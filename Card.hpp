// Briah Davis and Genesis Clarke
// 11/16/22
// Card.hpp


#ifndef Card_hpp
#define Card_hpp

#include <iostream>
#include <string>


class Card {
	// string operator to output a card
	friend std::ostream& operator<<(std::ostream& os, Card& card);
	friend class CardDeck;

public:
	// constructor takes in a parameter int value
	Card(int value);

	// comparison operator for comparing if two cards are equal
	bool operator==(const Card& other) const { return _cardNumber == other._cardNumber;  }

	// comparison operator for comparing if two cards are not equal
	bool operator!=(const Card& other) const { return _cardNumber != other._cardNumber;  }

	// returns the string of the face name
	std::string faceName() const;

	// returns string of the suitname
	std::string suitName() const;

	// returns the value of the card based on suit and face name
	int blackjackValue();

private:
	// holds an int representing the card number in a deck
	int _cardNumber;

	// class variables
	static const std::string faceAbbreviations[13];
	static const std::string suitLetters[4];
	static const std::string faceNames[13];
	static const std::string suitNames[4];
};

std::ostream& operator<<(std::ostream& os, Card& card);

#endif /* Card_hpp */