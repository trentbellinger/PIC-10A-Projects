#include "Player.h"
#include "LineOfMines.h"

using namespace std;

int main() {
	// the game is explained
	cout << "This is a game of Linesweeper: mines are arranged on a line. \n";
	cout << "You select a position to reveal what is there. \n";
	cout << "For every safe location you reveal, you get +1 point. \n";
	cout << "If you reveal a mine, you get a score of 0. \n";
	cout << "A given location may have a mine to either its left, right, both, or neither. \n";
	cout << "The number of neighbouring mines of a revealed location 0/1/2 is displayed. \n";
	cout << "You can continue playing until you either hit a mine or choose not to reveal any more locations." << '\n';
	
	srand(time(nullptr)); // seed for random numers

	cout << "What is your name? "; // display question
	string player_name; // string for the player's inputted name
	getline(cin, player_name); // player inputs name

	// set the player constructor using the player's name
	Player player(player_name);

	cout << "How long do you want the line? "; // display question
	size_t lineLength; // variable for the length of the line
	cin >> lineLength; // player inputs desired line length

	cout << "How many mines do you want on the line? "; // display question
	size_t numberOfMines; // variable for the number of mines
	cin >> numberOfMines; // player inputs desired number of mines

	bool moreGames = true; // bool for if the user wants more games
	while (moreGames) { // while the user wants to play more games

		// set the LineOfMines constructor using the line length and # of mines
		LineOfMines game(lineLength, numberOfMines);

		game.display(); // display the empty game board
		cout << '\n'; // display indentation after game board display

		bool moreRounds = true; // bool for if the user wants more rounds
		while (moreRounds) { // while the user wants to play more rounds
			
			// display question
			cout << "What position would you like to reveal? ";
			int user_position; // variable for the player's inputted position
			cin >> user_position; // user inputs desired position

			// input the user's position to update the game board
			game.makeSelection(user_position);

			if (game.hasHitMine()) { // if the user chose a position with a mine
				break; // exit the while loop
			}

			game.display(); // display the new game board
			cout << '\n'; // display indentation after game board

			// display question
			cout << "Would you like to reveal anther position? [y/n] ";
			char roundYesNo = ' '; // char for the user's input
			cin >> roundYesNo; // user inputs y (yes) or n (no)

			if (roundYesNo == 'n') { // if the user inputs n (no)
				moreRounds = false; // end the while loop and display no more rounds
			}
		}

		cout << "The mine positions are now revealed:\n"; // display message
		game.grandReveal(); // reveal the ending game board with mines exposed
		cout << '\n'; // display indentation

		// if the player has a new high score
		if (player.checkRecord(game.getScore())) {

			// display new high score message
			cout << "You have a new high score of " << player.getMaxScore() 
				<< "!\n";
		}
		else { // if the player does not have a new high score

			// display message containing old high score
			cout << "You scored " << game.getScore() 
				<< ", but your best score is still " << player.getMaxScore() 
				<< ".\n";
		}

		// display question
		cout << "Would you like to play another game? [y/n] ";
		char gameYesNo = ' '; // char for user's input
		cin >> gameYesNo; // user inputs y (yes) or n (no)

		if (gameYesNo == 'n') { // if the user input n (no)
			moreGames = false; // end the while loop and display no more games
		}
	}

	// display ending message with player name and final score
	cout << '\n' << player.getName() << ", your top score was " 
		<< player.getMaxScore();

	return 0;
}
