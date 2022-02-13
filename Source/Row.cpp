#include "Dictionary.hpp"
#include "Row.hpp"

void Row::Reset() {
	for (auto i = 0; i < mWord.size(); i++) {
		mWord[i].Reset();
		mWord[i].SetLetter('0');
	}
}

void Row::Draw() {
	for (auto i = 0; i < mWord.size(); i++ ) {
		mWord[i].Draw();
		Console::OutputText(" ");
	}
	Console::OutputBlankLine();
}

void Row::SetNextGuess(std::string aGuess) {
	//Count[0] ~ Count['A' - 'A'],
	//Count[1] ~ Count['B' - 'A'], etc.
	int guessedLetterCount[LETTERS_IN_ALPHABET] = { 0 };

	const char* secretWord = Dictionary::GetSecretWord();
	const int* secretLetterCount = Dictionary::GetSecretWordStats();

	for (auto i = 0; i < aGuess.length(); i++) {
		mWord[i].SetLetter(aGuess[i]);

		Letter::State newState = Letter::State::Incorrect;

		if (secretWord[i] == aGuess[i]) {
			newState = Letter::State::Correct;
			guessedLetterCount[aGuess[i] - 'A']++;
		}
		//Special handling for duplicate letters
		//If the secret word is BEEN and the guessed word
		//is (somehow) EBEE, then the third "E" should be green,
		//and only one of the other E's should be yellow (for simplicity,
		//we will choose the first occurence of the letter to be yellow, thus
		//the first "E" will be yellow). This means that we
		//need to keep track of how many characters of a given letter
		//are actually found to be in the correct spot before assigning
		//the state.
		else if ((guessedLetterCount[aGuess[i] - 'A'] + 1) <= secretLetterCount[secretWord[i] - 'A'] &&
			Dictionary::InWord(secretWord, aGuess[i])) {
			newState = Letter::State::WrongSpot;
			guessedLetterCount[aGuess[i] - 'A']++;
		}

		mWord[i].SetState(newState);
	}

	//Duplicate letter in guess clean up.
	//If the word is "TAKE" and the user guessed "EAVE",
	//The last "E" should be green, but the first "E" needs to be Incorrect.
	//We perform this correction by comparing the secret letter count
	//to the guessed letter count and take action if the guessed letters
	//exceeded the secret letter count.
	for (auto i = 0; i < LETTERS_IN_ALPHABET; i++) {
		//Find the first instance of this letter in the guessed word
		//that isn't flagged as correct.
		for (auto j = 0; j < aGuess.length() && guessedLetterCount[i] > secretLetterCount[i]; j++) {
			if (aGuess[j] == i + 'A' &&
				aGuess[j] != secretWord[j]) {
				mWord[j].SetState(Letter::State::Incorrect);
				guessedLetterCount[i]--;
			}
		}
	}
}