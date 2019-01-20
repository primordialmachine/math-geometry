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

#include "primordialmachine/math/points/include.hpp"
#include "primordialmachine/math/trigonometry/include.hpp"
#include "primordialmachine/math/vectors/include.hpp"

namespace primordialmachine {

// TODO: Move into "math-vectors".
template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
struct zero_functor<vector<vector_traits<ELEMENT, NUMBER_OF_ELEMENTS>>>
{
  using vector_type = vector<vector_traits<ELEMENT, NUMBER_OF_ELEMENTS>>;
  auto operator()() const noexcept(noexcept(vector_type()))
    -> decltype(vector_type())
  {
    return vector_type();
  }
}; // struct zero_functor

// TODO: Move into "math-points".
template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
struct zero_functor<point<point_traits<ELEMENT, NUMBER_OF_ELEMENTS>>>
{
  using point_type = point<point_traits<ELEMENT, NUMBER_OF_ELEMENTS>>;
  auto operator()() const noexcept(noexcept(point_type()))
    -> decltype(point_type())
  {
    return point_type();
  }
}; // struct zero_functor

template<typename ELEMENT>
struct circle
{
public:
  using scalar_type = ELEMENT;
  using point_type = point<point_traits<scalar_type, 2>>;
  using vector_type = vector<vector_traits<scalar_type, 2>>;
  template<typename _ELEMENT = ELEMENT>
  static constexpr enable_if_t<is_same_v<_ELEMENT, float>, float> TWO()
  {
    return 2.0F;
  }
  template<typename _ELEMENT = ELEMENT>
  static constexpr enable_if_t<is_same_v<_ELEMENT, double>, double> TWO()
  {
    return 2.0;
  }
  template<typename _ELEMENT = ELEMENT>
  static constexpr enable_if_t<is_same_v<_ELEMENT, long double>,
                               long double>
  TWO()
  {
    return 2.0L;
  }

private:
  point_type m_center;
  scalar_type m_radius;

public:
  /// @remark \f$r = 1\f$, \f$C = \vec{0}\f$.
  circle();

  ///
  circle(const point_type& center, const scalar_type& radius);
  ///
  point_type eval(scalar_type t) const;
}; // struct circle

template<typename ELEMENT>
circle<ELEMENT>::circle()
  : circle(zero<point_type>(), one<scalar_type>())
{}

template<typename ELEMENT>
circle<ELEMENT>::circle(const point_type& center, const scalar_type& radius)
  : m_center(center)
  , m_radius(radius)
{}

template<typename ELEMENT>
typename circle<ELEMENT>::point_type
circle<ELEMENT>::eval(scalar_type t) const
{
  // The constants for \f$0\f$ and \$f1\f$.
  static const auto ONE = one<scalar_type>()(), ZERO = zero<scalar_type>()();
  // The constants \f$2\pi\f$.
  static const auto TWO_PI =
    angle<scalar_type, angle_unit_radians>(TWO * pi<scalar_type>());
  return point_type(r * cos(TWO_PI * t), r * sin(TWO_PI * t));
}

} // namespace primordialmachine
