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

#include "primordialmachine/math/vectors/are_orthogonal.hpp"
#include "primordialmachine/math/vectors/dot_product_vector_vector.hpp"
#include "primordialmachine/one_zero_functors/include.hpp"
#include <type_traits>

namespace primordialmachine {

template<typename LEFT_OPERAND,
         typename RIGHT_OPERAND,
         typename EQUAL_TO_FUNCTOR>
struct are_orthogonal_functor<
  LEFT_OPERAND,
  RIGHT_OPERAND,
  EQUAL_TO_FUNCTOR,
  enable_if_t<is_floating_point_v<element_type_t<LEFT_OPERAND>> &&
              is_floating_point_v<element_type_t<RIGHT_OPERAND>>>>
{
  using left_operand_type = LEFT_OPERAND;
  using right_operand_type = RIGHT_OPERAND;
  using equal_to_functor_type = EQUAL_TO_FUNCTOR;
  auto operator()(const left_operand_type& u,
                  const right_operand_type& v,
                  equal_to_functor_type equal_to_functor)
  {
    // EQUAL_TO_FUNCTOR can be a relation of d == 0 e.g. abs(d) < 0.001f.
    const auto d = dot_product(u, v);
    return equal_to_functor(zero_functor<std::remove_cv_t<decltype(d)>>()(), d);
  }
}; // struct are_orthogonal_functor

} // namespace primordialmachine
