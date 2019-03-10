///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Vectors Library
// Copyright (c) 2017-2019 Michael Heilmann
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

#include "primordialmachine/math/non_scalars/include.hpp"

namespace primordialmachine {

template<typename ELEMENT, size_t NUMBER_OF_ELEMENTS>
struct vector_traits
{
  using element_type = ELEMENT;
  static constexpr size_t number_of_elements = NUMBER_OF_ELEMENTS;
  static constexpr bool is_degenerate = 0 == NUMBER_OF_ELEMENTS;
  static constexpr bool is_non_degenerate = false == is_degenerate;
}; // struct vector_traits

template<typename TRAITS, typename ENABLED = void>
struct vector;

template<typename T, typename ENABLED = void>
struct is_vector : public false_type
{}; // struct is_vector

template<typename T>
inline constexpr bool is_vector_v = is_vector<T, void>::value;

template<typename T>
struct number_of_elements<T, enable_if_t<is_vector_v<T>>>
{
  static constexpr size_t value = T::traits_type::number_of_elements;
}; // struct number_of_elements

template<typename T>
struct element_type<T, enable_if_t<is_vector_v<T>>>
{
  using type = typename T::traits_type::element_type;
}; // struct element_type

template<typename T>
struct is_non_scalar<T, enable_if_t<is_vector_v<T>>> : public true_type
{}; // struct is_non_scalar

template<typename T>
struct is_non_degenerate<T, enable_if_t<is_vector_v<T>>>
{
  static constexpr bool value = T::traits_type::is_non_degenerate;
}; // struct is_non_degenerate

template<typename T>
struct is_degenerate<T, enable_if_t<is_vector_v<T>>>
{
  static constexpr bool value = T::traits_type::is_degenerate;
}; // struct is_degenerate

} // namespace primordialmachine
