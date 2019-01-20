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

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/math/scalars/include.hpp"
#include "primordialmachine/math/vectors/vector_n.hpp"

namespace primordialmachine {

template<typename V, typename S>
struct binary_star_functor<V, S, enable_if_t<is_vector_v<V> && is_scalar_v<S>>>
  : public default_elementwise_binary_star_functor<V, S>
{}; // struct binary_star_functor

template<typename V, typename S>
struct star_assignment_functor<V,
                               S,
                               enable_if_t<is_vector_v<V> && is_scalar_v<S> &&
                                           is_same_v<element_type_t<V>, S>>>
  : public default_elementwise_star_assignment_functor<V, S>
{}; // struct star_assignment_functor

template<typename S, typename V>
struct binary_star_functor<S, V, enable_if_t<is_scalar_v<S> && is_vector_v<V>>>
{
  using functor =
    elementwise_binary_functor<scalar_generator_functor<S>,
                               V,
                               V,
                               number_of_elements_v<V>,
                               binary_star_functor<S, element_type_t<V>>,
                               void>;
  using left_operand_type = S;
  using right_operand_type = V;
  using result_type = typename functor::result_type;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    return functor()(scalar_generator_functor<S>(left_operand), right_operand);
  }
};

} // namespace primordialmachine
