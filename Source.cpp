#include <vector>
#include <iostream>
#include <algorithm>
#include "Dictionary.hpp"
#include "Row.hpp"
#include "Board.hpp"
#include "Main.hpp"

enum InputStatus {
	Valid,
	IncorrectLength,
	ContainsNumbers,
	NotInDictionary
};

InputStatus validateString(std::string& aString) {
	//Check to make sure it is the correct length,
	//only letters, and all caps (auto correct to all caps)
	if (aString.size() != MAX_LETTERS) {
		return IncorrectLength;
	}
	std::transform(aString.begin(), aString.end(), aString.begin(), ::toupper);

	for (auto i = 0; i < aString.size(); i++) {
		if (aString[i] < 'A' || aString[i] > 'Z') {
			return ContainsNumbers;
		}
	}

	if (!Dictionary::InDictionary(aString)) {
		return NotInDictionary;
	}
	return Valid;
}

//Allowed font sizes for Consolas
//16
//18
//20
//24
//28
//36
//72
void SetFontSize(int FontSize){
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}

int main() {
	SetFontSize(28);

	printf("Welcome to a rip off Wordle! %d letters and %d guesses.\n", MAX_LETTERS, MAX_ATTEMPTS);
	printf("Press enter to continue.\n");
	std::cin.ignore();
	Board activeBoard;
	std::string inputString;
	bool playing = true;
	bool guessedCorrect = false;
	bool endCurrentGame = false;
	bool reset = true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	InputStatus status = Valid;

	while (playing) {
		if (reset) {
			activeBoard.Reset();
			guessedCorrect = false;
			endCurrentGame = false;
			reset = false;
			status = Valid;
			Dictionary::Initialize();
		}

		activeBoard.Draw();

		if (endCurrentGame) {
			if (guessedCorrect) {
				SetConsoleTextAttribute(hConsole, GREEN);
				printf("\nYou guessed correctly!\n");
			}
			else {
				SetConsoleTextAttribute(hConsole, RED);
				printf("\nSecret word: %s\n", Dictionary::GetSecretWord());
			}
			SetConsoleTextAttribute(hConsole, WHITE);
			printf("Play again (Y/y) or (N/n)?\n");

			std::string temp;
			std::getline(std::cin, temp);
			if (temp[0] == 'y' || temp[0] == 'Y') {
				reset = true;
			}
			else {
				playing = false;
			}
		}
		else {
			if (activeBoard.GetActiveRow() < MAX_ATTEMPTS) {
				printf("Secret word: %s\n", Dictionary::GetSecretWord());
				switch (status) {
					case IncorrectLength:
						SetConsoleTextAttribute(hConsole, RED);
						printf("Enter a %d letter word only.\n", MAX_LETTERS);
						break;

					case ContainsNumbers:
						SetConsoleTextAttribute(hConsole, RED);
						printf("Enter letters (A-Z) only.\n");
						break;

					case NotInDictionary:
						SetConsoleTextAttribute(hConsole, RED);
						printf("Word not in stored dictionary.\n");
						break;

					case Valid:
					default:
						break;
				}

				SetConsoleTextAttribute(hConsole, WHITE);
				printf("\nEnter your guess (%d letter word): ", MAX_LETTERS);
				std::getline(std::cin, inputString);

				status = validateString(inputString);
				if (Valid == status) {
					//update the next word with the input string and secret word
					activeBoard.Update(inputString);
				}

				if (strcmp(inputString.c_str(), Dictionary::GetSecretWord()) == 0) {
					guessedCorrect = true;
					endCurrentGame = true;
				}
			}
			else {
				endCurrentGame = true;
			}
		}
	}

	return 0;
}