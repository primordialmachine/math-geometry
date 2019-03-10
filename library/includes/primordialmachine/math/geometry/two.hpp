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

#include "primordialmachine/functors/include.hpp"

namespace primordialmachine {

template<typename T, typename E = void>
struct two_functor;

template<typename T>
auto
two() noexcept(noexcept(two_functor<T>()())) -> decltype(two_functor<T>()())
{
  return two_functor<T>()();
}

template<>
struct two_functor<float, void>
{
  float operator()() const noexcept { return 2.0F; }
}; // struct two_functor

template<>
struct two_functor<double, void>
{
  double operator()() const noexcept { return 2.0; }
}; // struct two_functor

template<>
struct two_functor<long double, void>
{
  long double operator()() const noexcept { return 2.0L; }
}; // struct two_functor

} // namespace primordialmachine