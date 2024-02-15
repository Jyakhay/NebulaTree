#pragma once

#include <vector>
#include "Character.h"
#include "Section.h"

namespace NTree
{

	struct Tree
	{

		void Next();

		std::vector<Character> Characters;
		std::vector<Section> Sections;

		Section GetCurrentSection() const {return Sections[CurrentSection];}
		Character* GetCharacterByName(const std::string& Name);

		int CurrentSection = 0;

	};

}
