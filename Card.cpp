// Briah Davis and Genesis Clarke
// 11/16/22
// Card.cpp


#include "Card.hpp"

// class variables

// one or two characters face abbreviations for card
std::string faceAbbreviations[] = { "a", "2", "3", "4", "5", "6", "7", "8", "9", "10", "j", "q", "k" };

// one character abbreviation for the suit names
std::string suitLetters[] = {"c", "s", "h", "d"};

// full names for each face
std::string faceNames[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
							"Jack", "Queen", "King" };

// full names for each suit
std::string suitNames[] = { "Clubs", "Spades", "Hearts", "Diamonds" };


// constructor takes in a parameter int value
Card::Card(int value = 0) {
	if (value < 0 || value > 51) {
		std::cout << "invalid int for Card initialization (must be 0 to 51):" << std::endl;
	}
	_cardNumber = value;

}

// returns the string of the face name
std::string Card::faceName() {
	// calculate the index for faceNum using the cardNumber
	int faceNum = _cardNumber % 13;
	std::string face = faceNames[faceNum];

	return face;
}

// returns string of the suitname
std::string Card::suitName() {
	int suitNum = _cardNumber / 13;
	std::string suit = suitNames[suitNum];

	return suit;

}

// returns the value of the card based on suit and face name
int Card::blackjackValue() {
	// calculate the value based on card number
	int value = _cardNumber % 13 + 1;

	// if an ace, the value is 11
	if (value == 1) {
		value == 11;
	}
	// if the cards are 10, j, q, or k, the value is 10
	else if (value > 10) {
		value = 10;
	}
	return value;
}



std::ostream& operator<<(std::ostream& os, const Card& card) {
	os << card.faceName() << "of" << card.suitName();

	return os;
}