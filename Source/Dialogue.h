#pragma once
#include "Character.h"

namespace NTree
{
	struct Dialogue
	{

		Dialogue() = default;

		Dialogue(Character* Speaker, const std::string& Speech)
			:Speaker(Speaker), Speech(Speech) {}

		operator bool() const
		{
			return Speaker != nullptr;
		}

		Character* Speaker;
		std::string Speech;
	};
}
