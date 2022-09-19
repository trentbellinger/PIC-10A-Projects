#include "WordRun.h"

// stores all 4-letter words
void WordRun::setWords() {
	std::ifstream wordsIn("word4.txt"); // open the file of all 4-letter words
	std::string word; // create a string for a 4-letter word

	if (!wordsIn.fail()) { // if the file stream is valid

		while (!wordsIn.eof()) { // while we are still in the file
			getline(wordsIn, word); // get one word from the file
			words.insert(word); // store the word in the set of words
		}
	}
	wordsIn.close(); // close the file
}

// chooses a random word and stores its characters
void WordRun::chooseWord() {
	srand(time(nullptr)); // seed the random number generator

	// get a random number from 0 to the total number of words
	int randomWordNumber = rand() % words.size();

	auto words_itr = words.begin(); // iterator to get a word from the set

	// for every number from 0 to the random number
	for (int i = 0; i <= randomWordNumber; ++i) {
		++words_itr; // increase the iterator by 1
	}
	chosen = *words_itr; // set the chosen word to be the word the iterator points to

	for (size_t j = 0; j < chosen.size(); ++j) { // for every number between 0 and 4
		// set the numbers of the random word into the chars vector
		chars[j] = chosen[j];
	}
}

// calculate the user's score
void WordRun::setScore() {
	int maxPossible = 150; // variable for highest possible score
	int leastPossible = 0; // variable for lowest possible score

	// set the time score to be the max of 0 and 150 - total seconds taken		
	int timeScore = std::max(leastPossible, maxPossible - 
		static_cast<int>(getTime()));

	// set the guess score to be the max of 0 and 150 - total # of guesses
	int guessScore = std::max(leastPossible, maxPossible - getGuesses());

	// set the total score to be time score + guess score
	score = timeScore + guessScore;
}

// constructor for the WordRun game with all member variables initialized
WordRun::WordRun() : words({}), chosen(""), chars(4, ' '), guesses(0),
	start(time(nullptr)), duration(0), won(false), score(0) {
	setWords(); // put all 4-letter words in the words set
	chooseWord(); // put a random word in chosen and set the chars vector
}

// handles a user's guess
void WordRun::guess(const std::string& user_guess) {
	guesses += 1; // increase the number of guesses by 1

	if (user_guess.size() != chosen.size()) { // if the word is not 4 letters
		std::cout << "wrong size" << '\n'; // display message
	}
	// if the inputted word is not in the list of 4-letter words
	else if (words.find(user_guess) == words.end()) {
		std::cout << "word not among possible words" << '\n'; // display message
	}
	else { // if the inputted word is valid

		std::string hints; // create a string for the hints 
		hints.resize(chosen.size()); // set the hints string to be length 4

		// for every number between 0 and the size of hints
		for (size_t i = 0; i < hints.size(); ++i) {

			// if the user's letter exactly matches the chosen word's letter
			if (user_guess[i] == chosen[i]) {
				hints[i] = '*'; // set the character in hints to *
			}
			else { // if the user's letter does not exactly match the chosen word

				// for every number between 0 and the size of hints
				for (size_t j = 0; j < hints.size(); ++j) {

					/* if the user's letter is in the chosen word, but in the 
					wrong place */
					if (user_guess[i] == chosen[j]) {
						hints[i] = '~'; // set the character in hints to ~
						break; // exit the for loop
					}
					else { // if the user's letter is not in the chosen word
						hints[i] = '-'; // set the character in hints to -
					}
				}
			}
		}
		std::cout << hints << '\n'; // display hints

		if (user_guess == chosen) { // if the user's guess is the chosen word
			won = true; // set the bool for won to true
			setScore(); // set the user's score
		}
	}
}

// returns whether the user has won
bool WordRun::hasWon() const {
	return won;
}

// returns the number of guesses taken
int WordRun::getGuesses() const {
	if (hasWon()) { // if the user has won
		return guesses; // return the number of guesses taken
	}
	else { // if the user has not won
		return -1;
	}
}

// gets the amount of time take by the user
time_t WordRun::getTime() {
	if (hasWon()) { // if the user has won

		// set duration to be the current time - the time when the game started
		duration = time(nullptr) - start; 
		return duration;
	}
	else { // if the user has not won
		return -1;
	}
}

// get the user's score
int WordRun::getScore() const {
	if (hasWon()) { // if the user has won
		return score; // return the overall score
	}
	else { // if the user has not won
		return -1;
	}
}
