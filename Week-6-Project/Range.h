#ifndef _RANGE_
#define _RANGE_
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iterator>
#include "Card.h"

/**
The cardValue function will get the value of a Card.
 
@param card the card to get the value of
 
@return the card value
*/
int cardValue(const Card &card);

/**
The dealCard function will choose a random card from the deck of 52 cards and
remove it from the deck.
 
@param all_cards the vector of all 52 cards in the deck
 
@return one randomly selected Card
*/
Card dealCard(std::vector<Card>&all_cards);

/**
The showHand function will display the value of a hand of cards and will display
the cards in a hand.
 
@param hand_cards the vector containing the Cards in the hand
@param total_value the total value of the cards in the hand
*/
void showHand(const std::vector<Card>&hand_cards, int &total_value);

/**
The exceeds function will return true if the value of the user's hand exceeds the
maximum allowed value.
 
@param max_value the maximum allowed value of the cards
@param hand_value the value of the user's hand
 
@return true if the hand value exceeds the maximum allowed value
*/
bool exceeds(const int &max_value, const int &hand_value);

/**
The inRange function will return true if the value of the user's hand is within the
winning range.

@param lower_bound the lowest possible winning value
@param max_value the maximum possible winning value
@param hand_value the value of the user's hand
 
@return true is the hand value is within the winning range
*/
bool inRange(const int &lower_bound, const int &max_value, const int &hand_value);

#endif
