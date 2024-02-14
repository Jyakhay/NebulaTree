#pragma once
#include <string>
#include <vector>

namespace NTree
{
	struct Function
	{

		Function(const std::string& FunctionID, const std::vector<std::string>& ParameterValues)
			:FunctionID(FunctionID), Parameters(ParameterValues) {}

		std::string FunctionID;
		std::vector<std::string> Parameters;
	};
}
