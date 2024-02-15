#pragma once

#include <unordered_map>
#include <functional>
#include <string>

namespace NTree
{
    class FunctionBinder
    {

    public:

        static void ExecuteFunction(const std::string Function, const std::vector<std::string>& Arguments);
        static void BindFunction(const std::string& FunctionID, std::function<void(std::vector<std::string>)> Function);

    private:
 
        static inline std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> m_Functions;

    };
}