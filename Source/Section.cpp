#include "Section.h"

namespace NTree
{
	bool Section::IsCurrentLineDialogue()
	{
		return Body[CurrentLine].find(':') != -1;
	}

	bool Section::IsCurrentLineFunction()
	{
		return !IsCurrentLineDialogue();
	}
}
