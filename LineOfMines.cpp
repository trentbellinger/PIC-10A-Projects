#include "LineOfMines.h"

void LineOfMines::placeMines() { // places mines in random positions
    
	std::vector<int> numbers; // create a vector for numbers to be selected
	numbers.resize(lineLength); // make numbers the same size as the board

	// for all numbers between 0 and the size of the board
	for (size_t i = 0; i < lineLength; ++i) {
        size_t one = 1; // variable for 1
		numbers[i] = i + one; // add i + 1 to the vector of numbers
	}

	// for all numbers between 0 and the number of mine locations
	for (size_t j = 0; j < mineLocations.size(); ++j) {

		// random number for the location a mine will be placed
		int place_of_mine = rand() % numbers.size();

		// set the j-th position in mineLocations to be the random number
		mineLocations[j] = numbers[place_of_mine];

		// remove the random number from the numbers vector
		numbers.erase(numbers.begin() + place_of_mine);
	}
}

// sets the number of neighboring mines at each location
void LineOfMines::setCounts() {
	
	size_t one = 1; // variable for 1
	const int location_2 = 2; // variable for location 2
	size_t first_location = 0; // variable for the first location

	// if location 2 contains a mine
	if (containsMine(location_2)) {

		// the first location has 1 neighborng mine
		neighboringMineCounts[first_location] = 1;
	}
	// if the last location contains a mine
	if (containsMine(neighboringMineCounts.size() - one)) {

		// the last location has 1 neighboring mine
		neighboringMineCounts[neighboringMineCounts.size() - one] = 1;
	}

	// for location 2 to the number of locations
	for (size_t i = 2; i < neighboringMineCounts.size(); ++i) {

		// bool for if there is a mine to the left of the location
		bool mine_left = containsMine(i - one);
		// bool for if there is a mine to the right of the location
		bool mine_right = containsMine(i + one);

		// if the location has a mine to the left and to the right
		if (mine_left && mine_right) {

			// the location has 2 neighboring mines
			neighboringMineCounts[i - one] = 2;
		}
		// if the location only has a mine to the left
		else if (mine_left && (mine_right == false)) {

			// the location has 1 neighboring mine
			neighboringMineCounts[i - one] = 1;
		}
		// if the location only has a mine to the right
		else if ((mine_left == false) && mine_right) {

			// the location has 1 neighboring nime
			neighboringMineCounts[i - one] = 1;
		}
	}
}

// returns true if the position contains a mine
bool LineOfMines::containsMine(const int position) const {
	
	// for all numbers between 0 and the number of mine locations
	for (size_t i = 0; i < mineLocations.size(); ++i) {

		// if the mine location is the inputted position
		if (mineLocations[i] == position) {
			return true;
		}
	}
	return false; // there is no mine location for the inputted position
}

/* constructor for the LineOfMines with all member variables and 
vectors initialized */
LineOfMines::LineOfMines(size_t _lineLength, size_t _numberOfMines) : 
	lineLength(_lineLength), numberOfMines(_numberOfMines), score(0), 
	locationDisplays(lineLength, "_____"), neighboringMineCounts(lineLength, 0), 
	mineLocations(numberOfMines, 0), hitMine(false) {
		placeMines(); // place the mines, changing mineLocations
		setCounts(); // set the neighboring mine counts
	}

// display the board
void LineOfMines::display() const {

	// for all numbers between 1 and the length of the line
	for (size_t i = 1; i <= lineLength; ++i) {
		
        std::string numberOfLine; // string for the location
        numberOfLine = std::to_string(i); // set the string to be i
        
        /* display the number with a width of 5 so each number will correspond
         to the correct location */
        std::cout << std::left << std::setw(5) << numberOfLine << ' ';
	}
	std::cout << '\n'; // display indentation

	// for all numbers between 0 and the length of the line
	for (size_t j = 0; j < lineLength; ++j) {

		// display j-th component of the locationDisplays vector
		std::cout << locationDisplays[j] << ' ';
	}
}

// updates board and determines whether a player has hit a mine
void LineOfMines::makeSelection(const int user_position) {

	const int one = 1; // variable for 1

	// if the inputted position contains a mine
	if (containsMine(user_position)) {

		hitMine = true; // change the hitMine bool to true

		// update the display to show the mine (*)
		locationDisplays[user_position - one] = "__*__";
	}
	else { // if the inputted position does not contain a mine

		// get the number of neighboring mines to the position
		int num_neighboring_mines = neighboringMineCounts[user_position - one];

		// change the number of neighboring mines to a string
		std::string neighboring_mines = std::to_string(num_neighboring_mines);

		// create a string to display the number of neighboring mines on the board
		std::string num_mines_display = "__" + neighboring_mines + "__";

		// set the location in the display to contain the neighboring mines
		locationDisplays[user_position - one] = num_mines_display;

		// add 1 to the user's score for a correct guess
		score += 1;
	}
}

// get the user's score
int LineOfMines::getScore() {

	if (hitMine) { // if the user hit a mine
		score = 0; // set the score to 0
	}

	return score;
}

// returns true if the user hit a mine, false if they did not
bool LineOfMines::hasHitMine() const { return hitMine; }

// reveals the current board with all mine locations
void LineOfMines::grandReveal() {
	size_t one = 1; // variable for 1

	// for all numbers between 1 and the length of the board + 1
	for (size_t i = 1; i <= (locationDisplays.size() + one); ++i) {

		if (containsMine(i)) { // if the location contains a mine

			// change the display to contain a *
			locationDisplays[i - one] = "__*__";
		}
	}
	display(); // display the final board
}
