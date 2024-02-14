#pragma once

#include <vector>
#include "Character.h"
#include "Section.h"

namespace NTree
{

	struct Tree
	{

		std::vector<Character> Characters;
		std::vector<Section> Sections;

		Character* GetCharacterByName(const std::string& Name);

		int CurrentSection = 0;

	};

}
