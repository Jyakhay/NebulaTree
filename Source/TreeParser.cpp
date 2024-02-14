#include "TreeParser.h"

#include <sstream>
#include <vector>

namespace NTree
{
	Tree TreeParser::ParseString(const std::string& Str)
	{

		std::vector<std::string> TreeLines;

		std::stringstream InputStream;
		InputStream << Str;

		std::string CurrentLine;

		while (std::getline(InputStream, CurrentLine))
		{
			TreeLines.push_back(CurrentLine);
		}

		RemoveEmptyLines(TreeLines);

		std::vector<std::string> FunctionBody;
		GetFunctionSection(TreeLines, &FunctionBody);

		std::vector<std::string> CharacterBody;
		GetCharacterSection(TreeLines, &CharacterBody);

		std::vector<std::vector<std::string>> Sections;
		GetTreeSections(TreeLines, &Sections);

		return Tree();
	}

	void TreeParser::RemoveEmptyLines(std::vector<std::string>& Lines)
	{
		for(int i = Lines.size() - 1; i >= 0; i--)
		{
			if(Lines[i].length() <= 1 || Lines[i].find("//") != -1)
			{
				Lines.erase(Lines.begin() + i);
			}
		}
	}

	void TreeParser::GetFunctionSection(const std::vector<std::string>& Lines, std::vector<std::string>* BodyLines)
	{

		int StartIndex = -1;
		int EndIndex = -1;

		for(int i = 0; i < Lines.size(); i++)
		{

			//Search for body start, then next body start, or end of file.
			if (StartIndex == -1)
			{
				if (ToLower(Lines[i]) == "#functions")
				{
					StartIndex = i + 1;
				}
			}
			else
			{
				if(Lines[i][0] == '#' || i == Lines.size() - 1)
				{
					EndIndex = i;
					break;
				}
			}
		}

		if (EndIndex != -1)
		{
			BodyLines->insert(BodyLines->begin(), Lines.begin() + StartIndex, Lines.begin() + EndIndex);
		}

	}

	void TreeParser::GetCharacterSection(const std::vector<std::string>& Lines, std::vector<std::string>* BodyLines)
	{
		int StartIndex = -1;
		int EndIndex = -1;

		for (int i = 0; i < Lines.size(); i++)
		{

			//Search for body start, then next body start, or end of file.
			if (StartIndex == -1)
			{
				if (ToLower(Lines[i]) == "#characters")
				{
					StartIndex = i + 1;
				}
			}
			else
			{
				if (Lines[i][0] == '#' || i == Lines.size() - 1)
				{
					EndIndex = i;
					break;
				}
			}
		}

		if (EndIndex != -1)
		{
			BodyLines->insert(BodyLines->begin(), Lines.begin() + StartIndex, Lines.begin() + EndIndex);
		}
	}

	void TreeParser::GetTreeSections(const std::vector<std::string>& Lines,
		std::vector<std::vector<std::string>>* Sections)
	{

		int StartIndex = -1;

		for (int i = 0; i < Lines.size(); i++)
		{

			//Search for body start, then next body start, or end of file.
			if (StartIndex == -1)
			{
				if (ToLower(Lines[i]).find("#section") != -1)
				{
					StartIndex = i + 1;
				}
			}
			else
			{
				if (Lines[i][0] == '#' || i == Lines.size() - 1)
				{

					std::vector<std::string> NewSection;
					NewSection.insert(NewSection.begin(), Lines.begin() + StartIndex, Lines.begin() + i + (i == Lines.size() - 1 ? 1 : 0));

					Sections->push_back(NewSection);

					if(Lines[i][0] == '#')
					{
						i--;
					}

					StartIndex = -1;
					
				}
			}
		}

	}

	std::string TreeParser::ToLower(const std::string& Str)
	{

		std::string CurrentString;

		for(const auto CurrentChar : Str)
		{
			CurrentString += tolower(CurrentChar);
		}

		return CurrentString;

	}
}
