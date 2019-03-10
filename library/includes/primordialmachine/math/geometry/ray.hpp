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

#include "primordialmachine/math/geometry/common.hpp"

namespace primordialmachine {

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS, typename ENABLED = void>
struct ray;

#pragma push_macro("ENABLE_STRUCT_IF")
#define ENABLE_STRUCT_IF() enable_if_t<(NUMBER_OF_ELEMENTS >= 2)>

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
struct ray<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>
{
  using scalar_type = SCALAR;

  using point_type = point<point_traits<scalar_type, NUMBER_OF_ELEMENTS>>;

  using vector_type = vector<vector_traits<scalar_type, NUMBER_OF_ELEMENTS>>;

  // TODO: \f$p = \left(0,0,\ldots\right)\f$, \f$b =
  // \left(0,0,1,0,\ldots\right)\f$.
  ray();

  ray(const point_type& p, const vector_type& d);

private:
  point_type m_p;
  vector_type m_d;

}; // struct ray

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
ray<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::ray()
  : m_p()
  , m_d()
{}

template<typename SCALAR, size_t NUMBER_OF_ELEMENTS>
ray<SCALAR, NUMBER_OF_ELEMENTS, ENABLE_STRUCT_IF()>::ray(const point_type& p,
                                                         const vector_type& d)
  : m_p(p)
  , m_d(normalize(d))
{}

#undef ENABLE_STRUCT_IF
#pragma pop_macro("ENABLE_STRUCT_IF")

} // namespace primordialmachine
