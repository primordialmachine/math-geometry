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

#include "primordialmachine/math/vectors/dot_product.hpp"
#include "primordialmachine/math/vectors/vector.hpp"
#include <type_traits>

namespace primordialmachine {

template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
struct dot_product_functor<
  LEFT_OPERAND,
  RIGHT_OPERAND,
  enable_if_t<is_vector_v<LEFT_OPERAND> && is_vector_v<RIGHT_OPERAND> &&
              number_of_elements_v<LEFT_OPERAND> ==
                number_of_elements_v<RIGHT_OPERAND>>>
{
  static constexpr auto number_of_elements = number_of_elements_v<LEFT_OPERAND>;
  using left_operand_type = LEFT_OPERAND;
  using right_operand_type = RIGHT_OPERAND;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    return implementation(
      left_operand, right_operand, make_index_sequence<number_of_elements>());
  }
  template<size_t... Is>
  auto implementation(const left_operand_type& left_operand,
                      const right_operand_type& right_operand,
                      index_sequence<Is...>) const
  {
    return ((left_operand(Is) * right_operand(Is)) + ...);
  }
}; // struct dot_product_functor

} // namespace primordialmachine
