#include <iostream>
#include <map>
#include <list>
#include <cstdlib>

#include "DeckOfCards.h"
#include "Table.h"

using namespace std;


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
   
   Table pTable = Table(numPlayers);

   cout << endl << "Welcome to the table!" << endl;
   pTable.printPlayers();

   //-----GAME LOOP-----

   //Place Bets

   //Deal cards

   //Simulate other players turns


   DeckOfCards myDeckOfCards;
   myDeckOfCards.shuffleDeck(); // place Cards in queue
   Card playersHands[numPlayers][2];
   myDeckOfCards.dealHands(playersHands,numPlayers);
   /*for(int i = 0; i < numPlayers; i++){
      cout << myDeckOfCards.evaluateHand(playersHand[j]) << endl << endl;
   }*/

   
   return 0;
}

