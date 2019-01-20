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

TEST(math_geometry_tests, line_constructor)
{
  using line_type = line<scalar_type, _number_of_elements()>;
  auto l = line_type();
}

TEST(math_geometry_tests, circle_constructor)
{
  using circle_type = circle<scalar_type>;
  auto c = circle_type();
}
