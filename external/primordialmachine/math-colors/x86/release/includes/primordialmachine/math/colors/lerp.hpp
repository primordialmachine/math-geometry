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

namespace primordialmachine {

template<typename A, typename B, typename C>
struct lerp_functor;

template<typename A, typename B, typename T>
auto
lerp(const A& a,
     const B& b,
     const T& t) noexcept(noexcept(lerp_functor<A, B, T>()(a, b, t)))
  -> decltype(lerp_functor<A, B, T>()(a, b, t))
{
  return lerp_functor<A, B, T>()(a, b, t);
}

} // namespace primordialmachine
