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

#include "primordialmachine/math/geometry/lerp.hpp"

namespace primordialmachine {

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
struct line
{
public:
  using point_type = point<point_traits<SCALAR, NUMBER_OF_ELEMENTS>>;
  using vector_type = vector<vector_traits<SCALAR, NUMBER_OF_ELEMENTS>>;

private:
  point_type m_a;
  point_type m_b;

public:
  line();

  line(const point_type& a, const point_type& b);

  const point_type& a() const;

  const point_type& b() const;

  point_type eval(SCALAR t) const;

}; // struct line

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
line<SCALAR, NUMBER_OF_ELEMENTS>::line()
  : m_a()
  , m_b()
{}

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
line<SCALAR, NUMBER_OF_ELEMENTS>::line(const point_type& a, const point_type& b)
  : m_a(a)
  , m_b(b)
{}

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
const typename line<SCALAR, NUMBER_OF_ELEMENTS>::point_type&
line<SCALAR, NUMBER_OF_ELEMENTS>::a() const
{
  return m_a;
}

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
const typename line<SCALAR, NUMBER_OF_ELEMENTS>::point_type&
line<SCALAR, NUMBER_OF_ELEMENTS>::b() const
{
  return m_b;
}

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
typename line<SCALAR, NUMBER_OF_ELEMENTS>::point_type
line<SCALAR, NUMBER_OF_ELEMENTS>::eval(SCALAR t) const
{
  return lerp(m_a, m_b, t);
}

} // namespace primordialmachine
