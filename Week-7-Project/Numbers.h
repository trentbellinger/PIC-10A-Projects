#ifndef _NUMBERS_
#define _NUMBERS_
#include<string>
#include<cstddef>

/**
This function takes a single character and returns an unsigned char for its value from 0-9.
@param c the character to convert
@return its value from 0-9
*/
unsigned char charToDigit(char c);

/**
This function converts an unsigned char from 0-9 and returns a char '0' to '9'.
@param u the unsigned char to convert
@return its digit representation as a char
*/
char digitToChar(unsigned char u);

/**
 This function reverses the characters of a string, altering the inputted string.
 @param s the string to reverse
 */
void reverseString(std::string &s);

/**
 This function makes two strings the same length, prepending the shorter string with 0's until the
 two strings have equal length.
 @param first the first string
 @param second the second string
 */
void equalString(std::string &first, std::string &second);

/**
This function adds two unsigned integer types, represented as strings, given a base to work in.
@param first the first addend
@param second the second addend
@param base the base being used: from 2-10
@return the sum, num1+num2 in the base
*/
std::string add(const std::string& first, const std::string& second, unsigned char base);

/**
This function computes 2 to a given nonnegative integer power with the output as an std::string, in base 10.
@param pow the power
@return 2 to that power
*/
std::string twoPower(size_t pow);

/**
 This function accepts a string of an integer in binary and outputs a decimal representation.
 @param binary a string representation of a number in binary
 @return a string representation of the integer in decimal
 */
std::string binaryToDecimal(const std::string &binary);

/**
This function determines whether two string representations of unsigned integers satisfy <= numerically.
@param first the first number
@param second the second number
@return whether first <= second as unsigned integer types
*/
bool lessThanOrEqual(const std::string& first, const std::string& second);

/**
This function subtracts two unsigned integer types, represented as strings, given a base to work in.
@param minuend the term being subtracted from
@param subtrahend the value being subtracted
@param base the base being used
@return the difference, minuend-subtrahend in the base given
*/
std::string subtract(const std::string& minuend, std::string subtrahend, unsigned
char base);

/**
 This function accepts a string of an integer in decimal and outputs a binary representation.
 @param decimal a string representation of an integer in decimal
 @return a string representation of the integer in binary
 */
std::string decimalToBinary(const std::string &decimal);

#endif
