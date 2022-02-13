#pragma once
#include "Console.hpp"

class Letter {
	public:
		enum State {
			Undefined, //White
			Correct,   //Green
			WrongSpot, //Yellow
			Incorrect  //Red
		};
		
		void Reset();
		void Draw();

		void SetLetter(char aLetter);
		void SetState(State aNewState);

		State GetState();

	private:
		char mLetter = '0';
		State mState = Undefined;
		int mColor = WHITE;
};