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

namespace primordialmachine {

template<typename LEFT_OPERAND,
         typename RIGHT_OPERAND,
         typename EQUAL_TO_FUNCTOR,
         typename ENABLED = void>
struct are_orthogonal_functor;

template<typename LEFT_OPERAND, typename RIGHT_OPERAND, typename EQUAL_TO_FUNCTOR>
auto
are_orthogonal(const LEFT_OPERAND& u, const RIGHT_OPERAND& v, EQUAL_TO_FUNCTOR equal_to_functor)
  -> decltype(are_orthogonal_functor<LEFT_OPERAND, RIGHT_OPERAND, EQUAL_TO_FUNCTOR>()(u, v, equal_to_functor))
{
  return are_orthogonal_functor<LEFT_OPERAND, RIGHT_OPERAND, EQUAL_TO_FUNCTOR>()(u, v, equal_to_functor);
}

} // namespace primordialmachine
