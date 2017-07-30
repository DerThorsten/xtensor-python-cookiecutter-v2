
#-------------------------------------------------------------------------------------------------------------------
# Setup python bindings
#-------------------------------------------------------------------------------------------------------------------

#------------------------------------
# download pybind11
#-----------------------------------
ExternalProject_Add(
    external_pybind11
    PREFIX ${CMAKE_BINARY_DIR}/external_projects/pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11
    GIT_TAG "v2.1.1"
    TIMEOUT 10
    #UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)

# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(external_pybind11 source_dir)
set(PYBIND11_DIR ${source_dir} CACHE INTERNAL "Path to folder for pybin11")
set(PYBIND11_INCLUDE_DIR ${source_dir}/include CACHE INTERNAL "Path to include folder for pybin11")
MESSAGE(STATUS PYBIND11_INCLUDE_DIR ${PYBIND11_INCLUDE_DIR})
include_directories(${PYBIND11_INCLUDE_DIR})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools")
include(pybind11Tools)

# numpy
set(PYBIND11_CPP_STANDARD -std=c++14)
find_package(NumPy REQUIRED)
include_directories(${NUMPY_INCLUDE_DIRS})

#------------------------------------
# download xtensor-python
#-----------------------------------
ExternalProject_Add(
    external_xtensor_python
    PREFIX ${CMAKE_BINARY_DIR}/external_projects/xtensor-python
    GIT_REPOSITORY https://github.com/QuantStack/xtensor-python
    GIT_TAG "0.12.1"
    TIMEOUT 10
    #UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)

# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(external_xtensor_python source_dir)
set(XTENSOR_PYTHON_INCLUDE_DIR ${source_dir}/include CACHE INTERNAL "Path to include folder for xtensor-python")
MESSAGE(STATUS XTENSOR_PYTHON_INCLUDE_DIR " : " ${XTENSOR_PYTHON_INCLUDE_DIR})
include_directories(${XTENSOR_PYTHON_INCLUDE_DIR})


# meta target for all to handle dependencies
# mostly external headers 
add_custom_target(externl_headers_python)
add_dependencies(externl_headers_python
    externl_headers 
    external_pybind11
    external_xtensor_python
)


#-------------------------------------------------------------------------------------------------------------------
# Add The module
#-------------------------------------------------------------------------------------------------------------------
pybind11_add_module({{ cookiecutter.python_package_name }} main.cpp)

# dependencies (make sure all external headers are downloaded)
add_dependencies({{ cookiecutter.python_package_name }}
    externl_headers_python
)


