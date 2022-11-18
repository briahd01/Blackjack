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
		// create a new card object to store in the list of cards
		Card card(i);
		_cards.push_back(card);
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
// determines if the deck still has cards left
bool CardDeck::hasCards() {
	return (_cards.size() > 0);
}

// determines the number of cards left
int CardDeck::cardsLeft() {
	return _cards.size();
}

// deals a card when playing a game
Card CardDeck::dealOne() {
	// make sure there are still cards to deal
	if (_cards.size() == 0) {
		std::cout << "CardDeck out of cards" << std::endl;
	}

	// access the last card
	Card card = _cards.back();
	// remove it from the list
	_cards.pop_back();

	return card;
}

std::ostream& operator<<(std::ostream& os, CardDeck& card) {
	// loop through every card in the deck
	for (int i = 0; i < 52; i++) {
		// output the card
		os << card._cards[i];
	}
	return os;
}
