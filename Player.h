#ifndef _PLAYER_
#define _PLAYER_
#include<string>

/**
* @struct Player is a class to store a player's name and their game statistics.
*/
struct Player {
public:
	/**
	* Constructor creates a Player model.
	* @param _name the player's name
	*/
	Player(const std::string& _name);

	/**
	* This function returns the player's name.
	* @return the player's name
	*/
	std::string getName() const;

	/**
	* This function return the player's best overall score.
	* @return the player's max score
	*/
	int getMaxScore() const;

	/**
	* This function returns true if an inputted score is higher than the
	  player's max score. It also changes the max score to be the inputted 
	  score if true.
	* @param score the new score that is inputted
	* @return true if the inputted score is greater than the max score
	*/
	bool checkRecord(int score);

private:
	std::string name; // the player's name
	int bestScore; // the player's best score
};

#endif
