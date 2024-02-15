#pragma once

#include <fstream>
#include <sstream>
#include <string>

#include "Tree.h"
#include "TreeParser.h"
#include "FunctionBinds.h"

namespace NTree
{

    inline Tree TreeFromFile(const std::string& Path)
    {
        const std::ifstream FileStream(Path);
        std::stringstream FileBufferStream;
        FileBufferStream << FileStream.rdbuf();

        return TreeParser::ParseString(FileBufferStream.str());
    }

    inline void BindFunction(const std::string& FunctionID, const CallbackFunction& Callback)
    {
        FunctionBinder::BindFunction(FunctionID, Callback);
    }

}