#pragma once
#include <vector>
#include "Keyboard.hpp"
#include "Row.hpp"

class Board {
public:
	Board();
	void Draw();
	void Reset();
	int GetActiveRow();
	void Update(std::string aGuess);

private:
	std::vector<Row> mAllRows;
	Keyboard mKeyboard;
	int mActiveRow = 0;
};