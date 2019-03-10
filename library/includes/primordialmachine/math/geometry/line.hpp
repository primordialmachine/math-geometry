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

#include "primordialmachine/math/geometry/lerp.hpp"
#include "primordialmachine/math/geometry/to.hpp"

namespace primordialmachine {

template<typename P, typename ENABLED = void>
struct make_point;

template<typename P>
struct make_point<P, enable_if_t<is_point_v<P>>>
{
  template<typename C, typename F, typename G>
  auto operator()(C c, F f, G g) const
  {
    return implementation(
      c, f, g, make_index_sequence<number_of_elements_v<P>>{});
  }
  template<typename C, typename F, typename G, size_t... I>
  auto implementation(C c, F f, G g, index_sequence<I...>) const
  {
    auto x = [c, f, g](size_t i) { return c(i) ? f() : g(); };
    return P{ (x(I))... };
  }
};

} // namespace primordialmachine

namespace primordialmachine {

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS, typename ENABLED = void>
struct line;

#pragma push_macro("ENABLE_STRUCT_IF")
#define ENABLE_STRUCT_IF() enable_if_t<(NUMBER_OF_ELEMENTS >= 2)>

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
struct line<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>
{
  using scalar_type = SCALAR;

  using point_type = point<point_traits<scalar_type, NUMBER_OF_ELEMENTS>>;

  using vector_type = vector<vector_traits<scalar_type, NUMBER_OF_ELEMENTS>>;

  // \f$a = \left(0, 0, \ldots\right)\f$, \f$b = \left(0, 1, \ldots\right)\f$
  line();

  line(const point_type& a, const point_type& b);

  constexpr const point_type& a() const;

  constexpr const point_type& b() const;

  point_type eval(scalar_type t) const;

private:
  point_type m_a;

  point_type m_b;

}; // struct line

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
line<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::line()
  : m_a(to<point_type>(
      to<vector_type>(make_point<point_type>()([](size_t i) { return i == 0; },
                                               one_functor<SCALAR>(),
                                               zero_functor<SCALAR>())) /
      -two<SCALAR>()))
  , m_b(to<point_type>(
      to<vector_type>(make_point<point_type>()([](size_t i) { return i == 0; },
                                               one_functor<SCALAR>(),
                                               zero_functor<SCALAR>())) /
      +two<SCALAR>()))
{}

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
line<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::line(const point_type& a,
                                                           const point_type& b)
  : m_a(a)
  , m_b(b)
{}

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
constexpr const typename line<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::
  point_type&
  line<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::a() const
{
  return m_a;
}

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
constexpr const typename line<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::
  point_type&
  line<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::b() const
{
  return m_b;
}

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
typename line<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::point_type
line<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::eval(scalar_type t) const
{
  return lerp(m_a, m_b, t);
}

#undef ENABLE_STRUCT_IF
#pragma pop_macro("ENABLE_STRUCT_IF")

} // namespace primordialmachine
