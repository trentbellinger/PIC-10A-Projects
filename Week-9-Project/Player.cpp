#include "Player.h"

// Player constructor with member variables initialized
Player::Player(const std::string& _name) : name(_name), bestScore(0) {}

// returns the player's name
std::string Player::getName() const { return name; }

// returns the player's max score
int Player::getMaxScore() const { return bestScore; }

// returns true and changes max score if the inputted score > max score
bool Player::checkRecord(int score) {

	if (score > bestScore) { // if the inputted score is greater than best score
		bestScore = score; // change the best score to be the inputted score
		return true;
	}
	else { // if the inputted score is not greater than the best score
		return false;
	}
}
