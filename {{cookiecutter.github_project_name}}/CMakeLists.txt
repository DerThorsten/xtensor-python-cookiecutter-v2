cmake_minimum_required(VERSION 3.1)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

SET(PROJECT_NAME "{{ cookiecutter.cmake_project_name }}")
project({{ cookiecutter.cmake_project_name }})


# set (XTENSOR_SANDBOX_VERSION_MAJOR 0 )
# set (XTENSOR_SANDBOX_VERSION_MINOR 1 )
# set (XTENSOR_SANDBOX_VERSION_PATCH 0 )


# set (XTENSOR_SANDBOX_VERSION_SHORT_STR "${XTENSOR_SANDBOX_VERSION_MAJOR}.${XTENSOR_SANDBOX_VERSION_MINOR}")
# set (XTENSOR_SANDBOX_VERSION_STR "${XTENSOR_SANDBOX_VERSION_MAJOR}.${XTENSOR_SANDBOX_VERSION_MINOR}.${XTENSOR_SANDBOX_VERSION_PATCH}")


include(CheckCXXCompilerFlag)


#option(BUILD_TESTS     ON)
#option(BUILD_PYTHON    ON)


SET(BUILD_TESTS  ON CACHE BOOL "BUILD_TESTS Option"  FORCE)
SET(BUILD_PYTHON ON CACHE BOOL "BUILD_PYTHON Option" FORCE)

#-------------------------------------------------------------------------------------------------------------------
# cmake packages
#-------------------------------------------------------------------------------------------------------------------
include(ExternalProject)

#-------------------------------------------------------------------------------------------------------------------
# check for c++ 14 support
#-------------------------------------------------------------------------------------------------------------------

# FIXME c++14 checks are broken???
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    CHECK_CXX_COMPILER_FLAG("-std=c++14" HAS_CPP14_FLAG)
    #CHECK_CXX_COMPILER_FLAG("-std=c++11" HAS_CPP11_FLAG)
    if (HAS_CPP14_FLAG)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    else()
        message(FATAL_ERROR "Unsupported compiler -- multi-array  requires C++14 support!")
    endif()
endif()


if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

#-------------------------------------------------------------------------------------------------------------------
# threading package
#-------------------------------------------------------------------------------------------------------------------
find_package(Threads REQUIRED)

#-------------------------------------------------------------------------------------------------------------------
# include include files
#-------------------------------------------------------------------------------------------------------------------
file(GLOB_RECURSE headers include/*.hxx)
include_directories(include)


#-------------------------------------------------------------------------------------------------------------------
# external projects which need to be in the `include tree`
#-------------------------------------------------------------------------------------------------------------------

#---------------------------------------------------
# GSL: Guideline Support Library  
#---------------------------------------------------
ExternalProject_Add(
    external_gsl
    PREFIX ${CMAKE_BINARY_DIR}/external_projects/GSL
    GIT_REPOSITORY https://github.com/Microsoft/GSL
    GIT_TAG master
    TIMEOUT 5
    #UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)
# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(external_gsl source_dir)
set(GSL_INCLUDE_DIR ${source_dir}/include/ CACHE INTERNAL "Path to include folder for GSL")
include_directories(${GSL_INCLUDE_DIR})

#---------------------------------------------------
# xtensor 
#---------------------------------------------------
ExternalProject_Add(
    external_xtensor
    PREFIX ${CMAKE_BINARY_DIR}/external_projects/xtensor
    GIT_REPOSITORY https://github.com/QuantStack/xtensor
    GIT_TAG 0.10.7
    TIMEOUT 5
    #UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)
# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(external_xtensor source_dir)
set(XTENSOR_INCLUDE_DIR ${source_dir}/include/ CACHE INTERNAL "Path to include folder for xtensor")
include_directories(${XTENSOR_INCLUDE_DIR})


# meta target for all to handle dependencies
add_custom_target(externl_headers)
add_dependencies(externl_headers
    external_gsl 
    external_xtensor
)







#-------------------------------------------------------------------------------------------------------------------
# enable `make test` in root dir
#-------------------------------------------------------------------------------------------------------------------
if(BUILD_TESTS)
    enable_testing()
endif()

#------------------------------------------------------------------------------------------------------------------
# src folder
#-------------------------------------------------------------------------------------------------------------------
add_subdirectory(src)

