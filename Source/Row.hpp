//Copyright 2022, Kelsey Rudy, All Rights Reserved

#pragma once
#include <array>
#include "Base.hpp"
#include "Letter.hpp"
#include "Main.hpp"

class Row : Base {
	public:
		void Reset() override;
		void Draw() override;
		void SetNextGuess(std::string aGuess) override;

	private:
		std::array<Letter, MAX_LETTERS> mWord;
};