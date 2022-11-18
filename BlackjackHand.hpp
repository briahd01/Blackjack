// Briah Davis and Genesis Clarke
// 11/17/2022
// BlackjackHand.hpp

#include "Card.hpp"


class BlackjackHand {

	friend std::ostream& operator<<(std::ostream& os, BlackjackHand& hand);

public:
	// gets a name and stay value for the player to store in instance variables
	BlackjackHand(std::string name, int stayValue);

	// resets the player's hand to be empty
	void reset();

	// determines if a player can still get a card
	bool canGetCard();

	// adds a new card to the hand
	void addCard(Card card);

	// returns the total score of the player's hand
	int score();

	// determines if the player busted
	bool busted() const;

	// true if one hand is less than the other
	bool operator<(const BlackjackHand& other) const;

	// true if the hands are equal
	bool operator==(const BlackjackHand& other) const;

	// true if the hands are not equal
	bool operator!=(const BlackjackHand& other) const;

	// true if one hand is less than or equal to the other
	bool operator<=(const BlackjackHand& other) const;

	// true if one hand has a greater score than the other
	bool operator>(const BlackjackHand& other) const;

	// true if one hand is greater than or equal to the other hand
	bool operator>=(const BlackjackHand& other) const;

private:
	// name for the hand
	std::string _name;
	// value which the hand stops getting cards
	int _stayValue;
	// total value of the hand
	int _total;
	// True if the hand has an ace that is value 11
	bool _hasAce11;
};

std::ostream& operator<<(std::ostream& os, BlackjackHand& hand);