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

template<typename A>
struct unary_plus_functor<A, enable_if_t<is_angle_v<A>>>
{
  using operand_type = A;
  using result_type = A;
  result_type operator()(const operand_type& operand) const
    noexcept(noexcept(result_type{ +operand.value() }))
  {
    return result_type{ +operand.value() };
  }
}; // struct unary_plus_functor

} // namespace primordialmachine