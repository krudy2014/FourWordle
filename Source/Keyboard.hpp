#pragma once
#include <array>
#include "Base.hpp"
#include "Letter.hpp"
//Copyright 2022, Kelsey Rudy, All Rights Reserved

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
