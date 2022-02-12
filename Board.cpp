#include "Board.hpp"

Board::Board() {
	Reset();
}

int Board::GetActiveRow() {
	return mActiveRow;
}

void Board::Update(std::string aGuess) {
	mAllRows[mActiveRow].Update(aGuess);
	mKeyboard.Update(aGuess);
	mActiveRow++;
}

void Board::Draw() {
	system("CLS");
	for (auto i = 0; i < MAX_ATTEMPTS; i++) {
		mAllRows[i].Draw();
	}
	printf("\n");
	mKeyboard.Draw();
	printf("\n");
}

void Board::Reset() {
	mAllRows.clear();
	mActiveRow = 0;
	//Vector used for mAllRows for future enhancement
	//of being able to use variable length attempts on the fly
	for (auto i = 0; i < MAX_ATTEMPTS; i++) {
		mAllRows.emplace_back(Row());
	}
	mKeyboard.Reset();
}