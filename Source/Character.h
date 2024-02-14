#pragma once
#include <string>

namespace NTree
{

	struct Character
	{

		Character(const std::string& Name)
			:Name(Name) {}

		std::string Name;
		void* UserData = nullptr;

	};

}
