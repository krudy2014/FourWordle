#pragma once
#include <vector>
#include "Base.hpp"
#include "Keyboard.hpp"
#include "Row.hpp"

class Board : Base {
	public:
		Board();
		
		void Reset() override;
		void Draw() override;
		void SetNextGuess(std::string aGuess) override;

		int GetActiveRow();

	private:
		std::vector<Row> mAllRows;
		Keyboard mKeyboard;
		int mActiveRow = 0;
};