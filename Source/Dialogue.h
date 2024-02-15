#pragma once
#include "Character.h"

namespace NTree
{
	struct Dialogue
	{

	public:

		Dialogue() = default;

		Dialogue(Character* Speaker, const std::string& Speech)
			:m_Speaker(Speaker), m_Speech(Speech) {}

		Character* GetCharacter() const { return m_Speaker; };
		std::string GetSpeech() const { return m_Speech; };

		operator bool() const
		{
			return m_Speaker != nullptr;
		}

	private:

		Character* m_Speaker;
		std::string m_Speech;
	};
}
