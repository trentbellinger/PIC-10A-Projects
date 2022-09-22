#include "CI.h"

// returns a string with all lowercase letters
const std::string make_lower(const std::string& input_string) {
	// make a copy of the inputted string
	std::string input_copy = input_string;

	// for every number fromm 0 to the size of the string
	for (size_t i = 0; i < input_copy.size(); ++i) {
		// create c as the i-th char of the string
		char& c = input_copy[i];

		if ((c >= 'A') && (c <= 'Z')) { // if c is a capital letter
			c = c + ('a' - 'A'); // make c into a lowercase letter
		}
	}
	// return the new string with only lowercase letters
	return input_copy;
}

/* constructor for CI_String with member variable str initialized by
  calling the make_lower function*/
CI_String::CI_String(const std::string& user_string) : 
	str(make_lower(user_string)) {}

// returns the member variable str
std::string CI_String::get_string() const { return str; }

// returns the size of str
size_t CI_String::size() const { return str.size(); }

// returns whether or not ci_string1 < ci_string2
bool operator<(const CI_String& ci_string1, const CI_String& ci_string2) {

	// return the lexicographic comparison using < between the 2 strings
	return ci_string1.get_string() < ci_string2.get_string();
}

// allows the user to print CI_String objects
std::ostream& operator<<(std::ostream& ci_string_out, 
	const CI_String& ci_string) {
	// display the member variable str in the CI_String class
	ci_string_out << ci_string.get_string();
	return ci_string_out;
}

// returns the total number of characters in a file
size_t total_chars(const std::string & file_name) {
	size_t size_of_file = 0; // set the size of the file to 0

	// create an input file stream using the file
	std::ifstream ifs(file_name);

	if (ifs.fail()) { // if the stream fails
		ifs.close(); // close the file
		return 0; // return a size of 0
	}
	else { // if the stream does not fail
		// while there are still characters in the file
		while (ifs.get() != EOF) {
			++size_of_file; // add 1 to the size of the file
		}
	}
	ifs.close(); // close the file
	return size_of_file; // return the size
}

// retrns a set of the unique words in a file
std::set<CI_String> unique_words(const std::string& file_name) {
	// create the set for the unique words
	std::set<CI_String> result{};

	// create an input file stream using the file
	std::ifstream ifs(file_name);

	if (ifs.fail()) { // if the stream fails
		ifs.close(); // close the file
		return result; // return an empty set
	}
	else { // if the stream does not fail
		// while there are still characters in the file
		while (!ifs.eof()) {

			std::string current; // string for the current word
			ifs >> current; // get the current word

			// create a CI_String object using the current word
			CI_String cur(current);
			result.insert(cur); // insert the string into the set
		}
	}
	ifs.close(); // close the file
	return result; // return the set of CI_Strings
}

// returns a vector with the number of unique words per line
std::vector<size_t> uniques_per_line(const std::string& file_name) {
	// create a vector to store the lines of the file
	std::vector<std::string> lines(0);
	
	// create an input file stream using the file
	std::ifstream ifs(file_name);
	if (ifs.fail()) { // if the file name is not valid
		return {}; // return an empty vector
	}
	else { // if the file name is valid
		while (!ifs.eof()) { // while not at the end of the file

			// string for the current line
			std::string current_line_str;
			// get the current line of the file
			getline(ifs, current_line_str);
			// store the current line of the file in the vector
			lines.push_back(current_line_str);
		}
	}
	// create a vector for the size of each line
	std::vector<size_t> result(lines.size(), 0);

	// for every number from 0 to the size of the vector of the lines
	for (size_t i = 0; i < lines.size(); ++i) {

		// create a set for the words in each line
		std::set<CI_String> words_in_line;
		// create an input string stream using the current line
		std::istringstream iss(lines[i]);
		std::string word; // string for the current word

		// while words are being outputted from the line
		while (iss >> word) {

			// create a CI_String object using the current word
			CI_String w(word);
			// if the current word is not already in the set
			if (words_in_line.find(w) == end(words_in_line)) {
				words_in_line.insert(w); // add the word to the set

				/* in the result vector, add 1 to the location that
				coresponds to the current line */
				result[i] += 1;
			}
		}
	}
	
	return result; // return the result vector
}

// prints each unique word from line 1 of a file with its multiplicity
void print_line_one_info(const std::string& file_name) {

	// create an input file stream using the file
	std::ifstream ifs(file_name);
	std::string line; // string for the first line

	if (!ifs.fail()) { // if the file is valid
		getline(ifs, line); // get the first line of the file
		ifs.close(); // close the file
	}
	
	// create an input string stream using the first line
	std::istringstream iss(line);

	// create a map for words in the line and their multiplicity
	std::map <CI_String, size_t> words;
	// create a string for the current word
	std::string word_in_line;

	// while there are still words in the line
	while (iss >> word_in_line) {

		// create a CI_String object using the current word
		CI_String w(word_in_line);
		// if the current word is not already in the map
		if (words.find(word_in_line) == end(words)) {
			words[word_in_line] = 1; // add the word and map it to 1
		}
		else { // if the word is in the map
			words[word_in_line] += 1; // add 1 to the mapped value
		}
	}

	// for every word/multiplicity pair in the map
	for (const auto& m : words) {
		if (m.second == 1) { // if the word appears once

			// display word and number of times it appears
			std::cout << m.first << " occurs " << m.second 
				<< " time." << '\n';
		}
		else { // if the word appears more than once

			// display word and number of times it appears
			std::cout << m.first << " occurs " << m.second 
				<< " times. " << '\n';
		}
	}
}
