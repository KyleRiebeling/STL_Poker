/*
 * File:   Card.h
 * Author: Kyle
 *
 * Created on April 21, 2023, 5:04 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <set>

#include "DeckOfCards.h"

using namespace std;

class Table {
private:
   DeckOfCards myDeck;
   map<string, int> players;
   map<string, int> activePlayers;
   list<Card> player1Cards;
   list<Card> player2Cards;
   list<Card> player3Cards;
   list<Card> dealerCards;
   int numPlayers;
   int highBet;
   int pot;
   int turn;
public:

   Table(int num_Players) {
      pot = 0;
      numPlayers = num_Players;
      turn = 1;
      myDeck.shuffleDeck();

      int tempN;
      string tempS;
      cout << "Enter starting cash for all players: ";
      cin >> tempN;

      while (tempN < 5 || cin.fail()) {
         cout << "Please enter a number >= 5: ";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cin >> tempN;
      }

      for (int i = 0; i < numPlayers; i++) { //Setting up player maps
         cout << "Enter player " << i + 1 << "'s name: ";
         cin >> tempS;
         players.insert(pair<string, int>(tempS, tempN));
      }
   }

   void printPlayers() {
      cout << "Player   Cash" << endl;
      cout << "-------------" << endl;
      for (auto pair : players) {
         cout << pair.first << " - $";
         cout << pair.second << endl;
      }
      cout << endl;
   }

   void placeBets() {
      int currBet;
      char tempC;

      if (turn == 1) {
         currBet = 5;
         cout << "Everyone places the buy-in bet of $5." << endl;
         activePlayers = players;
         for (auto it = activePlayers.begin(); it != activePlayers.end(); it++) {
            pot += currBet;
            it->second -= currBet;
         }
         cout << "The pot is up to $" << pot << "!" << endl;
      } 
      
      else if (turn >= 2 && turn <= 5) {
         highBet = 0;
         for (auto it = activePlayers.begin(); it != activePlayers.end(); it++) {
            if (tempC == 'f') {
               it = activePlayers.begin();
            }
            tempC = ' ';
            while (tempC != 'f' && tempC != 'c' && tempC != 'r') {
               cout << it->first << ", make a choice: 'f' for fold, 'c' for call, or 'r' for raise: ";
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cin >> tempC;
            }
            switch (tempC) {
               case 'f':
                  players[it->first] = it->second;
                  cout << it->first << " is out of the game!" << endl;
                  activePlayers.erase(it->first);
                  break;
               case 'c':
                  break;
               case 'r':
                  if (it->second <= 0) {
                     cout << "Unable to raise, calling instead." << endl;
                     break;
                  }
                  string currPlay = it->first;
                  cout << "Enter amount to raise: ";
                  cin >> highBet;
                  it->second -= highBet;
                  pot += highBet;
                  raise(currPlay);
                  cout << "New pot is $" << pot << "!" << endl;
                  return;
            }
         }
      }





   }

   void startTurn() {
      string tempS;
      int currPlayer = 1;
      
      if (activePlayers.size() == 1 && turn < 10){
         map<string, int>::iterator it = activePlayers.begin();
         cout << it->first << " wins!";
         turn = 100;
      }

      if (turn == 1) {
         while (!player1Cards.empty()) {
            player1Cards.pop_back();
         }
         while (!player2Cards.empty()) {
            player2Cards.pop_back();
         }
         while (!player3Cards.empty()) {
            player3Cards.pop_back();
         }
         myDeck.dealHand(player1Cards, 2); //Give each player 2 cards
         myDeck.dealHand(player2Cards, 2);
         myDeck.dealHand(player3Cards, 2);
         

         for (auto it = activePlayers.begin(); it != activePlayers.end(); it++) {
            system("clear");
            cout << it->first << ", press any key and then enter to view your hand: ";
            cin >> tempS;
            switch (currPlayer) {
               case 1:
                  myDeck.viewHand(player1Cards);
                  break;
               case 2:
                  myDeck.viewHand(player2Cards);
                  break;
               case 3:
                  myDeck.viewHand(player3Cards);
                  break;
               default:
                  break;
            }

            currPlayer++;
         }
      } 
      
      else if (turn == 2) {
         myDeck.dealHand(dealerCards, 3); // Give the dealer 3 cards
         for (auto it = activePlayers.begin(); it != activePlayers.end(); it++) {
            system("clear");
            cout << it->first << ", press any key and then enter to view your hand with the cards on the table: ";
            cin >> tempS;
            switch (currPlayer) {
               case 1:
                  myDeck.viewHand(player1Cards, dealerCards);
                  break;
               case 2:
                  myDeck.viewHand(player2Cards, dealerCards);
                  break;
               case 3:
                  myDeck.viewHand(player3Cards, dealerCards);
                  break;
               default:
                  break;
            }
            currPlayer++;
         }
      }
      
      else if(turn == 3){
         dealerCards.push_front(myDeck.dealCard()); // Give the dealer 1 more card
         for (auto it = activePlayers.begin(); it != activePlayers.end(); it++) {
            system("clear");
            cout << it->first << ", press any key and then enter to view your hand with the cards on the table: ";
            cin >> tempS;
            switch (currPlayer) {
               case 1:
                  myDeck.viewHand(player1Cards, dealerCards);
                  break;
               case 2:
                  myDeck.viewHand(player2Cards, dealerCards);
                  break;
               case 3:
                  myDeck.viewHand(player3Cards, dealerCards);
                  break;
               default:
                  break;
            }
            currPlayer++;
         }
      }
      
      else if(turn == 4){
         dealerCards.push_front(myDeck.dealCard()); // Give the dealer 1 more card
         for (auto it = activePlayers.begin(); it != activePlayers.end(); it++) {
            system("clear");
            cout << it->first << ", press any key and then enter to view your hand with the cards on the table: ";
            cin >> tempS;
            switch (currPlayer) {
               case 1:
                  myDeck.viewHand(player1Cards, dealerCards);
                  break;
               case 2:
                  myDeck.viewHand(player2Cards, dealerCards);
                  break;
               case 3:
                  myDeck.viewHand(player3Cards, dealerCards);
                  break;
               default:
                  break;
            }
            currPlayer++;
         }
      }

      turn++;
   }

   void raise(string raiser) {
      char tempC;
      for (auto itr = activePlayers.begin(); itr != activePlayers.end(); itr++) {
         if (itr->first != raiser) {
            while (tempC != 'y' && tempC != 'n') {
               cout << itr->first << ", would you like to match the raise of " << highBet << "? 'y' or 'n': ";
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cin >> tempC;
            }
            if (tempC == 'y') {
               if (itr->second >= highBet) {
                  itr->second -= highBet;
               } else {
                  cout << "All in!" << endl;
                  pot += itr->second;
                  itr->second = 0;
               }
            }
            if (tempC == 'n') {
               players[itr->first] = itr->second;
               cout << itr->first << " is out of the game!" << endl;
               activePlayers.erase(itr->first);
            }\
            tempC = ' ';
         }
      }
   }
};

#endif /* Table.h */

