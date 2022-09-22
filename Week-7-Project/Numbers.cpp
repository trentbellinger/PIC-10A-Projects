#include "Numbers.h"
#include<stdexcept>
#include<string>
#include<iostream>

// takes a char and returns an unsigned char for its value
unsigned char charToDigit(char c) {
    int c_int = c - '0'; // convert the char to an int
    // convert the value of the int to an unsigned char
    unsigned char c_char = static_cast<unsigned char>(c_int);
    return c_char;
}

// takes an unsigned char from 0-9 and returns a char
char digitToChar(unsigned char u) {
    int u_int = u + '0'; // convert the unsigned char to an int
    // convert the int to a char in the form 'int'
    char u_char = static_cast<char>(u_int);
    return u_char;
}

// reverses the characters of a string
void reverseString(std::string &s) {
    std::string s_reversed; // string for s reversed
    s_reversed.resize(s.size()); // make the size of s reversed the same as s
    size_t one_less = 1; // variable to subtract 1
    
    for (size_t i = 0; i < s.size(); ++i) { // for all characters of s
        // change s reversed character at position i to be one less than s size - i
        s_reversed[i] = s[s.size() - i - one_less];
    }
    s = s_reversed; // change s to be s reversed
}

// makes 2 strings the same length by prepending the shorter string with 0's
void equalString (std::string &first, std::string &second) {
    std::string first_copy = first, second_copy = second; // make copies of the 2 strings
    size_t one_less = 1; // variable for 1

    if ( first.size() > second.size() ) { // if the first string is longer
        // change the second string to have the same size as the first string
        second_copy.resize( first.size() );
        
        for (size_t i = 1; i <= second.size(); ++i) { // for every character of the second string
            // transfer the characters from the second string to the end of the new second string
            second_copy[first.size() - i] = second[second.size() - i];
        }
        
        // for the unused spaces in the beginning of the new second string
        for (size_t i = 0; i <= first.size() - second.size() - one_less; ++i) {
            second_copy[i] = '0'; // make the characters 0
        }
    }
    else if (second.size() > first.size()) { // if the second string is larger
        // change the first string to have the same size as the second string
        first_copy.resize( second.size() );
        
        for (size_t i = 1; i <= first.size(); ++i) { // for every character of the first string
            // transfer the characters from the first string to the end of the new first string
            first_copy[second.size() - i] = first[first.size() - i];
        }
        
        // for the unused places in the beginning of the new first string
        for (size_t i = 0; i <= second.size() - first.size() - one_less; ++i) {
            first_copy[i] = '0'; // make the characters 0
        }
    }
    first = first_copy; // make first the copied string
    second = second_copy; // make second the copied string
}

// add two unsigned integers represented as strings given a base
std::string add(const std::string& first, const std::string& second, unsigned char base) {
    std::string first_copy = first, second_copy = second; // create copies of the first and second strings
    equalString(first_copy, second_copy); // make the strings equal length
    
    std::string result = ""; // create a string for the result
    unsigned char carry = 0; // variable for the number that is carried in the addition
    size_t one_less = 1; // variable to subtract 1
    
    for (size_t i = 1; i <= first_copy.size(); ++i) { // for every character of the two strings
        
        // get an unsigned char for the size - i position of each string
        unsigned char num_1 = charToDigit( first_copy[first_copy.size() - i] );
        unsigned char num_2 = charToDigit( second_copy[first_copy.size() - i] );
        
        // compute total as carry + number from string 1 + number from string 2
        unsigned char total = carry + num_1 + num_2;
        // compute result as an unsigned char by taking the remainder of total divided by base
        unsigned char result_uc = total % base;
        carry = total / base; // cchange carry to be total divided by base
        
        char result_char = digitToChar(result_uc); // convert the result to a char
        result.resize(i + one_less); // change the size of the result string to i + 1
        result[i - one_less] = result_char; // insert the result char into the result string
    }
    
    if (carry != 0) { // if carry is not 0
        char carry_char = digitToChar(carry); // convert carry into a char
        result[result.size() - one_less] = carry_char; // make carry the last character of the result string
    }
    else { // if carry is 0
        result.pop_back(); // remove the last character of the result string
    }
    
    reverseString(result); // reverse the result string to get the final product
    return result;
}

// compute 2 to the power of an integer
std::string twoPower(size_t pow) {
    std::string num = "1"; // create string for numbers starting at 1
    unsigned char base = 10; // set the base to 10
    
    for (auto i = 0; i < pow; ++i) { // for all numbers between 0 and the power
        num = add(num, num, base); // change num to be num + num
    }
    
    return num;
}

// accepts a string of an integer in binary and returns the integer in decimal
std::string binaryToDecimal(const std::string &binary) {
    std::string decimal; // create a string for the decimal
    size_t one_less = 1; // variable to subtract 1
    
    for (size_t i = 0; i < binary.size(); ++i) { // for all numbers in the binary string
        if (binary[i] == '1') { // if the character is 1
            // change decimal to be decimal plus 2^(one less than the size of binary - i)
            decimal = add(decimal, twoPower(binary.size() - i - one_less), 10);
        }
    }
    return decimal;
}

// determines whether two unsigned integers as strings satisfy <= numerically
bool lessThanOrEqual(const std::string& first, const std::string& second) {
    if (first == second) { // if the two strings are equal, then they are equal!
        return true;
    }
    /* We need to look at their lengths: a longer number in proper format (no 0's
     at beginning) will always be larger than a number that is shorter */
    if (first.size() < second.size()) { // second longer
        return true; // so first < second
    }
    else if (second.size() < first.size()) { // first longer
        return false; // so first > second
    }
    else { /* If the numbers have the same length, we can compare digit by digit
    because the chars 0-9 are ordered */
        return first < second;
    }
}

// subtracts two unsigned integers as strings given a base
std::string subtract(const std::string& minuend, std::string subtrahend, unsigned char base) {
    // ensure subtrahend has as many digits as minuend
    if (subtrahend.size() < minuend.size()) {
        subtrahend = std::string(minuend.size() - subtrahend.size(), '0') +
        subtrahend;
    }
    /* We first wish to modify each digit of subtrahend by turning it into its
     complement.
     The digit d should be converted into (base-1-d). */

    for (auto &c : subtrahend) { // for each char in the subtrahend string
        // need to convert the char to digits, do the arithmetic, and go back to char!
        c = digitToChar( (base - 1) - charToDigit(c) );
    }
    //Subtraction can be done by addition, now. We first add 1 to the subtrahend.
    subtrahend = add(subtrahend, "1", base);
    // now, add the minuend and updated subtrahend
    std::string difference = add(minuend, subtrahend, base);

    /* The resulting number will always have a superfluous digit at index 0 that we
     do not want.
     In addition, we wish to move past all the zeros at the start. */

    size_t zeroEnd = 1; // index to track where zeros end
    // size of the difference
    const size_t diff_sz = difference.size();
    // while index still within bounds (checked first) and there are still zeros
    while ((zeroEnd < diff_sz) && (difference[zeroEnd] == '0')) {
        ++zeroEnd; // increase the index
    }
    if (zeroEnd == diff_sz) { // if zeroEnd is out of range then it was all 0's
        return "0";
    }
    return difference.substr(zeroEnd); // return the truncated number going from
    // first nonzero to end of string
}

// accepts a string of an integer in decimal and converts it to binary
std::string decimalToBinary(const std::string &decimal) {
    std::string temp; // create a temporary string
    size_t maxPower = 0; // variable for the max power
    size_t one_more = 1; // variable to add one
    unsigned char base = 10; // set the base to be 10
    
    for (size_t i = 0; ; ++i) { // for loop that runs until break;
        // change temp to be 2^i
        temp = twoPower(i);
        
        if ( lessThanOrEqual(temp, decimal) == false ) { // if temp > decimal
            maxPower = i - one_more; // change the maxPower to i - 1
            break; // exit the for loop
        }
    }
    
    std::string decimal_copy = decimal; // create a copy of decimal
    std::string binary; // create a string for the binary integer
    size_t pow = maxPower; // set pow equal to maxPower
    binary.resize(maxPower + one_more); // change the size of binary to be maxPower + 1
    
    for (size_t i = 0; i <= maxPower; ++i) { // for all integers between 0 and maxPower
        if (pow < 0) { // if pow is less than 0
            break; // exit the for loop
        }
        
        // if 2^pow is less than or equal to the decimal copy
        if (lessThanOrEqual(twoPower(pow), decimal_copy) == true) {
            binary[i] = '1'; // set i-th character in binary to 1
            
            // change decimal copy to be decimal copy plus 2^pow
            decimal_copy = subtract(decimal_copy, twoPower(pow), base);
            pow--; // make pow one less
        }
        else { // if 2^pow is greater than the decimal copy
            if (pow != maxPower) { // if the current power is not maxPower
                binary[i] = '0'; // set i-th character of binary to 0
            }
            
            pow--; // make pow one less
        }
    }
    
    return binary;
}
