#include "HomeworkList.h" // need to use functions within the h file

#include<iostream> // header file for inputs and outputs
#include<string> // need to include to use strings
#include<iomanip> // need to include for rounding

using namespace std; // specify standard namespace

int main() {
	cout << "Enter student's name: "; // display command
	string student_name; // string variable for student's name
	getline(cin, student_name); // user enters student's name

	HomeworkList hw; // create a HomeworkList class

	bool more = true; // create a bool for while loop
	
	while (more) { // while user is inputting scores
		cout << "Enter score and max as two values: "; // display command
		int score, maxPossible; // variables for score and max possible points
		cin >> score >> maxPossible; // user inputs score and max possible points

		hw.addScore(score, maxPossible); // add inputted score to list of scores

		cout << "More scores? y/n: "; // ask user if they have more scores to input
		char yesNo = ' '; // create a char for yes or no
		cin >> yesNo; // user inputs y (yes) or n (no)

		if (yesNo == 'n') { // if the user inputs n (no)
			more = false; // end the while loop
		} // if the user does not enter n (no), then the while loop will continue
	}

    // display question
	cout << "How many scores should be used in computing the HW grade? ";
    size_t topNumber = 0; // create variable for number of grades used
	cin >> topNumber; // user inputs number of scores they want used

	size_t num_homeworks = hw.numberOfHWs(); // variable for number of scores stored

    // variable for overall homework percentage using only wanted scores
	double percentage = hw.percentageFromBest(topNumber);

    const int level_of_precision = 2; // variable for preision level
    
    // display message about the student's overall homework grade
	cout << "The homework grade for " << student_name << " based on the best "
        << topNumber << " homework scores out of " << num_homeworks << " is "
        << fixed << setprecision(level_of_precision) << percentage << "%.\n";
    
    // create variables for the thresholds of the four different messages
    const int excellent_min = 95, good_min = 80, decent_min = 70;
    
    // if overall score is greater than or equal to 95
	if ( percentage >= excellent_min) {
		cout << "This is excellent."; // display message
	}
    // if overall score is between 80 and 95
	else if ( percentage >= good_min) {
		cout << "This is good."; // display message
	}
    // if overall score is between 70 and 80
	else if ( percentage >= decent_min) {
		cout << "This is decent."; // display message
	}
	else { // if overall score is below 70
		cout << "This is poor."; // display message
	}

	return 0; // terminate program
 }
