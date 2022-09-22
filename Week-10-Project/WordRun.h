#ifndef _WORDRUN_
#define _WORDRUN_

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<ctime>
#include<algorithm>

/**
* @class WordRun creates the framework for a wordle game that can be played by 
  the user
*/
class WordRun {
private:
	std::set<std::string> words; // set of all possible words
	std::string chosen; // the secret word
	std::vector<char> chars; // the characters of the chosen word
	int guesses; // the number of guesses made
	std::time_t start, duration; // the start time and duration of play
	bool won; // whether the user has guessed the word
	int score; // the user's score

	/**
	* This function stores all possible 4-letter words.
	*/
	void setWords();

	/**
	* This function chooses a random 4-letter word and sets its characters.
	*/
	void chooseWord();

	/**
	* This function calculates the user's score after they complete the game.
	*/
	void setScore();

public:
	/**
	* This constructor creates the main framework for the WordRun game, 
	  initializing all member variables.
	*/
	WordRun();

	/**
	* This function takes in the user's guess and determines whether or not the
	  guess is valid and then gives hints to the user.
	* @param user_guess the user's guess of a word
	*/
	void guess(const std::string& user_guess);

	/**
	* This function returns true if the player won the game, and false otherwise.
	* @return true of the game has been won
	*/
	bool hasWon() const;

	/**
	* This function returns the number of guesses made by the user when they 
	  win the game or -1 if the user has not won yet.
	* @return the number of guesses
	*/
	int getGuesses() const;

	/**
	* This function returns the number of seconds the user took to win the game,
	  or -1 if the game has not been won yet.
	* @return the amount of time taken
	*/
	time_t getTime();

	/**
	* This function returns the user's overall score after they win the game, or
	  -1 if the game has not been won yet.
	* @return the user's score
	*/
	int getScore() const;

};

#endif
