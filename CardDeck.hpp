// Briah Davis and Genesis Clarke
// 11/16/2022
// CardDeck.hpp
#ifndef CardDeck_hpp
#define CardDeck_hpp

#include "Card.cpp"

class CardDeck {
	friend std::ostream& operator<<(std::ostream& os, const CardDeck& card);

public:
	CardDeck();

	void freshDeck();

	void shuffle();

	bool hasCards();

	int cardsLeft();

	Card dealOne();

private:
	Card _cards[52];
};
#endif /* CardDeck_hpp */

std::ostream& operator<<(std::ostream& os, const CardDeck& card);

