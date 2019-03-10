#pragma once

#include "primordialmachine/math/points/include.hpp"
#include "primordialmachine/math/vectors/include.hpp"

namespace primordialmachine {

template<typename TARGET, typename SOURCE, typename ENABLED = void>
struct to_functor;

template<typename TARGET, typename SOURCE>
auto
to(const SOURCE& source) noexcept(
  noexcept(to_functor<TARGET, SOURCE>()(source)))
  -> decltype(to_functor<TARGET, SOURCE>()(source))
{
  return to_functor<TARGET, SOURCE>()(source);
}

// Vector to point conversion.
// TODO: The "as" functor (facade functor) is more efficient. Add "as"
// functor.
template<typename TARGET, typename SOURCE>
struct to_functor<TARGET,
                  SOURCE,
                  enable_if_t<is_point_v<TARGET> && is_vector_v<SOURCE>>>
{
  using target_type = TARGET;
  using source_type = SOURCE;

  using result_type = TARGET;
  using qualified_result_type = TARGET;

  qualified_result_type operator()(const source_type& source) const
  {
    return implementation(
      source, make_index_sequence<number_of_elements_v<source_type>>{});
  }

  template<size_t... I>
  qualified_result_type implementation(const source_type& source,
                                       index_sequence<I...>) const
  {
    return result_type{ source(I)... };
  }
}; // struct as_functor

// Point to vector conversion.
// TODO: The "as" functor (facade functor) is more efficient. Add "as" functor.
template<typename TARGET, typename SOURCE>
struct to_functor<TARGET,
                  SOURCE,
                  enable_if_t<is_vector_v<TARGET> && is_point_v<SOURCE>>>
{
  using target_type = TARGET;
  using source_type = SOURCE;

  using result_type = TARGET;
  using qualified_result_type = TARGET;

  qualified_result_type operator()(const source_type& source) const
  {
    return implementation(
      source, make_index_sequence < number_of_elements_v<source_type>>{});
  }

  template<size_t ... I>
  qualified_result_type implementation(const source_type& source,
                                   index_sequence<I...>) const
  {
    return result_type{ source(I)... };
  }
}; // struct as_functor

} // namespace primordialmachine
