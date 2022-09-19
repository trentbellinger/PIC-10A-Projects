#ifndef _CI_
#define _CI_

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<set>
#include<vector>
#include<map>

/**
* This function takes in a string as an input and returns a string 
  with all the letters lowercase.
* @param input_string the string to convert to all lowercase
* @return a string with all the letters lowercased
*/
const std::string make_lower(const std::string& input_string);

/**
* @class CI_String is a class that stores a string with all its 
  letter lowercase.
*/
class CI_String {
private:
	std::string str; // stores a string of all lowercase letters

public:
	/**
	* Constructor creates the main framework for the CI_String 
	  class, taking in a string from the user.
	* @param user_string the inputted string
	*/
	CI_String(const std::string& user_string);

	/**
	* This member function returns the user's inputted string with
	  all lowercase.
	* @return the str member variable, which stores the inputted 
	  string with only lowercase
	*/
	std::string get_string() const;

	/**
	* This member function returns the size of the user's inputted 
	  string with only lowercase.
	* @return the size of the string with only lowercase
	*/
	size_t size() const;
};

/**
* Operator compares two CI_String objects to determine if the first 
  inputted object is less than the second inputted object.
* @param ci_string1 the first CI_String object
* @param ci_string2 the second CI_String object
* @return whether ci_string1 is less than ci_string2 based on a 
  lexicographical comparison
*/
bool operator<(const CI_String& string1, const CI_String& string2);

/**
* Operator allows a CI_String object to be printed to the console.
* @param ci_string_out the operator 
* @param ci_string the CI_String object to be printed
* @return ci_string_out the operator that allows CI_String to be 
  printed
*/
std::ostream& operator<<(std::ostream& si_string_out, 
	const CI_String& ci_string);

/**
* This function determines the number of characters that are contained
  within an inputted file.
* @param file_name the name of the file to be read
* @return the number of characters in the file
*/
size_t total_chars(const std::string& file_name);

/**
* This function gives a set of all the unique CI_String ojects 
  within a specified file.
* @param file_name the name of the file to be read
* @return a set containing all of the unique words in the file
*/
std::set<CI_String> unique_words(const std::string& file_name);

/**
* This function determines the number of unique words in each line 
  within a specified file.
* @param file_name the name of the file to be read
* @return a vector containing the number of unique words in each 
  line of the file
*/
std::vector<size_t> uniques_per_line(const std::string& file_name);

/**
* This function prints the each unique word in line 1 of a specified 
  file and prints the multiplicity of each word.
* @param file_name the name of the file to be read
*/
void print_line_one_info(const std::string& file_name);

#endif
