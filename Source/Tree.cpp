#include "Tree.h"

namespace NTree
{

	void Tree::Next()
	{
		GetCurrentSection().Next();
	}

	Character* Tree::GetCharacterByName(const std::string& Name)
	{
		for(auto& CurrentChar : Characters)
		{
			if(CurrentChar.Name == Name)
			{
				return &CurrentChar;
			}
		}

		return nullptr;
	}
}
