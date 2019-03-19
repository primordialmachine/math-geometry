///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Geometry Library
// Copyright (C) 2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "primordialmachine/math/geometry/include.hpp"
#include "gtest/gtest.h"

using namespace primordialmachine;
static constexpr size_t
_number_of_elements()
{
  return 3;
}
using scalar_type = float;
using point_type = point<point_traits<scalar_type, _number_of_elements()>>;
using vector_type = vector<vector_traits<scalar_type, _number_of_elements()>>;

TEST(math_geometry_tests, axis_vector_test)
{
  primordialmachine::unit_vector_functor<vector_type> f;
  vector_type v;

  v = f(0);
  ASSERT_TRUE(vector_type(1.f, 0.f, 0.f) == v);

  v = f(1);
  ASSERT_TRUE(vector_type(0.f, 1.f, 0.f) == v);

  v = f(2);
  ASSERT_TRUE(vector_type(0.f, 0.f, 1.f) == v);
}

TEST(math_geometry_tests, line_constructor)
{
  using line_type = line<scalar_type, _number_of_elements()>;
  auto l = line_type();
  ASSERT_TRUE(point_type(-0.5f, 0.f, 0.f) == l.a());
  ASSERT_TRUE(point_type(+0.5f, 0.f, 0.f) == l.b());
}

TEST(math_geometry_tests, circle_constructor)
{
  using circle_type = circle<scalar_type>;
  auto c = circle_type();
}

TEST(math_geometry_tests, ray_constructor)
{
  using ray_type = ray<scalar_type, 3>;
  auto r = ray_type();
}

TEST(math_geometry_tests, sphere_constructor)
{
  using sphere_type = sphere<scalar_type, 3>;
  auto s = sphere_type();
}


TEST(math_geometry_tests, point_to_vector)
{
  auto p = point_type();
  auto v = primordialmachine::to<vector_type>(p);
  auto q = primordialmachine::to<point_type>(v);
}

TEST(math_geometry_tests, vector_to_point)
{
  auto v = vector_type();
  auto p = primordialmachine::to<point_type>(v);
  auto w = primordialmachine::to<vector_type>(p);
}

TEST(math_geometry_tests, make_point)
{
  using F = make_point<point_type>;
  auto f = F();
  auto p = F()([](size_t i) { return i == 0; },
               one_functor<float>(),
               zero_functor<float>());
}