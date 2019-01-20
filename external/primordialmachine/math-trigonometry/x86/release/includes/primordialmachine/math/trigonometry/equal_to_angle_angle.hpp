///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Trigonometry Library
// Copyright (C) 2017-2019 Michael Heilmann
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

#include "primordialmachine/math/trigonometry/angle.hpp"
#include "primordialmachine/relational_functors/include.hpp"

namespace primordialmachine {

template<typename A, typename B>
struct equal_to_functor<
  A,
  B,
  enable_if_t<is_angle_v<A> && is_angle_v<B> &&
              is_same_v<unit_type_t<A>, unit_type_t<B>> &&
              is_same_v<underlying_type_t<A>, underlying_type_t<B>>>>
{
  using left_operand_type = A;
  using right_operand_type = B;
  using result_type = bool;
  bool operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
    noexcept(noexcept(left_operand.value() == right_operand.value()))
  {
    return left_operand.value() == right_operand.value();
  }
}; // struct equal_to_functor

} // namespace primordialmachine
