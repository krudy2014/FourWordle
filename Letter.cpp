#include <assert.h>
#include <vector>
#include "Dictionary.hpp"
#include "Letter.hpp"
#include "Main.hpp"

static int GetColor(Letter::State aState) {
	switch (aState) {
	case Letter::State::Undefined:
		return WHITE;
	case Letter::State::Correct:
		return GREEN;
	case Letter::State::WrongSpot:
		return YELLOW;
	case Letter::State::Incorrect:
		return RED;
	default:
		assert(true);
		return 255;
	}
}

void Letter::Draw() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, mColor);
	printf("%c", mLetter);
}

void Letter::SetLetter(char aLetter, int aIndex) {
	mLetter = aLetter;
	if (aIndex != -1) {
		mIndex = aIndex;
	}
}

void Letter::SetMode(UpdateMode aMode) {
	mMode = aMode;
}

//TODO: does this function really belong here?
//This is incorrect for if someone guesses "DDDS" for "ADDS"...
//the first letter is erroneously set to yellow since it thinks
//it's in the word somewhere
void Letter::Update(std::string aGuess) {
	const char* secretWord = Dictionary::GetSecretWord();

	if (mMode == Auto && mState == Correct) {
		//If this is already set to Correct and we're in
		//auto mode, don't set it to anything else
		return;
	}

	SetState(Incorrect);
	if (mIndex != -1) {
		//We only care about a single index, so just check the one stored
		if (secretWord[mIndex] == mLetter) {
			SetState(Correct);
			return;
		}
	}
	else {
		//TODO This is probably more complicated than it needs to be
		//We want to check all indices.
		//Get indices into the aGuess that match the mLetter
		std::vector<int> indices;
		for (auto i = 0; i < aGuess.size(); i++) {
			if (aGuess[i] == mLetter) {
				indices.emplace_back(i);
			}
		}

		//For each index, check if the secret word has it
		for (auto j = 0; j < indices.size(); j++) {
			if (secretWord[indices[j]] == mLetter) {
				SetState(Correct);

				//If at least one match
				if (mMode == Auto) {
					return;
				}
			}
		}
	}

	//TODO: still need to handle double letters
	for (auto k = 0; k < strlen(secretWord); k++) {
		if (secretWord[k] == mLetter) {
			SetState(WrongSpot);
			return;
		}
	}
}

void Letter::Reset() {
	SetState(Undefined);
}

void Letter::SetState(State aNewState) {
	mState = aNewState;
	mColor = GetColor(mState);
}