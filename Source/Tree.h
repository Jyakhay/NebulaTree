#pragma once

#include <iostream>
#include <vector>
#include "Character.h"
#include "Section.h"

namespace NTree
{

	struct Tree
	{

	public:

		void Begin();
		void Next();

		Dialogue GetCurrentDialogue() { return GetCurrentSection()->GetCurrentDialogue(); }

		Section* GetCurrentSection() {return &m_Sections[m_CurrentSection];}
		Character* GetCharacterByName(const std::string& Name);


	private:

		std::vector<Character> m_Characters;
		std::vector<Section> m_Sections;

		int m_CurrentSection = 0;

		friend class TreeParser;

	};

}
