#include "Dictionary.hpp"
#include "Keyboard.hpp"
#include <assert.h>

char KeyboardOrder[LETTERS_IN_ALPHABET] = {
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M'
};

Keyboard::Keyboard() {
	for (auto i = 0; i < mLetters.size(); i++) {
		mLetters[i].SetLetter(KeyboardOrder[i]);
		mLetters[i].SetMode(Letter::UpdateMode::Auto);
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
			printf("\n");
			row++;
			if (row >= 1) {
				printf(" ");
			}
			if (row >= 2) {
				//Extra space for third row
				printf(" ");
			}
		}
		mLetters[i].Draw();
		printf(" ");
	}
}

void Keyboard::SetNextGuess(std::string aGuess) {
	for (auto i = 0; i < aGuess.length(); i++) {
		auto letterIndex = getIndex(aGuess[i]);
		mLetters[letterIndex].SetNextGuess(aGuess);
	}
}

void Keyboard::Reset() {
	for (auto i = 0; i < mLetters.size(); i++) {
		mLetters[i].Reset();
	}
}