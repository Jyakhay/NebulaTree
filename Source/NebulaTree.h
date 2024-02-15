#pragma once

#include <fstream>
#include <sstream>

#include <string>
#include "Tree.h"
#include "TreeParser.h"

NTree::Tree TreeFromFile(const std::string& Path)
{
    std::ifstream Filestream(Path);
    std::stringstream FileBufferStream;
    FileBufferStream << Filestream.rdbuf();

    return NTree::TreeParser::ParseString(FileBufferStream.str());
}