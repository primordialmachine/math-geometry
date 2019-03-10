///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Colors Library
// Copyright (c) 2019 Michael Heilmann
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
struct clamp_functor;

template<typename T>
struct clamp_functor<T, enable_if_t<is_floating_point_v<T>>>
{
  T operator()(const T& value, const T& least, const T& greatest) const
  {
    if (value < least)
      return least;
    else if (value > greatest)
      return greatest;
    return value;
  }
}; // struct clamp_functor

template<typename T>
auto
clamp(const T& value, const T& least, const T& greatest) noexcept(
  noexcept(clamp_functor<T>()(value, least, greatest)))
  -> decltype(clamp_functor<T>()(value, least, greatest))
{
  return clamp_functor<T>()(value, least, greatest);
}

} // namespace primordialmachine

namespace primordialmachine {

template<typename T, typename E = void>
struct clamp_greatest_functor;

template<typename T>
struct clamp_greatest_functor<T, enable_if_t<is_floating_point_v<T>>>
{
  const T& operator()(const T& value, const T& greatest) const
  {
    return value > greatest ? greatest : value;
  }
}; // struct clamp_greatest_functor

template<typename T>
auto
clamp_greatest(const T& value, const T& greatest) noexcept(
  noexcept(clamp_greatest_functor<T>()(value, greatest)))
  -> decltype(clamp_greatest_functor<T>()(value, greatest))
{
  return clamp_greatest_functor<T>()(value, greatest);
}

} // namespace primordialmachine

namespace primordialmachine {

template<typename T, typename E = void>
struct clamp_least_functor;

template<typename T>
struct clamp_least_functor<T, enable_if_t<is_floating_point_v<T>>>
{
  const T& operator()(const T& value, const T& least) const
  {
    return value < least ? least : value;
  }
}; // struct clamp_least_functor

template<typename T, typename E = void>
auto
clamp_least(const T& value,
            const T& least) noexcept(noexcept(clamp_least_functor<T>()(value,
                                                                       least)))
  -> decltype(clamp_least_functor<T>()(value, least))
{
  return clamp_least_functor<T>()(value, least);
}

} // namespace primordialmachine
