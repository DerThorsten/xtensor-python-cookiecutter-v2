The subfolder tools is taken from https://github.com/pybind/pybind11/
see tools/LICENSE


We would love to avoid this hard copy.
But we want to use *.cmake files from pybind11
within this projects ( {{ cookiecutter.project_name }}) .

But we use pybind11 via cmake external projects.
This somehow makes it impossible (???) 
to use the cmake files from pybind within this projects
cmake build system.

