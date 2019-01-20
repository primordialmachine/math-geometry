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

#include "primordialmachine/math/scalars/include.hpp"
#include "primordialmachine/math/trigonometry/cos.hpp"
#include "primordialmachine/math/trigonometry/cot.hpp"
#include "primordialmachine/math/trigonometry/sin.hpp"
#include "primordialmachine/math/trigonometry/tan.hpp"

namespace primordialmachine {

// TODO: Move into functors library.
template<class... B>
inline constexpr bool conjunction_v = std::conjunction<B...>::value;

} // namespace primordialmachine

namespace primordialmachine {

template<typename T, typename E = void>
struct is_angle
{
  static constexpr bool value = false;
}; // struct is_angle

template<typename T>
constexpr bool is_angle_v = is_angle<T>::value;

} // namespace primordialmachine

namespace primordialmachine {

template<typename T, typename E = void>
struct underlying_type;

template<typename T>
struct underlying_type<T, enable_if_t<is_angle_v<T>>>
{
  using type = typename T::underlying_type;
}; // struct underlying_type

template<typename T>
using underlying_type_t = typename underlying_type<T>::type;

} // namespace primordialmachine

namespace primordialmachine {

template<typename T, typename E = void>
struct unit_type;

template<typename T>
struct unit_type<T, enable_if_t<is_angle_v<T>>>
{
  using type = typename T::unit_type;
}; // struct unit_type

template<typename T>
using unit_type_t = typename unit_type<T>::type;

} // namespace primordialmachine

namespace primordialmachine {

/// @tparam UNIT An AngleUnit type denoting the unit in which the angles are
/// measured.
/// @tparam UNDERLYING_TYPE The underlying type representing the angle values.
/// @tparam ENABLED For SFINAE.
template<typename UNIT, typename TYPE, typename ENABLED = void>
struct angle;

} // namespace primordialmachine

namespace primordialmachine {

template<typename UNIT, typename UNDERLYING_TYPE>
struct cos_functor<angle<UNIT, UNDERLYING_TYPE>, void>
{
  auto operator()(const angle<UNIT, UNDERLYING_TYPE>& a) const
    noexcept(noexcept(cos(a.to_radians().value())))
  {
    return cos(a.to_radians().value());
  }
}; // struct cos_functor

} // namespace primordialmachine

namespace primordialmachine {

template<typename UNIT, typename UNDERLYING_TYPE>
struct cot_functor<angle<UNIT, UNDERLYING_TYPE>, void>
{
  auto operator()(const angle<UNIT, UNDERLYING_TYPE>& a) const
    noexcept(noexcept(cot(a.to_radians().value())))
  {
    return cot(a.to_radians().value());
  }
}; // struct cot_functor

} // namespace primordialmachine

namespace primordialmachine {

template<typename UNIT, typename UNDERLYING_TYPE>
struct sin_functor<angle<UNIT, UNDERLYING_TYPE>, void>
{
  auto operator()(const angle<UNIT, UNDERLYING_TYPE>& a) const
    noexcept(noexcept(sin(a.to_radians().value())))
  {
    return sin(a.to_radians().value());
  }
}; // struct sin_functor

} // namespace primordialmachine

namespace primordialmachine {

template<typename UNIT, typename UNDERLYING_TYPE>
struct tan_functor<angle<UNIT, UNDERLYING_TYPE>, void>
{
  auto operator()(const angle<UNIT, UNDERLYING_TYPE>& a) const
    noexcept(noexcept(tan(a.to_radians().value())))
  {
    return tan(a.to_radians().value());
  }
}; // struct tan_functor

} // namespace primordialmachine
