#include<iostream> // header file for inputs and outputs

using namespace std; // specify standard namespace

int main() {
    // display command
    cout << "Enter a range of numbers to factorize. Enter lower bound and upper bound separated by a space: ";
    long long lower_bound, upper_bound; // variable for lower and upper bound
    cin >> lower_bound >> upper_bound; // user inputs lower and upper bound
    
    const long long divisible = 0; // variable to show if number is divisible
    
    // for every integer i between inputted lower and upper bound
    for (long long integer = lower_bound; integer <= upper_bound; ++integer) {
        
        long long current = integer; // variable for the current number used in calculations
        cout << current << ": "; // display the current number
        
        long long unit = 1, two_prime = 2; // variable for 1 and 2
        
        if (current == unit) { // if the current integer is 1
            cout << "unit!"; // display unit!
        }
        else if (current == two_prime) { // if the current integer is 2
            cout << "prime!"; // display prime!
        }
        
        long long divisor = 2; // variable for the divisor 2
        
        // while the current number is divisible by 2 and is not 2
        while ( (current % divisor == divisible) && (integer != two_prime) ) {
            
            current /= divisor; // change current number to be divided by 2
            
            if (current != unit) { // if the current number is not 1
                cout << "2 x "; // display prime factor 2 and multiplication symbol
            }
            else { // if the current number is 1
                cout << "2"; // display prime factor 2
            }
        }
        
        long long odd_divisor = 3; // variable for the divisor 3
        
        // for every odd integer that is less than the beginning integer
        for (long long divisor_2 = odd_divisor; divisor_2 <= integer; divisor_2 += two_prime) {
            
            while ( current % divisor_2 == divisible ) { // while the integer is divisible by an odd integer
                
                current /= divisor_2; // change current number to be divided by an odd integer
                
                if ( divisor_2 > integer/two_prime ) { // if the divisor is greater than the integer divided by 2
                    cout << "prime!"; // the number is prime
                    break; // exit the while loop
                }
                
                if (current != 1) { // if the current number is not 1
                    cout << divisor_2 << " x "; // display prime factor and multiplication symbol
                }
                else { // if the current number is 1
                    cout << divisor_2; // display prime factor
                }
            }
        }
        cout << '\n'; // indentation after factorization
    }
    
    return 0; // terminate program
}
