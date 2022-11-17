// Briah Davis and Genesis Clarke
// 11/16/2022
// CardDeck.hpp

#ifndef CardDeck_hpp
#define CardDeck_hpp

#include "Card.cpp"
#include <vector>

class CardDeck {
	// output operator
	friend std::ostream& operator<<(std::ostream& os, CardDeck& card);

public:
	// constructor will initialize the deck of cards
	CardDeck();

	// creates a new deck of cards
	void freshDeck();

	// shuffles the cards
	void shuffle();

	// determines if there are any more cards left in the deck
	bool hasCards();

	// returns how many cards are left in the deck
	int cardsLeft();

	// takes a card from the deck
	Card dealOne();

private:
	// represents a 52 card deck
	std::vector<Card> _cards;
};
#endif /* CardDeck_hpp */

std::ostream& operator<<(std::ostream& os, CardDeck& card);

