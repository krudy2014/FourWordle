#include <algorithm>
#include <vector>
#include "Console.hpp"
#include "Dictionary.hpp"
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

int main() {
	Console::Initialize();

	Console::OutputText("Welcome to a rip off Wordle! %d letters and %d guesses.\n", MAX_LETTERS, MAX_ATTEMPTS);
	Console::OutputText("Press enter to continue.\n");
	Console::WaitForInput();
	Board activeBoard;
	std::string inputString;
	bool playing = true;
	bool guessedCorrect = false;
	bool endCurrentGame = false;
	bool reset = true;
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
				Console::SetColor(GREEN);
				Console::OutputText("\nYou guessed correctly!\n");
			}
			else {
				Console::SetColor(RED);
				Console::OutputText("\nSecret word: %s\n", Dictionary::GetSecretWord());
			}
			Console::SetColor(WHITE);
			Console::OutputText("Play again (Y/y) or (N/n)?\n");

			std::string temp;
			Console::GetInputString(temp);
			if (temp[0] == 'y' || temp[0] == 'Y') {
				reset = true;
			}
			else {
				playing = false;
			}
		}
		else {
			if (activeBoard.GetActiveRow() < MAX_ATTEMPTS) {
				//Console::OutputText("Secret word: %s\n", Dictionary::GetSecretWord());
				switch (status) {
					case IncorrectLength:
						Console::SetColor(RED);
						Console::OutputText("Enter a %d letter word only.\n", MAX_LETTERS);
						break;

					case ContainsNumbers:
						Console::SetColor(RED);
						Console::OutputText("Enter letters (A-Z) only.\n");
						break;

					case NotInDictionary:
						Console::SetColor(RED);
						Console::OutputText("Word not in stored dictionary.\n");
						break;

					case Valid:
					default:
						break;
				}

				Console::SetColor(WHITE);
				Console::OutputText("\nEnter your guess (%d letter word): ", MAX_LETTERS);
				Console::GetInputString(inputString);

				status = validateString(inputString);
				if (Valid == status) {
					//update the next word with the input string and secret word
					activeBoard.SetNextGuess(inputString);
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