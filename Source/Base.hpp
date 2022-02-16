//Copyright 2022, Kelsey Rudy, All Rights Reserved

#pragma once
#include <string>

class Base {
	public:
		virtual void Reset() = 0;
		virtual void Draw() = 0;
		virtual void SetNextGuess(std::string aGuess) = 0;

	//This class is primarily for demonstration purposes
    //of inheritance. To become more useful, we could
    //for instance, set an x and y variable here that the
    //inherited elements could then easily have access to.
};