//Copyright 2022, Kelsey Rudy, All Rights Reserved

#pragma once
#include <string>

//Helper functions to interact with stored dictionary
namespace Dictionary {
	void Initialize();
	const char* GetSecretWord();
	const int* GetSecretWordStats();
	bool InDictionary(std::string aString);
	bool InWord(const char* aWord, char aLetter);
}