#include "Section.h"

#include "FunctionBinds.h"

namespace NTree
{

	void Section::Next()
	{

		m_CurrentLine++;

		if(IsCurrentLineFunction())
		{
			const Function CurrentFunction = m_FunctionCalls[m_FunctionIndex];
			FunctionBinder::ExecuteFunction(CurrentFunction.GetFunctionID(), m_OwningTree, CurrentFunction.GetParameters());

			m_FunctionIndex++;

			Next();

			return;
		}

		m_DialogueIndex++;
	}

	bool Section::IsCurrentLineDialogue()
	{
		return m_Body[m_CurrentLine].find(':') != -1;
	}

	bool Section::IsCurrentLineFunction()
	{
		return !IsCurrentLineDialogue();
	}
}
