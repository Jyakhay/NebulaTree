#include "NebulaTree.h"

#include "FunctionBinds.h"
#include <iostream>

void PlaySound(NTree::Tree* OwningTree, const std::vector<std::string> Args)
{

}

class MyEntity
{

public:

	float Health = 0.0f;
};

void LookAtCharacter(NTree::Tree* OwningTree, const std::vector<std::string> Args)
{
	static_cast<MyEntity*>(OwningTree->GetCharacterByName(Args[0])->GetUserData())->Health;
}

int main()
{

	BindFunction("LookAtCharacter", &LookAtCharacter);
	BindFunction("PlaySound", &PlaySound);

	NTree::Tree TestTree = NTree::TreeFromFile("Example.ntree");
	TestTree.Begin();

	MyEntity Alex;
	TestTree.GetCharacterByName("Alex")->SetUserData(&Alex);

	std::cout << TestTree.GetCurrentDialogue().GetSpeech() << '\n';
	TestTree.Next();

	std::cout << TestTree.GetCurrentDialogue().GetSpeech() << '\n';
	TestTree.Next();

	std::cout << TestTree.GetCurrentDialogue().GetSpeech() << '\n';
	TestTree.Next();

	std::cout << TestTree.GetCurrentDialogue().GetSpeech() << '\n';
	std::cin.get();
}