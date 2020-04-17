#pragma once

#include <array>

#include <InfoStructures/StructClassInfo.h>

#include "GeneratedEntityCodeTemplate.h"

namespace rfk
{
	class GeneratedClassCodeTemplate : public GeneratedEntityCodeTemplate
	{
		private:
			void						generateClassCode(kodgen::GeneratedFile& generatedFile, kodgen::StructClassInfo const& classInfo)			const	noexcept;
			void						generateStructCode(kodgen::GeneratedFile& generatedFile, kodgen::StructClassInfo const& structInfo)			const	noexcept;

			kodgen::uint16				computeMethodFlags(kodgen::MethodInfo const& method)														const	noexcept;
			kodgen::uint16				computeFieldFlags(kodgen::FieldInfo const& field)															const	noexcept;

			/** Return generated macro name */
			std::string					generateGetArchetypeMacro(kodgen::GeneratedFile& generatedFile, kodgen::StructClassInfo const& info)		const	noexcept;
			std::string					generateArchetypePropertiesMacro(kodgen::GeneratedFile& generatedFile, kodgen::EntityInfo const& info)		const	noexcept;
			std::string					generateDefaultInstantiateMacro(kodgen::GeneratedFile& generatedFile, kodgen::StructClassInfo const& info)	const	noexcept;
			std::string					generateRegistrationMacro(kodgen::GeneratedFile& generatedFile, kodgen::StructClassInfo const& info)		const	noexcept;
			std::string					generateParentsMetadataMacro(kodgen::GeneratedFile& generatedFile, kodgen::StructClassInfo const& info)		const	noexcept;
			std::string					generateMethodsMetadataMacro(kodgen::GeneratedFile& generatedFile, kodgen::StructClassInfo const& info)		const	noexcept;
			std::array<std::string, 2>	generateFieldsMetadataMacros(kodgen::GeneratedFile& generatedFile, kodgen::StructClassInfo const& info)		const	noexcept;
			std::string					generateFieldHelperMethodsMacro(kodgen::GeneratedFile& generatedFile,
																		 kodgen::StructClassInfo const& info)										const	noexcept;

		protected:
			virtual void	generateCode(kodgen::GeneratedFile& generatedFile, kodgen::EntityInfo const& entityInfo)					const	noexcept override;
	};
}
