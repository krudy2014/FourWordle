#pragma once
#include "Main.hpp"
#include "Letter.hpp"
#include <array>

class Row {
	public:
		void Draw();
		void Update(std::string aGuess);

	private:
		std::array<Letter, MAX_LETTERS> mWord;
};