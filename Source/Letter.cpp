//Copyright 2022, Kelsey Rudy, All Rights Reserved

#include <assert.h>
#include <vector>
#include "Dictionary.hpp"
#include "Letter.hpp"
#include "Main.hpp"

static int GetColor(Letter::State aState) {
	switch (aState) {
	case Letter::State::Undefined:
		return WHITE;
	case Letter::State::Correct:
		return GREEN;
	case Letter::State::WrongSpot:
		return YELLOW;
	case Letter::State::Incorrect:
		return RED;
	default:
		assert(true);
		return 255;
	}
}

void Letter::Reset() {
	SetState(Undefined);
}

void Letter::Draw() {
	Console::SetColor(mColor);
	Console::OutputText(mLetter);
}

void Letter::SetLetter(char aLetter) {
	mLetter = aLetter;
}

void Letter::SetState(State aNewState) {
	mState = aNewState;
	mColor = GetColor(mState);
}

Letter::State Letter::GetState() {
	return mState;
}