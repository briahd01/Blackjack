// Briah Davis and Genesis Clarke
// 11/17/2022
// BlackjackHand.hpp

#include "BlackjackHand.hpp"


// gets a name and stay value for the player to store in instance variables
BlackjackHand::BlackjackHand(std::string name, int stayValue) {
	_name = name;
	_stayValue = stayValue;
	_total = 0;
	_hasAce11 = false;
}

// resets the player's hand to be empty
void BlackjackHand::reset() {
	_total = 0;
	_hasAce11 = false;
}

// determines if a player can still get a card
bool BlackjackHand::canGetCard() {
	return (_total < _stayValue);
}

// adds a new card to the hand
void BlackjackHand::addCard(Card card) {
	// get the value of the card
	int value = card.blackjackValue();

	// check if the value is an ace
	if (value == 11) {
		// check if the value with an ace is greater than 10
		if (_total > 10) {
			// if so, switch the ace value to a 1
			value = 1;
		}
		else {
			// otherwise, the ace stays with a value of 11
			_hasAce11 = true;
		}
	}
	// if adding the card would bust and we already have an ace that is 11
	if (_total + value > 21 && _hasAce11) {
		// change the ace to a 1 by removing 10 point
		_total += value - 10;
		// ace is no longer 11
		_hasAce11 = false;
	}
	else {
		// otherwise, add the card to the hand
		_total += value;
	}
}

// returns the total score of the player's hand
int BlackjackHand::score() {
	return _total;
}

// determines if the player busted
bool BlackjackHand::busted() const {
	return (_total > 21);
}

// true if one hand is less than the other
bool BlackjackHand::operator<(const BlackjackHand& other) const {
	// if both busted, then this is true
	if (busted() && other.busted()) {
		return true;
	}
	// if the other busted, then the first hand won
	else if (other.busted()) {
		return false;
	}
	// if the first hand busted, then the second hand won
	else if (busted()) {
		return true;
	}
	// otherwise, check the numbers
	return _total < other._total;
}

// true if the hands are equal
bool BlackjackHand::operator==(const BlackjackHand& other) const {
	if (busted() && other.busted()) {
		return true;
	}
	if (busted() || other.busted()) {
		return false;
	}
	return _total == other._total;
}

// true if the hands are not equal
bool BlackjackHand::operator!=(const BlackjackHand& other) const {
	return !(*this == other);
}

// true if one hand is less than or equal to the other
bool BlackjackHand::operator<=(const BlackjackHand& other) const {
	return (*this < other) or (*this == other);
}

// true if one hand has a greater score than the other
bool BlackjackHand::operator>(const BlackjackHand& other) const {
	return !(*this <= other);
}

// true if one hand is greater than or equal to the other hand
bool BlackjackHand::operator>=(const BlackjackHand& other) const {
	return !(*this < other);
}

// string override
std::ostream& operator<<(std::ostream& os, BlackjackHand& hand) {
	std::string name = hand._name;

	// check if the name is not empty to add colons after it
	if (name != "") {
		name = name + ":";
	}

	// if the player busted, add "busted" next to the name and return the string
	if (hand._total > 21) {
		name = name + " busted";
		os << name;
		return os;
	}
	else {
        // convert total to a string
		std::string total = std::to_string(hand._total);
		// add the total next to the name and return the string
		name = name + " " + total;
		os << name;
		return os;
	}
}