//Copyright 2022, Kelsey Rudy, All Rights Reserved

#pragma once
#include <string>

//This module handles logic that is specific
//to outputting to the windows console. This is
//created such that if a different app was chosen (i.e., not Windwos),
//it could be a drop in replacement here.

#define WHITE (7)
#define GREEN (2)
#define YELLOW (6)
#define RED (4)

namespace Console {
	void Initialize();
	void Clear();
	void SetFontSize(int FontSize);
	void SetColor(int aColor);
	void OutputBlankLine();
	void OutputText(const char* aText, ...);
	void OutputText(char aLetter);
	void GetInputString(std::string& aInput);
	void WaitForInput();
}