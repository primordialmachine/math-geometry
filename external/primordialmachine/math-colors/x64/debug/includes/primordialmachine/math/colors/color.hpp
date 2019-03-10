#pragma once

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/functors/include.hpp"
#include "primordialmachine/one_zero_functors/include.hpp"
#include "primordialmachine/relational_functors/include.hpp"

namespace primordialmachine {

template<typename TYPE>
struct is_color_space : public false_type
{};

template<typename TYPE>
constexpr bool is_color_space_v = is_color_space<TYPE>::value;

template<typename TYPE, typename ENABLED = void>
struct number_of_components;

template<typename TYPE>
constexpr size_t number_of_components_v = number_of_components<TYPE>::value;

} // namespace primordialmachine

namespace primordialmachine {

/*TODO: Move into Primordial Machine's Functors library.*/
template<typename T, T v>
using integral_constant = std::integral_constant<T, v>;

// A color space with four components for red, green, blue, and alpha.
struct color_space_rgba
{};
template<>
struct is_color_space<color_space_rgba> : public true_type
{};
template<>
struct number_of_components<color_space_rgba, void>
  : public integral_constant<size_t, 4>
{};

// A color space with three components for red, green, and blue.
struct color_space_rgb
{};
template<>
struct is_color_space<color_space_rgb> : public true_type
{};
template<>
struct number_of_components<color_space_rgb, void>
  : public integral_constant<size_t, 3>
{};

// A color space with one component for luminance.
struct color_space_l
{};
template<>
struct is_color_space<color_space_l> : public true_type
{};
template<>
struct number_of_components<color_space_l, void>
  : public integral_constant<size_t, 1>
{};

// A color space with two components for luminance and alpha.
struct color_space_la
{};
template<>
struct is_color_space<color_space_la> : public true_type
{};
template<>
struct number_of_components<color_space_la, void>
  : public integral_constant<size_t, 2>
{};

// A color space with three components for hue, saturation, and value.
struct color_space_hsv
{};
template<>
struct is_color_space<color_space_hsv> : public true_type
{};
template<>
struct number_of_components<color_space_hsv, void>
  : public integral_constant<size_t, 3>
{};

// A color space with four components for hue, saturation, value, and alpha.
struct color_space_hsva
{};
template<>
struct is_color_space<color_space_hsva> : public true_type
{};
template<>
struct number_of_components<color_space_hsva, void>
  : public integral_constant<size_t, 4>
{};

// A color space with three components for hue, saturation, and luminance.
struct color_space_hsl
{};
template<>
struct is_color_space<color_space_hsl> : public true_type
{};
template<>
struct number_of_components<color_space_hsl, void>
  : public integral_constant<size_t, 3>
{};

// A color space with four components for hue, saturation, luminance, and alpha.
struct color_space_hsla
{};
template<>
struct is_color_space<color_space_hsla> : public true_type
{};
template<>
struct number_of_components<color_space_hsla, void>
  : public integral_constant<size_t, 4>
{};

} // namespace primordialmachine

namespace primordialmachine {

template<typename TYPE>
struct is_component_arithmetic : public false_type
{};

template<typename TYPE>
constexpr bool is_component_arithmetic_v = is_component_arithmetic<TYPE>::value;

} // namespace primordialmachine

namespace primordialmachine {

// Component arithmetic for saturated (aka clamped) arithmetic.
struct component_arithmetic_saturated
{};
template<>
struct is_component_arithmetic<component_arithmetic_saturated>
  : public true_type
{};

// Component arithmetic for clamped (aka saturated) aritmetic.
using component_arithmetic_clamped = component_arithmetic_saturated;

} // namespace primordialmachine

namespace primordialmachine {

template<typename COMPONENT,
         typename COMPONENT_ARITHMETIC,
         typename COLOR_SPACE,
         typename ENABLED = void>
struct color;

template<typename T, typename E = void>
struct is_color : public false_type
{};

template<typename T>
constexpr bool is_color_v = is_color<T>::value;

template<typename T>
struct binary_plus_functor<T, T, enable_if_t<is_color_v<T>>>
{
  auto operator()(const T& a, const T& b) const { return T::binary_plus(a, b); }
};

template<typename T>
struct binary_minus_functor<T, T, enable_if_t<is_color_v<T>>>
{
  auto operator()(const T& a, const T& b) const
  {
    return T::binary_minus(a, b);
  }
};

template<typename T>
struct equal_to_functor<T, T, enable_if_t<is_color_v<T>>>
{
  auto operator()(const T& a, const T& b) const { return T::equal_to(a, b); }
};

template<typename T>
struct not_equal_to_functor<T, T, enable_if_t<is_color_v<T>>>
{
  auto operator()(const T& a, const T& b) const
  {
    return T::not_equal_to(a, b);
  }
};

template<typename T>
struct plus_assignment_functor<T, T, enable_if_t<is_color_v<T>>>
{
  auto operator()(T& a, const T& b) const { return T::plus_assignment(a, b); }
};

template<typename T>
struct minus_assignment_functor<T, T, enable_if_t<is_color_v<T>>>
{
  auto operator()(T& a, const T& b) const { return T::minus_assignment(a, b); }
};

} // namespace primordialmachine
