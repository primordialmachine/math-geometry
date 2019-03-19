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

#pragma once

#include "primordialmachine/math/geometry/common.hpp"

namespace primordialmachine {

template<typename SCALAR>
struct circle
{
  using scalar_type = SCALAR;

  using point_type = point<point_traits<scalar_type, 2>>;

  using vector_type = vector<vector_traits<scalar_type, 2>>;

  /// @remark \f$r = 1\f$, \f$C = \vec{0}\f$.
  circle();

  ///
  circle(const point_type& c, const scalar_type& r);

  ///
  point_type eval(scalar_type t) const;

private:
  point_type m_c;

  scalar_type m_r;

}; // struct circle

template<typename ELEMENT>
circle<ELEMENT>::circle()
  : circle(zero<point_type>(), one<scalar_type>())
{}

template<typename ELEMENT>
circle<ELEMENT>::circle(const point_type& c, const scalar_type& r)
  : m_c(c)
  , m_r(r)
{}

template<typename ELEMENT>
typename circle<ELEMENT>::point_type
circle<ELEMENT>::eval(scalar_type t) const
{
  // The constants for \f$0\f$ and \$f1\f$.
  static const auto ONE = one<scalar_type>()(), ZERO = zero<scalar_type>()();
  // The constants \f$2\pi\f$.
  static const auto TWO_PI =
    angle<scalar_type, angle_unit_radians>(two<scalar_type>() * pi<scalar_type>());
  return point_type(m_r * cos(TWO_PI * t), m_r * sin(TWO_PI * t));
}

} // namespace primordialmachine
