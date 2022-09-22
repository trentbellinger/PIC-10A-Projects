#include "Range.h"
#include "Card.h"

using namespace std;

int cardValue(const Card &card) { // given a Card, return the value of that card
    int value = 0; // variable for the value of the card
    string card_string = card.card_as_string(); // change the card to a string
    
    string face_string = card_string; // create a string for the first character of the string
    size_t face_string_size = face_string.size(); // variable for the size of the string
    size_t one_less = 1; // variable to get one less than the size of the string
    
    // for all values from 0 to 1 less than the size of the string
    for (size_t i = 0; i < face_string_size - one_less; i++) {
        face_string.pop_back(); // remove the last character of the string
    }
    
    if ( face_string == "1") { // if the first character of the string is 1
        value = 10; // set the value of the card to 10
    }
    // if the first character of the string is J, Q, or K
    else if ( (face_string == "J") || (face_string == "Q") || (face_string == "K") ) {
        value = 11; // set the value of the card to 11
    }
    else if (face_string == "A") { // if the first character of the string is A
        card_string.pop_back(); // remove the last character if the original string
        // remove the first 2 characters from the string to get the suit
        string aces_suit = card_string.substr(2);
        
        if (aces_suit == "Spades") { // if the suit of the card is spades
            value = 12; // set the value of the card to 12
        }
        else { // if the suit of the card is not spades
            value = 1; // set the value of the card to 1
        }
    }
    else { // if the first character is between 2 and 9
        int lower = 2, upper = 9; // variables for the upper and lower of the for loop
        
        for (int i = lower; i <= upper; ++i) { // for all numbers between 2 and 9
            // convert the first character of the card string to an int
            string i_string = to_string(i);
            if (face_string == i_string) { // if the first character is equal to i (2-9)
                value = i; // set the value to be i (2-9)
            }
        }
    }

    return value;
}

// given a vector of all the cards, choose 1 card and remove it from the deck
Card dealCard(vector<Card>&all_cards) {
    // choose a random number from the number of cards in the deck
    int selected_card_number = rand() % all_cards.size();
    
    // get the card that corresponds with the random number
    Card selected_card = all_cards[selected_card_number];
    
    // remove the selected card from the vector of all cards
    all_cards.erase(all_cards.begin() + selected_card_number);
     
    return selected_card;
}

// display the value of a hand of cards and the cards in the hand
void showHand(const vector<Card>&hand_cards, int &hand_value) {
    string cards_in_hand = ""; // create a string for the cards in the hand
    size_t hand_cards_size = hand_cards.size(); // variable for the size of the hand cards vector

    for (size_t i = 0; i < hand_cards_size; ++i) { // for all the cards in the hand
        Card current_card = hand_cards[i]; // get the current card from the vector of the hand
        cards_in_hand += current_card.card_as_string() + " "; // add the current card to a string with a space
    }

    size_t last = 1; // variable to get last value in the vector
    // add the card value to the total value
    hand_value += cardValue(hand_cards[hand_cards_size - last]);

    cout << "Hand value is: " << hand_value << '\n'; // display hand value
    cout << "Hand is: " << cards_in_hand << '\n'; // display the cards in the hand
}

// bool that returns true if the hand value exceeds the maximum allowed value
bool exceeds(const int &max_value, const int &hand_value) {
    bool exceeds = false; // create a bool to show if the value of the hand exceeds the max

    if (hand_value > max_value) { // if the value of the hand exceeds the max
        exceeds = true; // the bool for exceeds is true
    }
    
    return exceeds;
}

// bool that returns true if the hand is within the winning range
bool inRange(const int &lower_bound, const int &max_value, const int &total_value) {
    bool inRange = false; // create a bool to show if the value of the hand is in the winning range
    
    // if the hand is within the winning range
    if ((total_value >= lower_bound) && (total_value <= max_value)) {
        inRange = true; // the bool for inRange is true
    }
    
    return inRange;
}
