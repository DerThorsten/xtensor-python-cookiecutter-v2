![cookicutter-logo](./cookiecutter.png)



[![Build Status](https://travis-ci.org/DerThorsten/xtensor-python-cookiecutter-v2.svg?branch=master)](https://travis-ci.org/DerThorsten/xtensor-python-cookiecutter-v2)
[![Build status](https://ci.appveyor.com/api/projects/status/hqaaw6wpwr86yv5v/branch/master?svg=true)](https://ci.appveyor.com/project/DerThorsten/xtensor-python-cookiecutter-v2/branch/master)




#### A [cookiecutter](https://github.com/audreyr/cookiecutter) template for creating a C++ packages with custom Python extension with xtensor

## What is xtensor-python-cookiecutter-v2?

THIS IS THIS WORK IN PROGRESS

`xtensor-python-cookiecutter-v2` helps extension authors create a C++ package and  Python extension modules making use of xtensor.

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