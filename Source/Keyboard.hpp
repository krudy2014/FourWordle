#pragma once
#include <array>
#include "Base.hpp"
#include "Letter.hpp"
#include "Main.hpp"

class Keyboard : Base {
	public:
		Keyboard();

		void Reset() override;
		void Draw() override;
		void SetNextGuess(std::string aGuess) override;

	private:
		std::array<Letter, LETTERS_IN_ALPHABET> mLetters;
}; 
