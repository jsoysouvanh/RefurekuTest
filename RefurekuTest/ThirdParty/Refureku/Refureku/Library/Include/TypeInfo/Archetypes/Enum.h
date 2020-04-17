#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include "TypeInfo/Archetypes/Archetype.h"
#include "TypeInfo/EnumValue.h"

namespace rfk
{
	class Enum : public Archetype
	{
		public:
			/** Values contained in this enum */
			std::unordered_set<EnumValue, Entity::NameHasher, Entity::EqualName>	values;

			Enum()													= delete;
			Enum(std::string&& name, uint64 id, uint64 memorySize)	noexcept;
			Enum(Enum const&)										= delete;
			Enum(Enum&&)											= default;
			~Enum()													= default;

			/** Get the EnumValue corresponding to the provided name if any, else nullptr */
			inline EnumValue const*					getEnumValue(std::string enumValueName)	const noexcept;
			
			/** Get the first found EnumValue corresponding to the provided value if any, else nullptr */
			inline EnumValue const*					getEnumValue(int64 value)				const noexcept;

			/** Get all the EnumValues corresponding to the provided value */
			inline std::vector<EnumValue const*>	getEnumValues(int64 value)				const noexcept;

			Enum& operator=(Enum const&)	= delete;
			Enum& operator=(Enum&&)			= default;
	};

	#include "TypeInfo/Archetypes/Enum.inl"

	/** Base implementation of getEnum, specialized for each reflected enum */
	template <typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
	inline rfk::Enum const* getEnum() noexcept
	{
		return nullptr;
	}
}