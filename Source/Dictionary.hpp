#pragma once
#include <string>

namespace Dictionary {
	void Initialize();
	const char* GetSecretWord();
	const int* GetSecretWordStats();
	bool InDictionary(std::string aString);
	bool InWord(const char* aWord, char aLetter);
}