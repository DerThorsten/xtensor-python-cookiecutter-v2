#include "doctest.h"

#include "xtensor/xtensor.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xarray.hpp"
#include "xtensor/xtensor.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xutils.hpp"
#include "xtensor/xbuilder.hpp"

TEST_SUITE_BEGIN("{{ cookiecutter.package_name }}");

TEST_CASE( "some test case" ) {


    //auto image_in  = xt::random::randn<double>({100, 100});
    auto image_in  = xt::ones<double>({100, 100});
    auto image_out = xt::xtensor<double, 2   >({100, 100});

    //xt::vigra::gaussian_smooth(image_in, image_out);

}


TEST_SUITE_END();