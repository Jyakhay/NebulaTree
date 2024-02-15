#pragma once

#include <string>
#include <vector>

namespace NTree
{
	struct Function
	{

	public:

		Function(const std::string& FunctionID, const std::vector<std::string>& ParameterValues)
			:m_FunctionID(FunctionID), m_Parameters(ParameterValues) {}

		std::string GetFunctionID() const { return m_FunctionID; }
		const std::vector<std::string>& GetParameters() const { return m_Parameters; }

	private:

		std::string m_FunctionID;
		std::vector<std::string> m_Parameters;
	};
}
