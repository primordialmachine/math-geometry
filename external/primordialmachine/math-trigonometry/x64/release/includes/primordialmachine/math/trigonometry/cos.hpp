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

#include "primordialmachine/functors/include.hpp"
#include "primordialmachine/trigonometric_functors/include.hpp"
#include <cmath>

namespace primordialmachine {

template<typename T>
struct cos_functor<T, enable_if_t<is_floating_point_v<T>>>
{
  T operator()(T v) const noexcept(noexcept(std::cos(v)))
  {
    return std::cos(v);
  }
}; // struct cos_functor

} // namespace primordialmachine
