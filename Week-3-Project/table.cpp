#include<iostream> // header file for inputs and outputs
#include<string> // need to use strings
#include<iomanip> // need for precision and 'set' commands
#include<cmath> // need for math functions

using namespace std; // specify standard namespace

int main() {
	cout << "Enter your first x- and y-values separated by a space: "; // display command

	double x_value_1; // variable for x value 1
	double y_value_1; // variable for y value 1
	cin >> x_value_1 >> y_value_1; // user inputs x-value 1 and y-value 1

	cout << "Enter your second x- and y-values separated by a space: "; // display commannd 

	double x_value_2; // variable for x value 2
	double y_value_2; // variable for y value 2
	cin >> x_value_2 >> y_value_2; // user inputs x-value 2 and y-value 2

	cout << "Enter your third x- and y-values separated by a space: "; // display command

	double x_value_3; // variable for x value 3
	double y_value_3; // variable for y value 3
	cin >> x_value_3 >> y_value_3; // user inputs x-value 3 and y-value 3

	cin.ignore(); // ignore the last entry inputted to allow getline to work

	cout << "Enter your x-label: "; // display command
	string x_label; // string for the inputted x label
	getline(cin, x_label); // user inputs x-label

	cout << "Enter your y-label: "; // display command
	string y_label; // string for the inputted y label
	getline(cin, y_label); // user inputs y-label

	cout << "What level of precision would you like? "; // display question
	int level_of_precision; // variable for inputted level of precision
	cin >> level_of_precision; // user inputs desired level of precision

	cout << x_label << "|" << y_label << '\n'; // display first row of table

	size_t x_label_length = x_label.size(); // length of the x-label
	size_t y_label_length = y_label.size(); // length of the y-label

	int x_label_length_int = static_cast<int>(x_label_length); // convert x label length to int
	int y_label_length_int = static_cast<int>(y_label_length); // convert y label length to int
	int line_in_middle_of_table = 1; // variable for space in the middle of the table

	// calculate number of dashed lines needed for the second row of the table
	int num_of_dashed_lines = x_label_length_int + y_label_length_int + line_in_middle_of_table;

	// create a string for the row of dashed lines
	string dashed_lines(num_of_dashed_lines, '-');

	cout << dashed_lines << '\n'; // display second row of table

	// display x-value for row 3 of the table aligned with x label
	cout << setw(x_label_length_int) << fixed << setprecision(level_of_precision) << x_value_1;

	// display y-value and '|' for row 3 of the table
	cout << "|" << fixed << setprecision(level_of_precision) << y_value_1 << '\n';

	// display x-value for row 4 of the table aligned with x label
	cout << setw(x_label_length_int) << fixed << setprecision(level_of_precision) << x_value_2;

	// display y-value and '|' for row 4 of the table
	cout << "|" << fixed << setprecision(level_of_precision) << y_value_2 << '\n';

	// display x-value for row 5 of the table aligned with x label
	cout << setw(x_label_length_int) << fixed << setprecision(level_of_precision) << x_value_3;

	// display y-value and '|' for row 5 of the table
	cout << "|" << fixed << setprecision(level_of_precision) << y_value_3 << '\n';

	double num_of_values = 3; // create variable for number of x and y values
	double x_bar = (x_value_1 + x_value_2 + x_value_3) / num_of_values; // calculate x(bar)
    double y_bar = (y_value_1 + y_value_2 + y_value_3) / num_of_values; // calculate y(bar)

	// calculate numerator for equation of slope of best fit
	double slope_numerator = (x_bar - x_value_1) * (y_bar - y_value_1) +
		(x_bar - x_value_2) * (y_bar - y_value_2) + (x_bar - x_value_3) * (y_bar - y_value_3);

	int squared = 2; // create variable to square values

	// calculate denominator for equation of slope of best fit
	double slope_denominator = pow((x_value_1 - x_bar), squared) + 
		pow((x_value_2 - x_bar), squared) + pow((x_value_3 - x_bar), squared);

	double slope = slope_numerator / slope_denominator; // calculate slope of best fit

	double y_intercept = y_bar - slope * x_bar; // calculate y-intercept of best fit

	// display line of best fit equation with inputted precision
	cout << "The best fitting equation is: y = " << fixed << setprecision(level_of_precision) 
		<< slope << "x + " << setprecision(level_of_precision) << y_intercept << '\n';

	// calculate numerator of correlation coefficient equation
	double correlation_coefficient_numerator = (x_bar - x_value_1) * (y_bar - y_value_1) +
		(x_bar - x_value_2) * (y_bar - y_value_2) + (x_bar - x_value_3) * (y_bar - y_value_3);

    // calculate sum of squares for x values
    double x_sum_of_squares = pow( (x_value_1 - x_bar), squared ) +
        pow( (x_value_2 - x_bar), squared ) + pow( (x_value_3 - x_bar), squared );
    
    // calculate sum of squares for y values
    double y_sum_of_squares = pow( (y_value_1 - y_bar), squared ) +
        pow( (y_value_2 - y_bar), squared ) + pow( (y_value_3 - y_bar), squared );
    
	// calculate denominator of correlation coefficient equation
	double correlation_coefficient_denominator = sqrt( x_sum_of_squares * y_sum_of_squares );

	// calculate correlation coefficient
	double correlation_coefficient = correlation_coefficient_numerator /
		correlation_coefficient_denominator;

	// display correlation coefficient with inputted precision
	cout << "The correlation coefficient is: " << fixed << setprecision(level_of_precision)
        << correlation_coefficient;

	return 0; // terminate program
}
