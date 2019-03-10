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

template<typename VECTOR, typename ENABLED = void>
struct unit_vector_functor;

template<typename VECTOR>
struct unit_vector_functor<VECTOR, enable_if_t<is_vector_v<VECTOR>>>
{
  static constexpr const size_t number_of_elements = number_of_elements_v<VECTOR>;
  using scalar_type = element_type_t<VECTOR>;
  using vector_type = VECTOR;
  auto operator()(size_t i) const
    noexcept(noexcept(impl(i, make_index_sequence<number_of_elements>{})))
  {
    return impl(i, make_index_sequence<number_of_elements>{});
  }

private:
  template<size_t... N>
  auto impl(size_t i, index_sequence<N...>) const
  {
    return vector_type((N == i ? one<scalar_type>() : zero<scalar_type>()) ...);
  }
}; // struct unit_vector_functor

} // namespace primordialmachine

namespace primordialmachine {

template<typename T, typename E = void>
struct two_functor;

template<typename T>
auto
two() noexcept(noexcept(two_functor<T>()())) -> decltype(two_functor<T>()())
{
  return two_functor<T>()();
}

template<>
struct two_functor<float, void>
{
  float operator()() const noexcept { return 2.0F; }
}; // struct two_functor

template<>
struct two_functor<double, void>
{
  double operator()() const noexcept { return 2.0; }
}; // struct two_functor

template<>
struct two_functor<long double, void>
{
  long double operator()() const noexcept { return 2.0L; }
}; // struct two_functor

} // namespace primordialmachine

namespace primordialmachine {

/* TODO: Move into "math-vectors". */
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

/* TODO: Move into "math-points". */
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

} // namespace primordialmachine
