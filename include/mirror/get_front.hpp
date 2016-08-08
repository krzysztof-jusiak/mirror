/**
 * @file mirror/get_front.hpp
 * @brief Implementation of the `get_front` operation
 *
 * Copyright Matus Chochlik.
 * Distributed under the Boost Software License, Version 1.0.
 * See accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef MIRROR_GET_FRONT_1105240825_HPP
#define MIRROR_GET_FRONT_1105240825_HPP

#include "int_const.hpp"
#include "optional.hpp"
#include "range.hpp"
#include "string.hpp"

namespace mirror {
namespace _aux {

template <typename X>
struct op_get_front;

template <>
struct op_get_front<empty_range>
 : empty_optional
{ };

template <typename H, typename ... T>
struct op_get_front<range<H, T...>>
 : optional<H>
{ };

template <typename Char>
struct op_get_front<basic_string<Char>>
 : empty_optional
{ };

template <typename Char, Char CH, Char ... CT>
struct op_get_front<basic_string<Char, CH, CT...>>
 : optional<int_const<Char, CH>>
{ };

} // namespace _aux

template <typename X>
using get_front = eval<_aux::op_get_front<X>>;

template <typename X>
using front = get_front<X>;

} // namespace mirror

#endif //include guard
