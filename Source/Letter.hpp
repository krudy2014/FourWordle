#pragma once
#include "Base.hpp"
#include "Console.hpp"

class Letter : Base{
	public:
		enum State {
			Undefined, //White
			Correct,   //Green
			WrongSpot, //Yellow
			Incorrect  //Red
		};

		enum UpdateMode {
			Manual,
			Auto //Once letter is set to green, won't go back to yellow
		};

		void Reset() override;
		void Draw() override;
		void SetNextGuess(std::string aGuess) override;

		void SetLetter(char aLetter, int aIndex = -1);
		void SetMode(UpdateMode aMode);

	private:
		void SetState(State aNewState);

		char mLetter = '0';
		State mState = Undefined;
		int mColor = WHITE;
		UpdateMode mMode = Manual;
		int mIndex = -1;
};