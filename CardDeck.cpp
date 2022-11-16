// Briah Davis and Genesis Clarke
// 11/16/2022
// CardDeck.cpp

#include "CardDeck.hpp"

CardDeck::CardDeck() {
	freshDeck();
}

// creates all the cards in a deck
void CardDeck::freshDeck() {
	// loop through numbers 0 - 51 to get every card
	for (int i = 0; i < 52; i++) {
		Card card(i);
		// create a new card object to store in the list of cards
		_cards[i] = card;
	}
}

// shuffles the cards using a random int
void CardDeck::shuffle() {
	// sets a starting point for rand
	srand(time(nullptr) % INT_MAX);

	// loop through cards
	for (int i = 0; i < 52; i++) {
		// get random number
		int num = rand();

		// switch the positions of the card using the random number
		_cards[i] = _cards[num];
	}
}

bool CardDeck::hasCards() {

	return (_cards.size() > 0);

}

int CardDeck::cardsLeft() {

	return _cards.size();

}

Card CardDeck::dealOne() {

	if (_cards.size() == 0) {
		std::cout << "CardDeck out of cards" << std::endl;
	}

	return _cards.back();

}
