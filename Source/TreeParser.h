#pragma once

#include "Tree.h"

#include <string>
#include <vector>

namespace NTree
{

	class TreeParser
	{

	public:

		static Tree ParseString(const std::string& Str);

	private:

		//Parse Functions

		//Removes all decorative lines, including empty and commented lines.
		static void RemoveEmptyLines(std::vector<std::string>& Lines);

		//Retrieves the function section body.
		static void GetFunctionSection(const std::vector<std::string>& Lines, std::vector<std::string>* BodyLines);

		//Retrieves the character section body.
		static void GetCharacterSection(const std::vector<std::string>& Lines, std::vector<std::string>* BodyLines);

		//Retrieves lines of all sections.
		static void GetTreeSections(const std::vector<std::string>& Lines, std::vector<std::vector<std::string>>* Sections);

		//Utilities

		static std::string ToLower(const std::string& Str);

	};

}
