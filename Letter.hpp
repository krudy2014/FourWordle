#pragma once
#include <string>

#define WHITE (7)
#define GREEN (2)
#define YELLOW (6)
#define RED (4)

class Letter {
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

		void Draw();
		void SetLetter(char aLetter, int aIndex = -1);
		void SetMode(UpdateMode aMode);
		void Update(std::string aGuess);
		void Reset();

	private:
		void SetState(State aNewState);

		char mLetter = '0';
		State mState = Undefined;
		int mColor = WHITE;
		UpdateMode mMode = Manual;
		int mIndex = -1;
};