#include<iostream> // header file for inputs and outputs

using namespace std; // specify standard namespace

int main() {
	cout << "Enter true cost.\n"; // display command

	cout << "Give the dollars: "; // display command
    int item_cost_dollars; // create variable for item cost in dollars
	cin >> item_cost_dollars; // user inputs the item cost in dollars

	cout << "Now give the cents: "; // display command
    int item_cost_cents; // create variable for item cost in cents
	cin >> item_cost_cents; // user inputs the item cost in cents

	int cents_per_dollar = 100; // create variable to convert from dollars to cents
    
	// calculate total item cost in cents
	int item_cost = item_cost_dollars * cents_per_dollar + item_cost_cents;

	// convert item cost in cents to a double for calculations
    double item_cost_in_cents = static_cast<double>(item_cost);

    int cents_per_nickel = 5; // create variable to convert from cents to number of nickels
    
	// calculate total item cost in number of nickels
	double item_cost_in_nickels = item_cost_in_cents / cents_per_nickel;

	// round the item cost in nickels to the nearest nickel
	double item_cost_in_nickels_rounded = static_cast<int>(item_cost_in_nickels + 0.5);

	// calculate item cost rounded to the nearest 5 cents
	double item_cost_rounded = item_cost_in_nickels_rounded * cents_per_nickel / cents_per_dollar;

    // display item cost in dollars rounded to the nearest 5 cents
	cout << "In cash, the item costs: $" << item_cost_rounded << ".\n";

	cout << "Enter payment details.\n"; // display command
    
	cout << "Number of toonies: "; // display command
    int num_of_toonies; // create variable for number of toonies
	cin >> num_of_toonies; // user inputs number of toonies used

	cout << "Number of loonies: "; // display command
    int num_of_loonies; // create variable for number of loonies
	cin >> num_of_loonies; // user inputs number of loonies used

	cout << "Number of fifty cent pieces: "; // display command
    int num_of_50_cent_pieces; // create variable for number of 50 cent pieces
	cin >> num_of_50_cent_pieces; // user inputs number of 50 cent pieces used

	cout << "Number of quarters: "; // display command
    int num_of_quarters; // create variable for number of quarters
	cin >> num_of_quarters; // user inputs number of quarters used

	cout << "Number of dimes: "; // display command
    int num_of_dimes; // create variable for number of dimes
	cin >> num_of_dimes; // user inputs number of dimes used

	cout << "Number of nickels: "; // display command
    int num_of_nickels; // create variable for number of nickels
	cin >> num_of_nickels; // user inputs number of nickels used

	int cents_per_toonie = 200; // create variable for the number of cents per toonie
    int cents_per_loonie = 100; // create variable for the number of cents per loonie
    int cents_per_50_cent_piece = 50; // create variable for the number of cents per 50 cent piece
    int cents_per_quarter = 25; // create variable for the number of cents per quarter
    int cents_per_dime = 10; // create variable for the number of cents per dime

	// calculate the total amount paid in cents
	int total_payment = num_of_toonies * cents_per_toonie + num_of_loonies * cents_per_loonie
		+ num_of_50_cent_pieces * cents_per_50_cent_piece + num_of_quarters * cents_per_quarter
		+ num_of_dimes * cents_per_dime + num_of_nickels * cents_per_nickel;

	// calculate total amount paid in dollars
	int total_payment_dollars = total_payment / cents_per_dollar;

	// calculate total amount paid in cents
	int total_payment_cents = total_payment % cents_per_dollar; 

	// display total amount paid in dollars and cents
	cout << "You paid: " << total_payment_dollars << " dollar(s) and "
		<< total_payment_cents << " cent(s).\n";

	// calculate rounded item cost in cents
	double item_cost_rounded_in_cents_dbl = item_cost_rounded * cents_per_dollar;
    
    // convert variable for item cost rounded in cents into type int for calculations
    int item_cost_rounded_in_cents = static_cast<int>(item_cost_rounded_in_cents_dbl);

	// calculate change due in cents
	int total_change_due = total_payment - item_cost_rounded_in_cents;

	// calculate the amount of dollars due
	int change_due_dollars = total_change_due / cents_per_dollar;

	// calculate the amount of cents due
	int change_due_cents = total_change_due % cents_per_dollar;
    
	// display change due in dollars and cents and closing message
	cout << "Your change due is: " << change_due_dollars << " dollar(s) and "
		<< change_due_cents << " cent(s). Have a nice day, eh!";

	return 0; // terminate program
}
