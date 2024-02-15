#include "NebulaTree.h"

#include "FunctionBinds.h"
#include <iostream>

void PrintArgs(std::vector<std::string> Args)
{
	std::cout << Args[0];
}

int main()
{
	NTree::FunctionBinder::BindFunction("PrintArgs", &PrintArgs);
	NTree::Tree TestTree = TreeFromFile("Example.ntree");

	std::cout << TestTree.GetCurrentSection().GetCurrentDialogue().Speech << '\n';
	TestTree.Next();
	std::cin.get();

	std::cout << TestTree.GetCurrentSection().GetCurrentDialogue().Speech << '\n';
	std::cin.get();
}