#pragma once
#include <array>
#include "Base.hpp"
#include "Main.hpp"
#include "Letter.hpp"

class Row : Base {
	public:
		void Reset() override;
		void Draw() override;
		void SetNextGuess(std::string aGuess) override;

	private:
		std::array<Letter, MAX_LETTERS> mWord;
};