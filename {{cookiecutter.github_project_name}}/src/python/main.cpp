#include "pybind11/pybind11.h"

#include "xtensor/xmath.hpp"
#include "xtensor/xarray.hpp"

#define FORCE_IMPORT_ARRAY
#include "xtensor-python/pyarray.hpp"
#include "xtensor-python/pyvectorize.hpp"

#include <iostream>
#include <numeric>


// our headers
#include "{{ cookiecutter.cpp_root_folder_name }}/{{ cookiecutter.package_name }}.hpp"

namespace py = pybind11;



namespace {{ cookiecutter.cpp_namespace }} {

    void def_examples(py::module & module){

        // lambda to have pyarray as input
        module.def("example1", 
            [](xt::pyarray<double> &m){
                return example1(m);
            }, 
            "Return the first element of an array, of dimension at least one"
        );

        //lambda to have pyarray as in an output(!)
        module.def("example2", [](xt::pyarray<double> &m) -> xt::pyarray<double> {
            return example2(m);
        },  
        "Return the the specified array plus 2");

        // lambda to have pyarray as input
        module.def("readme_example1", [](xt::pyarray<double> &m) {
            return readme_example1(m);
        }, 
        "Accumulate the sines of all the values of the specified array");


        module.def("vectorize_example1", xt::pyvectorize(scalar_func), 
            "Add the sine and and cosine of the two specified values");
    }

}


// Python Module and Docstrings
PYBIND11_PLUGIN({{ cookiecutter.python_package_name }})
{
    xt::import_numpy();

    py::module module("{{ cookiecutter.python_package_name }}", R"docu(
        {{ cookiecutter.project_short_description }}

        .. currentmodule:: {{ cookiecutter.python_package_name }}

        .. autosummary::
           :toctree: _generate

           example1
           example2
           readme_example1
           vectorize_example1
    )docu");

    {{ cookiecutter.cpp_namespace }}::def_examples(module);

    return module.ptr();
}
