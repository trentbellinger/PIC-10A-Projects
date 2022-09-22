#include "WordRun.h"

using namespace std;

int main() {

	cout << "Enter your name: "; // display command
	string user_name; // string for the user's name
	getline(cin, user_name); // user enters their name
	
	ifstream iname(user_name + ".txt"); // open the user's file of scores

	if (iname.fail()) { // if there is no such file
		cout << "You have not played before.\n"; // display message
	}
	else { // if the user already has a file
		int max = 0; // value for the user's max score

		while (!iname.eof()) { // for all numbers in the file

			int current_score; // the current score under consideration
			iname >> current_score; // get the score from the file

			if (current_score > max) { // if the score is greater than max
				max = current_score; // set the max to be the score
			}
		}
		// display user's best score
		cout << "Your best score is " << max << ".\n";
	}
	iname.close(); // close the file
	
	cout << "Would you like to play? y/n:"; // display question
	char yesNo; // char for y(yes) or n (no)
	cin >> yesNo; // user enters y (yes) or n (no)

	if (yesNo == 'n') { // if the user enters n (no)
		cout << "goodbye"; // display goodbye
	}
	else { // if the user enters y (yes)
		// display game instructions
		cout << "Try to guess a 4-letter word. Letters in their rightful place "
			<< "get a '*'. Letters of the word not in their place get a '~'. "
			<< "Otherwise, a '-' is displayed.\n";

		cin.ignore(); // allow for getline to be used again later

		WordRun game; // begin the game

		bool moreTries = true; // bool for if the user gets more tries
		while (moreTries) { // while the user gets more guesses

			string user_guess; // string for the user's guess
			getline(cin, user_guess); // user inputs their guess

			// input the user's guess into the game
			game.guess(user_guess);

			if (game.hasWon()) { // if the user's guess is correct
				moreTries = false; // end the while loop

				/* display message to the user with their number of 
				guesses, time spent, and score */
				cout << "You won and responded in " << game.getGuesses() <<
					" guesses, with a time of " << game.getTime() <<
					"s, earning a score of " << game.getScore() << ".";

				// open the user's file of scores
				ofstream oname(user_name + ".txt", ios_base::app);
				// put the new score into the file
				oname << game.getScore() << '\n';
				oname.close(); // close the file
			}
		}
	}

	return 0;
}
