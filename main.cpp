#include <iostream>
#include <map>
#include <list>
#include <cstdlib>

#include "DeckOfCards.h"
#include "Table.h"

using namespace std;


int main() {
   int numPlayers = 0;

   cout << "Welcome to the casino! How many people will be playing today? (Max of 3)" << endl;
   cin >> numPlayers;

   //Error check for amount of players
   while (numPlayers <= 0 || numPlayers >= 4 || cin.fail()) {
      cout << "Must be at least one player. Enter a number from 1-3: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cin >> numPlayers;
   }
   
   Table pTable = Table(numPlayers);

   cout << endl << "Welcome to the table!" << endl;
   pTable.printPlayers();

   //-----GAME LOOP-----

   //Place Buy-in Bets

   //Deal cards

   //Ask for more bets

   //Dealer places three cards on table

   //Ask for more bets/folds

   //Dealer places one more card

   //Ask for bets/fold

   //Dealer places last card

   //Last round of betting

   //Reveal winner and their hand

   //Ask if you want to keep going


   DeckOfCards myDeckOfCards;
   myDeckOfCards.shuffleDeck(); // place Cards in queue
   Card playersHands[numPlayers][2];
   myDeckOfCards.dealHands(playersHands,numPlayers);//Give each player 2 cards

   
   return 0;
}

