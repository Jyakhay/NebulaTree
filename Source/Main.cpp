#include "TreeParser.h"

#include <fstream>
#include <sstream>

int main()
{

	std::ifstream FileStream = std::ifstream("Example.ntree");
	std::stringstream FileInput;
	FileInput << FileStream.rdbuf();

	NTree::Tree Test = NTree::TreeParser::ParseString(FileInput.str());
	FileStream.close();
}