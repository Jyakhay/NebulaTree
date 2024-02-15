#pragma once
#include <string>
#include <vector>

#include "Dialogue.h"
#include "Function.h"

namespace NTree
{
	struct Tree;
}

namespace NTree
{
	struct Section
	{

	public:

		void Next();

		bool IsCurrentLineDialogue();
		bool IsCurrentLineFunction();

		Dialogue GetCurrentDialogue() const {return m_Dialogue[m_DialogueIndex];}
		Tree* GetOwningTree() const { return m_OwningTree; }

		const std::vector<std::string>& GetBody() const { return m_Body; }
		const std::vector<Dialogue>& GetDialogue() const { return m_Dialogue; }
		const std::vector<Function>& GetFunctionCalls() const { return m_FunctionCalls; }

	private:

		Tree* m_OwningTree;

		std::vector<std::string> m_Body;
		std::vector<Dialogue> m_Dialogue;
		std::vector<Function> m_FunctionCalls;

		int m_CurrentLine = 0;
		int m_DialogueIndex = 0;
		int m_FunctionIndex = 0;

		friend struct Tree;
		friend class TreeParser;

	};
}
