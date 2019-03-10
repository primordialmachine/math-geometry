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

#include "primordialmachine/math/colors/clamp.hpp"
#include "primordialmachine/math/colors/color.hpp"

namespace primordialmachine {

#pragma push_macro("STRUCT_CONDITION")
#define STRUCT_CONDITION()                                                     \
  is_floating_point_v<COMPONENT>&&                                             \
    is_same_v<COMPONENT_ARITHMETIC, component_arithmetic_saturated>&&          \
      is_color_space_v<COLOR_SPACE>&& is_same_v<COLOR_SPACE, color_space_rgb>

// Case of
// - an RGB color space
// - saturated component arithmetic
// - floating point components
template<typename COMPONENT,
         typename COMPONENT_ARITHMETIC,
         typename COLOR_SPACE>
struct color<COMPONENT,
             COMPONENT_ARITHMETIC,
             COLOR_SPACE,
             enable_if_t<STRUCT_CONDITION()>>
{
public:
  using component_type = COMPONENT;
  using component_arithmetic_type = COMPONENT_ARITHMETIC;
  using color_space_type = COLOR_SPACE;
  static constexpr component_type least = zero<component_type>();
  static constexpr component_type greatest = one<component_type>();

private:
  using this_type = color<COMPONENT, COMPONENT_ARITHMETIC, COLOR_SPACE>;
  component_type m_data[number_of_components_v<COLOR_SPACE>];

public:
  color() noexcept
    : m_data{}
  {}

  color(const component_type& r,
        const component_type& g,
        const component_type& b) noexcept
    : m_data{ clamp(r, least, greatest),
              clamp(g, least, greatest),
              clamp(b, least, greatest) }
  {}

  constexpr const component_type& r() const noexcept { return m_data[0]; }
  constexpr component_type& r() noexcept { return m_data[0]; }

  constexpr const component_type& g() const noexcept { return m_data[1]; }
  constexpr component_type& g() noexcept { return m_data[1]; }

  constexpr const component_type& b() const noexcept { return m_data[2]; }
  constexpr component_type& b() noexcept { return m_data[2]; }

  constexpr const component_type& operator()(size_t i) const
  {
    static_assert(i < number_of_components_v<color_space_type>,
                  "index out of bounds");
    return m_data[i];
  }

  constexpr component_type& operator()(size_t i)
  {
    static_assert(i < number_of_components_v<color_space_type>,
                  "index out of bounds");
    return m_data[i];
  }

  static this_type binary_plus(const this_type& a, const this_type& b)
  {
    static const auto f = [](const component_type& a, const component_type& b) {
      return clamp_greatest(a + b, greatest);
    };
    return this_type{ f(a.m_data[0], b.m_data[0]),
                      f(a.m_data[1], b.m_data[1]),
                      f(a.m_data[2], b.m_data[2]) };
  }

  static this_type& plus_assignment(this_type& a, const this_type& b)
  {
    static const auto f = [](const component_type& a, const component_type& b) {
      return clamp_greatest(a + b, greatest);
    };
    a.m_data[0] = f(a.m_data[0], b.m_data[0]);
    a.m_data[1] = f(a.m_data[1], b.m_data[1]);
    a.m_data[2] = f(a.m_data[2], b.m_data[2]);
    return a;
  }

  static this_type binary_minus(const this_type& a, const this_type& b)
  {
    static const auto f = [](const component_type& a, const component_type& b) {
      return clamp_least(a - b, least);
    };
    return this_type{ f(a.m_data[0], b.m_data[0]),
                      f(a.m_data[1], b.m_data[1]),
                      f(a.m_data[2], b.m_data[2]) };
  }

  static this_type& minus_assignment(this_type& a, const this_type& b)
  {
    static const auto f = [](const component_type& a, const component_type& b) {
      return clamp_least(a - b, least);
    };
    a.m_data[0] = f(a.m_data[0], b.m_data[0]);
    a.m_data[1] = f(a.m_data[1], b.m_data[1]);
    a.m_data[2] = f(a.m_data[2], b.m_data[2]), return a;
  }

  static this_type binary_star(const component_type& a, const this_type& b)
  {
    return binary_star(b, a);
  }

  static this_type binary_star(const this_type& a, const component_type& b)
  {
    static const auto f = [](const component_type& a, const component_type& b) {
      return clamp(a * b, least, greatest);
    };
    return this_type{ f(a.m_data[0], b), f(a.m_data[1], b), f(a.m_data[2], b) };
  }

  static bool equal_to(const this_type& a, const this_type& b)
  {
    if (&a == &b)
      return true; // Simply avoid component-wise comparison.
                   // Maybe improves performance.
                   // Certainly improves precision.
    return a.m_data[0] == b.m_data[0] && a.m_data[1] == b.m_data[1] &&
           a.m_data[2] == b.m_data[2];
  }

  static bool not_equal_to(const this_type& a, const this_type& b)
  {
    return !equal_to(a, b);
  }

}; // struct color

template<typename COMPONENT,
         typename COMPONENT_ARITHMETIC,
         typename COLOR_SPACE>
struct is_color<color<COMPONENT, COMPONENT_ARITHMETIC, COLOR_SPACE>,
                enable_if_t<STRUCT_CONDITION()>> : public true_type
{}; // struct is_color

#undef STRUCT_CONDITION
#pragma pop_macro("STRUCT_CONDITION")

} // namespace primordialmachine
