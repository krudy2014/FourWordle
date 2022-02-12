#include "Dictionary.hpp"
#include "Row.hpp"

void Row::Draw() {
	for (auto i = 0; i < mWord.size(); i++ ) {
		mWord[i].Draw();
		printf(" ");
	}
	printf("\n");
}

void Row::Update(std::string aGuess) {
	for (auto i = 0; i < aGuess.length(); i++) {
		mWord[i].SetLetter(aGuess[i], i);
		mWord[i].Update(aGuess);
	}
}