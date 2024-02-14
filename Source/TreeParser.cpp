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

		Tree ReturnValue;

		for(auto& CharacterString : CharacterBody)
		{
			ReturnValue.Characters.push_back(Character(CharacterString));
		}

		for(const auto& CurSection : Sections)
		{
			Section NewSection;
			NewSection.Body = CurSection;

			for(const auto& CurLine : NewSection.Body)
			{
				if(CurLine.find(':') != -1)
				{
					std::string CharacterName;
					std::string Speech;

					ParseDialogue(CurLine, &CharacterName, &Speech);

					NewSection.Dialogue.push_back(Dialogue(ReturnValue.GetCharacterByName(CharacterName), Speech));
				}
				else
				{
					std::string FunctionID;
					std::vector<std::string> Parameters;

					ParseFunction(CurLine, &FunctionID, &Parameters);

					NewSection.FunctionCalls.push_back(Function(FunctionID, Parameters));
				}
			}

			ReturnValue.Sections.push_back(NewSection);
		}

		return ReturnValue;
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

	void TreeParser::ParseDialogue(const std::string& Line, std::string* Character, std::string* Speech)
	{
		const int NameEndIndex = Line.find(':');

		if(NameEndIndex != -1)
		{
			*Character = Line.substr(0, NameEndIndex);
		}

		const std::string SpeechSection = Line.substr(NameEndIndex + 1, Line.length() - NameEndIndex);
		int SpeechStartIndex = -1;

		for(int i = 0; i < SpeechSection.length(); i++)
		{
			if(SpeechSection[i] != ' ')
			{
				SpeechStartIndex = i;
				break;
			}
		}

		if(SpeechStartIndex != -1)
		{
			*Speech = SpeechSection.substr(SpeechStartIndex, SpeechSection.length() - SpeechStartIndex);
		}

	}

	void TreeParser::ParseFunction(const std::string& Line, std::string* Function, std::vector<std::string>* Parameters)
	{
		const int FunctionEndIndex = Line.find('(');

		if(FunctionEndIndex != -1)
		{
			*Function = Line.substr(0, FunctionEndIndex);

			const std::string ParameterList = Line.substr(FunctionEndIndex + 1, Line.length() - FunctionEndIndex - 2);

			std::stringstream Stream;
			Stream << ParameterList;

			std::string CurrentParameter;
			while(std::getline(Stream, CurrentParameter, ','))
			{
				Parameters->push_back(RemoveWhitespace(CurrentParameter));
			}
		}
	}

	std::string TreeParser::RemoveWhitespace(const std::string& Str)
	{
		std::string ReturnValue = Str;

		for(int i = Str.size() - 1; i >= 0; i--)
		{
			if(Str[i] == ' ')
			{
				ReturnValue.erase(ReturnValue.begin() + i);
			}
		}

		return ReturnValue;
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
