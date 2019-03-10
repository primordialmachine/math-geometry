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

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/math/vectors/vector.hpp"
#include "primordialmachine/one_zero_functors/include.hpp"

namespace primordialmachine {

// SFINAE for the struct type.
#pragma push_macro("STRUCT_CONDITION")
#define STRUCT_CONDITION()                                                     \
  enable_if_t<(is_floating_point_v<typename TRAITS::element_type>)&&(          \
    TRAITS::number_of_elements > 1)>

// SFINAE for the constructor.
#pragma push_macro("CONSTRUCTOR_CONDITION_1")
#define CONSTRUCTOR_CONDITION_1(_NUMBER_OF_ARGUMENTS)                          \
  ((1 + sizeof...(ARGUMENTS)) == _NUMBER_OF_ARGUMENTS)

#pragma push_macro("CONSTRUCTOR_CONDITION_2")
#define CONSTRUCTOR_CONDITION_2()                                              \
  (std::is_convertible_v<                                                      \
    std::decay_t<ARGUMENT>,                                                    \
    typename TRAITS::element_type>)&&(... &&                                   \
                                      std::is_convertible_v<                   \
                                        std::decay_t<ARGUMENTS>,               \
                                        typename TRAITS::element_type>)

#pragma push_macro("CONSTRUCTOR_CONDITION")
#define CONSTRUCTOR_CONDITION()                                                \
  enable_if_t<CONSTRUCTOR_CONDITION_1(TRAITS::number_of_elements) &&           \
              CONSTRUCTOR_CONDITION_2()>

template<typename TRAITS>
struct is_vector<vector<TRAITS>, STRUCT_CONDITION()> : public true_type
{}; // struct is_vector

template<typename TRAITS>
struct vector<TRAITS, STRUCT_CONDITION()>
{
  using traits_type = TRAITS;
  using element_type = typename TRAITS::element_type; /*TODO: Remove this.*/
  static constexpr size_t number_of_elements =
    TRAITS::number_of_elements; /*TODO: Remove this.*/

  vector();

  template<typename ARGUMENT,
           typename... ARGUMENTS,
           typename ENABLED = CONSTRUCTOR_CONDITION()>
  vector(ARGUMENT&& argument, ARGUMENTS&&... arguments);

  template<size_t NUMBER_OF_ELEMENTS_ = TRAITS::number_of_elements>
  constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 1), element_type> const& x()
    const;
  template<size_t NUMBER_OF_ELEMENTS_ = TRAITS::number_of_elements>
  constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 1), element_type>& x();

  template<size_t NUMBER_OF_ELEMENTS_ = TRAITS::number_of_elements>
  constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 2), element_type> const& y()
    const;
  template<size_t NUMBER_OF_ELEMENTS_ = TRAITS::number_of_elements>
  constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 2), element_type>& y();

  template<size_t NUMBER_OF_ELEMENTS_ = TRAITS::number_of_elements>
  constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 3), element_type> const& z()
    const;
  template<size_t NUMBER_OF_ELEMENTS_ = TRAITS::number_of_elements>
  constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 3), element_type>& z();

  constexpr element_type const& operator()(size_t i) const;
  constexpr element_type& operator()(size_t i);

  constexpr element_type const* data() const;
  constexpr element_type* data();

private:
  element_type m_elements[number_of_elements];
};

#pragma push_macro("TYPE")
#define TYPE vector<TRAITS, STRUCT_CONDITION()>

template<typename TRAITS>
TYPE::vector()
  : m_elements{}
{
  std::fill_n(m_elements, number_of_elements, zero<element_type>());
}

template<typename TRAITS>
template<typename ARGUMENT, typename... ARGUMENTS, typename ENABLED>
TYPE::vector(ARGUMENT&& argument, ARGUMENTS&&... arguments)
  : m_elements{ static_cast<element_type>(argument),
                static_cast<element_type>(arguments)... }
{}

template<typename TRAITS>
template<size_t NUMBER_OF_ELEMENTS_>
constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 1),
                      typename TYPE::element_type> const&
TYPE::x() const
{
  return m_elements[0];
}

template<typename TRAITS>
template<size_t NUMBER_OF_ELEMENTS_>
constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 1), typename TYPE::element_type>&
TYPE::x()
{
  return m_elements[0];
}

template<typename TRAITS>
template<size_t NUMBER_OF_ELEMENTS_>
constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 2),
                      typename TYPE::element_type> const&
TYPE::y() const
{
  return m_elements[1];
}

template<typename TRAITS>
template<size_t NUMBER_OF_ELEMENTS_>
constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 2), typename TYPE::element_type>&
TYPE::y()
{
  return m_elements[1];
}

template<typename TRAITS>
template<size_t NUMBER_OF_ELEMENTS_>
constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 3),
                      typename TYPE::element_type> const&
TYPE::z() const
{
  return m_elements[2];
}

template<typename TRAITS>
template<size_t NUMBER_OF_ELEMENTS_>
constexpr enable_if_t<(NUMBER_OF_ELEMENTS_ >= 3), typename TYPE::element_type>&
TYPE::z()
{
  return m_elements[2];
}

template<typename TRAITS>
constexpr typename TYPE::element_type const&
TYPE::operator()(size_t i) const
{
  return m_elements[i];
}

template<typename TRAITS>
constexpr typename TYPE::element_type&
TYPE::operator()(size_t i)
{
  return m_elements[i];
}

template<typename TRAITS>
constexpr typename TRAITS::element_type const*
TYPE::data() const
{
  return m_elements;
}

template<typename TRAITS>
constexpr typename TRAITS::element_type*
TYPE::data()
{
  return m_elements;
}

#undef TYPE
#pragma pop_macro("TYPE")

#undef CONSTRUCTOR_CONDITION_2
#pragma pop_macro("CONSTRUCTOR_CONDITION_2")

#undef CONSTRUCTOR_CONDITION_1
#pragma pop_macro("CONSTRUCTOR_CONDITION_1")

#undef CONSTRUCTOR_CONDITION
#pragma pop_macro("CONSTRUCTOR_CONDITION")

#undef STRUCT_CONDITION
#pragma pop_macro("STRUCT_CONDITION")

} // namespace primordialmachine
