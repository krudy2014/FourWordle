//Copyright 2022, Kelsey Rudy, All Rights Reserved
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
		//Vector used for mAllRows for future enhancement
		//of being able to use variable length attempts on the fly
		std::vector<Row> mAllRows;
		Keyboard mKeyboard;
		int mActiveRow = 0;
};