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

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/math/trigonometry/angle.hpp"

namespace primordialmachine {

template<typename A, typename B>
struct star_assignment_functor<
  A,
  B,
  enable_if_t<
    conjunction_v<is_angle<A>,
                  is_scalar<B>,
                  is_same<underlying_type_t<A>, B>>>>
{
  using left_operand_type = A;
  using right_operand_type = B;
  using result_type = A;
  result_type& operator()(left_operand_type& left_operand,
                          const right_operand_type& right_operand) const
    noexcept(noexcept(left_operand.value(left_operand.value() *
                                         right_operand)))
  {
    left_operand.value(left_operand.value() * right_operand);
    return left_operand;
  }
}; // struct star_assignment_functor

} // namespace primordialmachine
