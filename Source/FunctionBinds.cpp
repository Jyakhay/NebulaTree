#include "FunctionBinds.h"

namespace NTree
{

    void FunctionBinder::ExecuteFunction(const std::string Function, const std::vector<std::string>& Arguments)
    {
        if(m_Functions.find(Function) != m_Functions.end())
        {
            m_Functions.at(Function)(Arguments);
        }
    }

    void FunctionBinder::BindFunction(const std::string& FunctionID, std::function<void(std::vector<std::string>)> Function)
    {
        m_Functions.emplace(FunctionID, Function);
    }

}