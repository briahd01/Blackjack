//
//  main.cpp
//  BlackjackLab
//
//  Created by Genesis Clarke on 11/17/22.
//

#include <iostream>
#include "Card.hpp"
#include "CardDeck.hpp"
#include "BlackjackHand.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, const char* argv[]) {
    // insert code here..
    CardDeck deck;
    Card card(0);
    BlackjackHand dealer("Dealer", 17);
    BlackjackHand player("Player", 21);

    // shuffle the deck before dealing 
    deck.shuffle();
    card = deck.dealOne();

    // deal one card to the dealer
    dealer.addCard(card);
    cout << card << endl;
    cout << dealer << endl;
    cout << "\n" << endl;
    
    // deal the first 2 cards
    for (int i = 0; i < 2; i++) {
        // get a card and add it to the player's hand
        card = deck.dealOne();
        cout << card << endl;
        player.addCard(card);
        cout << player << endl;
    }

    cout << "\n" << endl;

    // loop through to play the game
    while (player.canGetCard()) {
        string h;
        // if the player hits, deal another card
        cout << "enter h to hit" << endl;
        cin >> h;
        if (h == "h") {
            card = deck.dealOne();
            cout << card << endl;
            player.addCard(card);
            cout << player << endl;
        }
        // if the player stays, stop dealing cards
        else {
            break;
        }
        cout << "\n" << endl;
    }
    // if the player did not bust, deal cards to the dealer
    if (!(player.busted())) {
        while (dealer.canGetCard()) {
            card = deck.dealOne();
            cout << card << endl;
            dealer.addCard(card);
            cout << dealer << endl;
            cout << "\n" << endl;
        }
    }
    // compare the hands to determine which player won
    if (player > dealer) {
        cout << "player wins!";
    }
    else if (dealer > player) {
        cout << "dealer wins!" << endl;
    }
    else {
        cout << "tie!" << endl;
    }

    return 0;
}