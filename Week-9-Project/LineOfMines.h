#ifndef _LINEOFMINES_
#define _LINEOFMINES_
#include<vector>
#include<string>
#include<iomanip>
#include<iostream>

class LineOfMines {
private:
	size_t lineLength; // the length of the line of mines
	size_t numberOfMines; // the number of mines
	int score; // the player's score

	// how each location should be displayed
	std::vector<std::string> locationDisplays;
	// the number of mines adjacent to each location
	std::vector<int> neighboringMineCounts;
	// the location of each mine
	std::vector<int> mineLocations;

	// whether or not a mine has been hit by the player
	bool hitMine;

	/**
	* This function places a certain number of mines in random distinct
	  locations in the field of mines.
	*/
	void placeMines();

	/**
	* This function sets the amount of neighboring mines at each location
	  according to where the mines are placed.
	*/
	void setCounts();

	/**
	* This function returns true if a user's inputted position contains a mine.
	* @param position the position inputted by the user
	* @return true is the position contains a mine, and false otherwise
	*/
	bool containsMine(const int position) const;

public:
	/**
	* Constructor creates the main framework for the linesweeper game,
	  accepting two inputs from the player.
	* @param _lineLength the number of locations in the game
	* @param _numberOfMines the number of mines in the game
	*/
	LineOfMines(size_t _lineLength, size_t _numberOfMines);

	/**
	* This function displays the game board in its current state.
	*/
	void display() const;

	/**
	* This function updates the board and determines whether or not a player
	  has hit a mine when their desired position is inputted.
	* @param user_position the position from the player
	*/
	void makeSelection(const int user_position);

	/**
	* This function returns the player's score, updating it if a mine is hit.
	* @return the player's current score
	*/
	int getScore();

	/**
	* This function returns whether or not a mine has been nit by the user.
	* @return true if a mine has been hit, otherwise false
	*/
	bool hasHitMine() const;

	/**
	* This function modifies the board so that it displays all mine locations,
	  and then displays the board.
	*/
	void grandReveal();

};

#endif
