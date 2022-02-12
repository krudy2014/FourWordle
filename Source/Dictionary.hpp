#pragma once
#include <string>

namespace Dictionary {
	void Initialize();
	const char* GetSecretWord();
	bool InDictionary(std::string aString);
}