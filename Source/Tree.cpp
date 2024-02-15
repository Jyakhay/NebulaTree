#include "Tree.h"

namespace NTree
{
	void Tree::Begin()
	{
		for(auto& CurrentSection: m_Sections)
		{
			CurrentSection.m_OwningTree = this;
		}
	}

	void Tree::Next()
	{
		GetCurrentSection()->Next();
	}

	Character* Tree::GetCharacterByName(const std::string& Name)
	{
		for(auto& CurrentChar : m_Characters)
		{
			if(CurrentChar.GetName() == Name)
			{
				return &CurrentChar;
			}
		}

		return nullptr;
	}
}
