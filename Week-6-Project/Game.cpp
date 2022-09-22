#include "Card.h"
#include "Range.h"

using namespace std;

int main() {
    // display introduction to the game
    cout << "Cards 2-10 are worth their numeric vaule.\n";
    cout << "J, Q, K have a value of 11.\n";
    cout << "An A has a value of 12 as a spade and 1 for other suits.\n";
    cout << "Over 3 rounds, you will try to reach or exceed a target value, without going over 22!\n";
    cout << "If you go over, you get -1 points; if you are within range, you get +1 points;";
    cout << " otherwise you get 0 points.\n\n";

    int total_points = 0; // variable for the total points earned by the user
    const int first_run = 1, last_run = 3; // variables for the first and last run
    
    srand(time(nullptr)); // make random numbers random according to the current time

    for (int i = first_run; i <= last_run; ++i) { // for loop that runs 3 times
        // vector of strings for all the faces in the deck
        vector<string>faces = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        // vector of strings for all the suits in the deck
        vector<string>suits = {"Diamonds", "Hearts", "Spades", "Clubs"};
        
        vector<Card>all_cards; // vector for all 52 cards in the deck
        
        // variables for the sizes of suits and faces vector
        size_t suits_size = suits.size(), faces_size = faces.size();

        for (size_t i = 0; i < suits_size; ++i) { // for every number within the size of the vector of suits
            string one_suit = suits[i]; // get a string with the suit that has that number
            
            for (size_t i = 0; i < faces_size; ++i) { // for every number within the vector of faces
                string one_face = faces[i]; // get a string with the face that has the number
                
                // add a Card to the deck having that suit and face
                all_cards.push_back( Card(one_suit, one_face) );
            }
        }
        
        const int max_value = 22, lowest_value = 17; // variable for the max and lowest allowed value of the cards
        const int inclusive = 1; // variable for making the random number inclusive
        
        // get a random number from 17 to 22 inclusive for the lower bound
        int lower_bound = rand() % (max_value - lowest_value + inclusive) + lowest_value;
        
        vector<Card>hand_cards; // create a vector for the hands of cards
        int total_value = 0; // variable for the total card values for each hand

        bool more = true; // create bool for the while loop
        while (more) { // while more is true
            cout << "Target lower bound: " << lower_bound << '\n'; // display target lower bound
            
            Card current_card = dealCard(all_cards); // deal a card from the deck and set it aside

            hand_cards.push_back(current_card); // add the selected card to the vector for the hand

            showHand(hand_cards, total_value); // display the hand value and the cards in the hand

            // create a bool that returns true if the hand value is greater than 22
            bool exceeds_max = exceeds(max_value, total_value);
            if (exceeds_max) { // if the hand value exceeds the max
                total_points -= 1; // subtract 1 from the total amount of points
                cout << "You got -1 points." << '\n'; // display message
                break; // end the while loop
            }

            // create a bool that returns true if the hand is within the winning range
            bool in_range = inRange(lower_bound, max_value, total_value);
            if (in_range) { // if the hand value is in the winning range
                total_points += 1; // add 1 to the total amount of points
                cout << "You got 1 point." << '\n'; // display message
                break; // end the while loop
            }

            cout << "Deal more? y/n: "; // ask the user if they want another card
            char yesNo = ' '; // char for the user input
            cin >> yesNo; // user inputs y (yes) or n (no)

            if (yesNo == 'n') { // if the user inputs n (no)
                total_points += 0; // the total amount of points stays the same
                cout << "You got 0 points." << '\n'; // display message
                more = false; // set bool more to false to end the while loop
            }
        }
        cout << '\n'; // space between iterations of the for loop
    }
    
    cout << '\n'; // double space before displaying total score
    
    if (total_points == 1) { // if the total number of points is 1
        cout << "Your total score is " << total_points << " point."; // display total score
    }
    else { // if the total number of points is not 1
        cout << "Your total score is " << total_points << " points."; // display total score
    }
   
    return 0; // terminate program
}
