///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Geometry Library
// Copyright (C) 2019 Michael Heilmann
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

#include "primordialmachine/one_zero_functors/include.hpp"

namespace primordialmachine {

template<typename V, typename T, typename E = void>
struct lerp_functor;

template<typename V, typename T>
auto lerp(const V& x, const V& y, const T& t)
  noexcept(noexcept(lerp_functor<V, T>()(x, y, t)))
  -> decltype(lerp_functor<V, T>()(x, y, t))
{ return lerp_functor<V, T>()(x, y, t); }

template<typename V, typename T>
struct lerp_functor<V, T, enable_if_t<is_floating_point_v<V> && is_floating_point_v<T>>>
{
    auto operator()(const V& x, const V& y, const T& t) const
    { return (one<V>() - t) * x + t * y; }
}; // struct lerp_functor
  
} // namespace primordialmachine
