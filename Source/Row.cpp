#include "Dictionary.hpp"
#include "Row.hpp"

void Row::Reset() {
	//Currently an unused function
	for (auto i = 0; i < mWord.size(); i++) {
		mWord[i].Reset();
		mWord[i].SetLetter('0');
	}
}

void Row::Draw() {
	for (auto i = 0; i < mWord.size(); i++ ) {
		mWord[i].Draw();
		printf(" ");
	}
	printf("\n");
}

void Row::SetNextGuess(std::string aGuess) {
	for (auto i = 0; i < aGuess.length(); i++) {
		mWord[i].SetLetter(aGuess[i], i);
		mWord[i].SetNextGuess(aGuess);
	}
}