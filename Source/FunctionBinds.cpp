#include "FunctionBinds.h"

namespace NTree
{

    void FunctionBinder::ExecuteFunction(const std::string& Function, Tree* OwningTree, const std::vector<std::string>& Arguments)
    {
        if(m_Functions.find(Function) != m_Functions.end())
        {
            m_Functions.at(Function)(OwningTree, Arguments);
        }
    }

    void FunctionBinder::BindFunction(const std::string& FunctionID, CallbackFunction Function)
    {
        m_Functions.emplace(FunctionID, Function);
    }

}