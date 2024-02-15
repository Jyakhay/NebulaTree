#pragma once

#include <unordered_map>
#include <functional>
#include <string>

#include "Tree.h"

namespace NTree
{

    //void(Tree* Instigator, std::vector<std::string> Arguments)
    typedef std::function<void(Tree*, std::vector<std::string>)> CallbackFunction;

    class FunctionBinder
    {

    public:

        static void ExecuteFunction(const std::string& Function, Tree* Instigator, const std::vector<std::string>& Arguments);
        static void BindFunction(const std::string& FunctionID, CallbackFunction Function);

    private:
 
        static inline std::unordered_map<std::string, CallbackFunction> m_Functions;

    };
}
