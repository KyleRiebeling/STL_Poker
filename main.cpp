#include <iostream>
#include <map>
#include <list>
#include <cstdlib>


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
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> numPlayers;
   }

   Table pTable = Table(numPlayers);

   cout << endl << "Welcome to the table!" << endl;
   pTable.printPlayers();

   //-----GAME LOOP-----

   //Place Buy-in Bets++++

   //Deal cards ++++

   //Ask for more bets 2

   //Dealer places three cards on table

   //Ask for more bets/folds 3

   //Dealer places one more card

   //Ask for bets/fold 4

   //Dealer places last card

   //Last round of betting 5

   //Reveal winner and their hand

   //Ask if you want to keep going

   for (int i = 0; i < 5; i++) {
      pTable.placeBets();
      pTable.startTurn();
   }

   return 0;
}

