#pragma once
#include <string>

namespace NTree
{

	struct Character
	{

	public:

		Character(const std::string& Name)
			:m_Name(Name) {}

		void SetUserData(void* NewData) { m_UserData = NewData; }
		void* GetUserData() const { return m_UserData; }

		std::string GetName() const { return m_Name; }

	private:

		std::string m_Name;
		void* m_UserData = nullptr;

	};

}
