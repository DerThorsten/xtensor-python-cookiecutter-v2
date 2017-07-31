#pragma once
#ifndef {{ cookiecutter.cpp_macro_prefix }}_HPP
#define {{ cookiecutter.cpp_macro_prefix }}_HPP

#include "xtensor/xtensor.hpp"
#include "xtensor/xarray.hpp"
#include "xtensor/xexpression.hpp"

#include <cmath>
#include <numeric>

namespace {{ cookiecutter.cpp_namespace }} {

    template<class D>
    auto example1(const xt::xexpression<D> &m)
    {
        const auto & d = m.derived_cast();
        return d(0);
    }

    
    template<class D>
    inline auto example2(const xt::xexpression<D> &m)
    {
        const auto & d = m.derived_cast();
        return d + 2;
    }


    // Readme Examples
    template<class D>
    inline double readme_example1(const xt::xexpression<D> &m)
    {
        const auto & d = m.derived_cast();
        const auto sines = xt::sin(d);
        return std::accumulate(sines.begin(), sines.end(), 0.0);
    }

    // Vectorize Examples
    inline double scalar_func(const double i, const double j)
    {
        return std::sin(i) + std::cos(j);
    }
    



} // end namespace {{cookiecutter.cpp_namespace}}


#endif // #ifndef {{ cookiecutter.cpp_macro_prefix }}_HPP