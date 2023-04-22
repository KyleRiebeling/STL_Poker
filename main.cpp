#include <iostream>
#include <map>
#include <list>
#include <cstdlib>

#include "DeckOfCards.h"

using namespace std;

void printPlayers(map<string, int> a) {
   cout << "Player   Bank" << endl;
   cout << "-------------" << endl;
   for (auto pair : a) {
      cout << pair.first << " - $";
      cout << pair.second << endl;
   }
   cout << endl;
}

int main() {
   srand(time(0));
   map<string, int> players;
   map<string, list<int>> playerStats;
   list<int> player1Stats;
   list<int> player2Stats;
   list<int> player3Stats;

   int numPlayers = 0;
   int tempN;
   string tempS;

   cout << "Welcome to the casino! How many people will be playing today? (Max of 3)" << endl;
   cin >> numPlayers;

   while (numPlayers <= 0 || numPlayers >= 4) {//Error check for amount of players
      cout << "Must be at least one player. Enter a number from 1-3: ";
      cin >> numPlayers;
   }
   cout << "Enter starting cash for all players: ";
   cin >> tempN;

   for (int i = 0; i < numPlayers; i++) { //Setting up player maps
      cout << "Enter player " << i + 1 << "'s name: ";
      cin >> tempS;
      players.insert(pair<string, int>(tempS, tempN));
      if (i == 0) {
         playerStats.insert(pair<string, list<int>>(tempS, player1Stats));
         player1Stats.push_back(tempN);
      }
      if (i == 1) {
         playerStats.insert(pair<string, list<int>>(tempS, player2Stats));
         player2Stats.push_back(tempN);
      }
      if (i == 2) {
         playerStats.insert(pair<string, list<int>>(tempS, player3Stats));
         player3Stats.push_back(tempN);
      }
   }

   cout << endl << "Welcome to the table!" << endl;
   printPlayers(players);

   //-----GAME LOOP-----

   //Place Bets

   //Deal cards

   //Simulate other players turns


   DeckOfCards myDeckOfCards;
   myDeckOfCards.shuffleDeck(); // place Cards in queue
   Card playersHand[5];

   for (int i = 0; i < 5; i++) {
      playersHand[i] = myDeckOfCards.dealCard();
      cout << playersHand[i].toString() << endl;
   }

   cout << myDeckOfCards.evaluateHand(playersHand);
   return 0;
}

