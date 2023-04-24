/* 
 * File:   DeckOfCards.h
 * Author: Kyle
 *
 * Created on April 21, 2023, 5:13 PM
 */

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <random>       
#include <chrono>
#include <iterator>
#include <algorithm>

#include "Card.h"

using namespace std;

class DeckOfCards {
private:
   Card deck[52];
   queue<Card> shuffled;
   int currentCard = 0;

   bool fullHouse(int f[]) {
      bool pair3 = false;
      bool pair2 = false;
      for (int i = 0; i < 14; i++) {
         if (f[i] == 2) {
            pair2 = true;
         }
         if (f[i] == 3) {
            pair3 = true;
         }
         if (pair2 && pair3) {
            return true;
         }
      }
      return false;
   }

   bool straight(int f[]) {
      int counter = 0;
      for (int i = 0; i < 14; i++) {
         if (f[i] == 1) {
            counter++;
         } else {
            counter = 0;
         }
         if (counter == 5) {
            return true;
         }
      }
      return false;
   }

   bool flush(int s[]) {
      for (int i = 0; i < 5; i++) {
         if (s[i] == 5) {
            return true;
         }
      }
      return false;
   }

   bool fourOfAKind(int f[]) {
      for (int i = 0; i < 14; i++) {
         if (f[i] == 4) {
            return true;
         }
      }
      return false;
   }

   bool threeOfAKind(int f[]) {
      if (count(f, f + 14, 3)) {
         return true;
      }
      return false;
   }

   bool pair(int f[]) {
      if (count(f, f + 14, 2)) {
         return true;
      }
      return false;
   }

   bool twoPairs(int f[]) {
      int pairCount = 0;
      for (int i = 0; i < 14; i++) {
         if (f[i] >= 2) {
            pairCount++;
         }
         if (pairCount >= 2) {
            return true;
         }
      }
      return false;
   }
public:

   DeckOfCards() {
      string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six",
         "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
      string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
      int i = 0;
      // populate deck with Card objects 
      for (int i = 0; i < 52; i++) {
         deck[i].setFace(faces[i % 13]);
         deck[i].setSuit(suits[i / 13]);
      }
   }

   void shuffleDeck() {
      // resets dealCard counter
      currentCard = 0;
      random_shuffle(deck, deck + 52);

      for (auto it : deck) {
         shuffled.push(it);
      }
   }

   Card dealCard() {
      Card temp;
      if (currentCard >= 52) {
         shuffleDeck();
      }
      currentCard++;
      temp = shuffled.front();
      shuffled.pop();
      return temp;
   }

   void dealHand(list<Card> &playerHand, int amount) {
      for (int i = 0; i < amount; i++) {
         Card temp = dealCard();
         playerHand.push_front(temp);
      }
   }

   void viewHand(list<Card> hand) {
      for (auto it = hand.begin(); it != hand.end(); it++) {
         cout << it->toString() << endl;
      }
      cout << "When done viewing hand, enter any key and then enter to hide it from the next player.";
      string temp;
      cin >> temp;
      system("clear");
   }

   string evaluateHand(Card hand[]) {

      int suitsFound[5] = {0, 0, 0, 0, 0};
      int facesFound[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

      for (int i = 0; i < 5; i++) {
         if (hand[i].getSuit() == "Hearts") {
            suitsFound[0]++;
         } else if (hand[i].getSuit() == "Clubs") {
            suitsFound[1]++;
         } else if (hand[i].getSuit() == "Spades") {
            suitsFound[2]++;
         } else if (hand[i].getSuit() == "Diamonds") {
            suitsFound[3]++;
         } else {
            suitsFound[4]++;
         }

         if (hand[i].getFace() == "Ace") {
            facesFound[0]++;
         } else if (hand[i].getFace() == "Two") {
            facesFound[1]++;
         } else if (hand[i].getFace() == "Three") {
            facesFound[2]++;
         } else if (hand[i].getFace() == "Four") {
            facesFound[3]++;
         } else if (hand[i].getFace() == "Five") {
            facesFound[4]++;
         } else if (hand[i].getFace() == "Six") {
            facesFound[5]++;
         } else if (hand[i].getFace() == "Seven") {
            facesFound[6]++;
         } else if (hand[i].getFace() == "Eight") {
            facesFound[7]++;
         } else if (hand[i].getFace() == "Nine") {
            facesFound[8]++;
         } else if (hand[i].getFace() == "Ten") {
            facesFound[9]++;
         } else if (hand[i].getFace() == "Jack") {
            facesFound[10]++;
         } else if (hand[i].getFace() == "Queen") {
            facesFound[11]++;
         } else if (hand[i].getFace() == "King") {
            facesFound[12]++;
         } else {
            facesFound[13]++;
         }
      }

      if (facesFound[13] != 0 || suitsFound[4] != 0) {
         return "ERROR";
      }

      if (fullHouse(facesFound)) {
         return "Full house!";
      }

      if (straight(facesFound)) {
         return "Straight!";
      }

      if (flush(suitsFound)) {
         return "Flush!";
      }

      if (fourOfAKind(facesFound)) {
         return "Four of a kind!";
      }

      if (threeOfAKind(facesFound)) {
         return "Three of a kind";
      }

      if (twoPairs(facesFound)) {
         return "Two pairs";
      }

      if (pair(facesFound)) {
         return "One pair";
      }

      return "Nothing";
   }
};
#endif /* DECKOFCARDS_H */

