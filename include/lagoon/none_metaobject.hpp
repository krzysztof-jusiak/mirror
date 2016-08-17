/**
 * @file lagoon/none_metaobject.hpp
 * @brief Declaration of the `none_metaobject` class
 *
 * Copyright Matus Chochlik.
 * Distributed under the Boost Software License, Version 1.0.
 * See accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef LAGOON_NONE_METAOBJECT_1105240825_HPP
#define LAGOON_NONE_METAOBJECT_1105240825_HPP

#include "metaobject.hpp"

namespace lagoon {

class base_registry;

class none_metaobject
 : public metaobject
{
private:
	base_registry& _reg;
	metaobject_traits _ts;
public:
	none_metaobject(base_registry& reg)
	noexcept
	 : _reg(reg)
	{ }

	bool is_none(void) const
	override;

	const metaobject_traits& traits(void)
	override;

	std::string_view get_base_name(void)
	override;

	std::string_view get_full_name(void)
	override;

	std::string_view get_display_name(void)
	override;

	shared_metaobject get_type(void)
	override;

	shared_metaobject get_scope(void)
	override;

	shared_metaobject get_aliased(void)
	override;

	shared_metaobject_sequence get_base_classes(void)
	override;

	shared_metaobject_sequence get_data_members(void)
	override;

	shared_metaobject_sequence get_member_types(void)
	override;

	shared_metaobject_sequence get_enumerators(void)
	override;
};

} // namespace lagoon

#include <lagoon/none_metaobject.inl>

#endif //include guard
