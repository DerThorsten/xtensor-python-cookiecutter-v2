![cookicutter-logo](./cookiecutter.png)



#### A [cookiecutter](https://github.com/audreyr/cookiecutter) template for creating a c++ packages with custom Python extension with xtensor

## What is xtensor-python-cookiecutter-v2?

THIS IS THIS WORK IN PROGRESS

`xtensor-python-cookiecutter` helps extension authors create a c++ package and  Python extension modules making use of xtensor.

It takes care of the initial work of generating a project skeleton with

- A complete `setup.py` compiling the extension module
- Automatic download of cpp dependencies:
    - xtensor
    - doctest
    - pybind11
    - xtensor-python

## Usage

Install [cookiecutter](https://github.com/audreyr/cookiecutter):

    $ pip install cookiecutter

After installing cookiecutter, use the xtensor-python-cookiecutter-v2:

    $ cookiecutter https://github.com/DerThorsten/xtensor-python-cookiecutter-v2.git

TODO