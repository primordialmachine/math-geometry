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

#include "primordialmachine/math/vectors/euclidean_norm_functor.hpp"
#include "primordialmachine/math/vectors/vector_n.hpp"
#include <cmath>

namespace primordialmachine {

template<typename V>
struct euclidean_norm_functor<V, enable_if_t<is_vector_v<V>>>
{
  using operand_type = V;
  auto operator()(const operand_type& operand) const
  {
    return implementation(operand,
                          make_element_indices<V>{});
  }
  template<size_t... Is>
  auto implementation(const operand_type& operand,
                      index_sequence<Is...>) const
  {
    return square_root(((operand(Is) * operand(Is)) + ...));
  }
}; // struct euclidean_norm_functor

} // namespace primordialmachine
