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

namespace primordialmachine {

template<typename T, typename E = void>
struct pi_functor;

template<typename T>
auto
pi() -> decltype(pi_functor<T, void>()())
{
  return pi_functor<T, void>()();
}

// TODO: Can we use more digits?
template<>
struct pi_functor<float, void>
{
  float operator()() const
  {
    return 3.141592653589793238462643383279502884197169399375105820974944592F;
  }
}; // struct pi_functor

// TODO: Can we use more digits?
template<>
struct pi_functor<double, void>
{
  double operator()() const
  {
    return 3.141592653589793238462643383279502884197169399375105820974944592;
  }
}; // struct pi_functor

// TODO: Can we use more digits?
template<>
struct pi_functor<long double, void>
{
  long double operator()() const
  {
    return 3.141592653589793238462643383279502884197169399375105820974944592L;
  }
}; // struct pi_functor

} // namespace primordialmachine
