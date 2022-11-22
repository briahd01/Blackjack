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

int main(int argc, const char * argv[]) {
    // insert code here..
    CardDeck deck;
    Card card;
    BlackjackHand dealer("dealer", 17);
    BlackjackHand player("player", 21);
    
    // deck.shuffle(); fucked up
    card = deck.dealOne();
    cout<< card << "\n";
    
    
    dealer.addCard(card);
    
    // deal the first 2 cards
    for(int i=0; i<2; i++) {
        card = deck.dealOne();
        cout << card;
        player.addCard(card);
        cout << "player" << player.score() << endl;
    }
    
    cout << "\n" << endl;
    
    while (player.canGetCard()) {
        string h;
        cout << "enter h to hit" << endl;
        cin >> h;
        if (h == "h") {
            card = deck.dealOne();
            cout << card << endl;
            player.addCard(card);
            cout << "Player" << player.score() << endl;
        }
        else {
            break;
        }
        cout << "\n" << endl;
    }
    if (player > dealer) {
        cout << "player wins!";
    } else if (dealer > player) {
        cout << "dealer wins!" << endl;
}
    else {
        cout << "tie!" << endl;
    }

    return 0;
}
