#pragma once

#include <iostream>
#include <vector>

#include "Misc/FundamentalTypes.h"

#include "Misc/EAccessSpecifier.h"
#include "InfoStructures/EntityInfo.h"
#include "InfoStructures/TypeInfo.h"
#include "InfoStructures/MethodParamInfo.h"

namespace kodgen
{
	class MethodInfo : public EntityInfo
	{
		public:
			struct MethodQualifiers
			{
				bool isDefault		: 1;
				bool isStatic		: 1;
				bool isVirtual		: 1;
				bool isPureVirtual	: 1;
				bool isInline		: 1;
				bool isOverride		: 1;
				bool isFinal		: 1;
				bool isConst		: 1;

			}								qualifiers;

			EAccessSpecifier				accessSpecifier;

			/** Prototype of this method as a string */
			std::string						prototype;

			TypeInfo						returnType;
			std::vector<MethodParamInfo>	parameters;

			MethodInfo()														= default;
			MethodInfo(CXCursor const& cursor, PropertyGroup&& propertyGroup)	noexcept;
			MethodInfo(MethodInfo const&)										= default;
			MethodInfo(MethodInfo&&)											= default;
			~MethodInfo()														= default;

			std::string getName()																const noexcept;
			std::string getPrototype(bool removeQualifiers = false, bool removeSpaces = false)	const noexcept;
	};

	std::ostream& operator<<(std::ostream& out_stream, MethodInfo const& methodInfo) noexcept;
}