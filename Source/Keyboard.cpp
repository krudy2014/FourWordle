//Copyright 2022, Kelsey Rudy, All Rights Reserved

#include <assert.h>
#include "Console.hpp"
#include "Dictionary.hpp"
#include "Keyboard.hpp"

char KeyboardOrder[LETTERS_IN_ALPHABET] = {
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M'
};

Keyboard::Keyboard() {
	for (auto i = 0; i < mLetters.size(); i++) {
		mLetters[i].SetLetter(KeyboardOrder[i]);
	}
	//TODO: To improve getIndex(), create a hashmap
	//mapping the letter to the correct index. This
	//will prevent getIndex from searching through
	//entire array each time.
}

int getIndex(char aLetter) {
	for (auto i = 0; i < LETTERS_IN_ALPHABET; i++) {
		if (aLetter == KeyboardOrder[i]) {
			return i;
		}
	}

	assert(true);
	return 0;
}

//Draws a keyboard in QWERTY format
void Keyboard::Draw() {
	int row = 0;
	for (auto i = 0; i < mLetters.size(); i++) {
		if (i == 10 || i == 19) {
			//Start a new row
			Console::OutputBlankLine();
			row++;
			if (row >= 1) {
				Console::OutputText(" ");
			}
			if (row >= 2) {
				//Extra space for third row
				Console::OutputText(" ");
			}
		}
		mLetters[i].Draw();
		Console::OutputText(" ");
	}
}

void Keyboard::SetNextGuess(std::string aGuess) {
	const char* secretWord = Dictionary::GetSecretWord();
	for (auto i = 0; i < aGuess.length(); i++) {
		Letter::State newState = Letter::State::Incorrect;
		if (secretWord[i] == aGuess[i]) {
			newState = Letter::State::Correct;
		}
		else if (Dictionary::InWord(secretWord, aGuess[i])) {
			newState = Letter::State::WrongSpot;
		}

		//If the state has already been set to "Correct",
		//don't change it any more.
		auto letterIndex = getIndex(aGuess[i]);
		if (mLetters[letterIndex].GetState() !=
			Letter::State::Correct) {
			mLetters[letterIndex].SetState(newState);
		}
	}
}

void Keyboard::Reset() {
	for (auto i = 0; i < mLetters.size(); i++) {
		mLetters[i].Reset();
	}
}