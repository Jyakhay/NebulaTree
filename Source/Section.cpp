#include "Section.h"

#include "FunctionBinds.h"

namespace NTree
{

	void Section::Next()
	{
		if(IsCurrentLineFunction())
		{
			Function CurrentFunction = FunctionCalls[FunctionIndex];
			FunctionBinder::ExecuteFunction(CurrentFunction.FunctionID, CurrentFunction.Parameters);

			FunctionIndex++;
			Next();

			return;
		}

		DialogueIndex++;
	}

	bool Section::IsCurrentLineDialogue()
	{
		return Body[CurrentLine].find(':') != -1;
	}

	bool Section::IsCurrentLineFunction()
	{
		return !IsCurrentLineDialogue();
	}
}
