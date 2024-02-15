#pragma once
#include <string>
#include <vector>

#include "Dialogue.h"
#include "Function.h"

namespace NTree
{
	struct Section
	{

		void Next();
		void Previous();

		void GoToLine(int Index);

		bool IsCurrentLineDialogue();
		bool IsCurrentLineFunction();

		Dialogue GetCurrentDialogue() const {return Dialogue[DialogueIndex];}

		std::vector<std::string> Body;

		std::vector<Dialogue> Dialogue;
		std::vector<Function> FunctionCalls;

		int CurrentLine = 0;

		int DialogueIndex = 0;
		int FunctionIndex = 0;

	};
}
