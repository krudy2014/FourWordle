#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <Windows.h>
#include "Console.hpp"

namespace Console {
	HANDLE hConsole;

	void Initialize() {
		SetFontSize(28);
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	void Clear() {
		system("CLS");
	}

	//Allowed font sizes for Consolas: 16, 18, 20, 24, 28, 36, 72
	void SetFontSize(int FontSize) {
		CONSOLE_FONT_INFOEX info = { 0 };
		info.cbSize = sizeof(info);
		info.dwFontSize.Y = FontSize; // leave X as zero
		info.FontWeight = FW_NORMAL;
		wcscpy_s(info.FaceName, L"Consolas");
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	}

	void SetColor(int aColor) {
		SetConsoleTextAttribute(hConsole, aColor);
	}

	void OutputBlankLine() {
		printf("\n");
	}

	void OutputText(const char* aText) {
		printf("%s", aText);
	}

	void OutputText(const char* aText, ...) {
		va_list args;
		va_start(args, aText);
		vprintf(aText, args);
		va_end(args);
	}

	void OutputText(char aLetter) {
		printf("%c", aLetter);
	}

	void GetInputString(std::string& aInput) {
		std::getline(std::cin, aInput);
	}

	void WaitForInput() {
		std::cin.ignore();
	}
}