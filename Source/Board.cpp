#include "Board.hpp"
#include "Console.hpp"

Board::Board() {
	Reset();
}

int Board::GetActiveRow() {
	return mActiveRow;
}

void Board::SetNextGuess(std::string aGuess) {
	mAllRows[mActiveRow].SetNextGuess(aGuess);
	mKeyboard.SetNextGuess(aGuess);
	mActiveRow++;
}

void Board::Draw() {
	Console::Clear();
	for (auto i = 0; i < MAX_ATTEMPTS; i++) {
		mAllRows[i].Draw();
	}
	Console::OutputBlankLine();
	mKeyboard.Draw();
	Console::OutputBlankLine();
}

void Board::Reset() {
	mAllRows.clear();
	mActiveRow = 0;
	for (auto i = 0; i < MAX_ATTEMPTS; i++) {
		mAllRows.emplace_back(Row());
	}
	mKeyboard.Reset();
}