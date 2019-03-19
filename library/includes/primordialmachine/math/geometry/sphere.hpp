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

template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS, typename ENABLED = void>
struct sphere;

#pragma push_macro("ENABLE_STRUCT_IF")
#define ENABLE_STRUCT_IF() enable_if_t<(NUMBER_OF_ELEMENTS >= 3)>

template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
struct sphere<ELEMENT, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>
{
  using scalar_type = ELEMENT;

  using point_type = point<point_traits<scalar_type, NUMBER_OF_ELEMENTS>>;

  using vector_type = vector<vector_traits<scalar_type, NUMBER_OF_ELEMENTS>>;

  /// @remark \f$r = 1\f$, \f$C = \vec{0}\f$.
  sphere();

  ///
  sphere(const point_type& c, const scalar_type& r);

  constexpr const point_type& c() const noexcept;
  constexpr point_type& c() noexcept;

  constexpr const scalar_type& r() const noexcept;
  constexpr scalar_type& r() noexcept;

private:
  point_type m_c;

  scalar_type m_r;

}; // struct sphere

template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
sphere<ELEMENT, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::sphere()
  : sphere<ELEMENT, NUMBER_OF_ELEMENTS>(zero<point_type>(), one<scalar_type>())
{}

template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
sphere<ELEMENT, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::sphere(
  const point_type& c,
  const scalar_type& r)
  : m_c(c)
  , m_r(r)
{}

template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
constexpr const typename sphere<ELEMENT, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::point_type&
sphere<ELEMENT, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::c() const noexcept
{
  return m_c;
}

template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
constexpr typename sphere<ELEMENT,
                                NUMBER_OF_ELEMENTS,
                                ENABLE_STRUCT_IF()>::point_type&
sphere<ELEMENT, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::c() noexcept
{
  return m_c;
}

template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
constexpr const typename sphere<ELEMENT,
                                NUMBER_OF_ELEMENTS,
                                ENABLE_STRUCT_IF()>::scalar_type&
sphere<ELEMENT, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::r() const noexcept
{
  return m_r;
}

template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
constexpr
  typename sphere<ELEMENT, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::scalar_type&
  sphere<ELEMENT, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::r() noexcept
{
  return m_r;
}

#undef ENABLE_STRUCT_IF
#pragma pop_macro("ENABLE_STRUCT_IF")

} // namespace primordialmachine
