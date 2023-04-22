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

#include "Card.h"

using namespace std;

class DeckOfCards{
private:
   Card deck[52];
   int currentCard = 0;
   bool fullHouse(int f[]){
        bool pair3 = false;
        bool pair2 = false;
        for (int i = 0; i < 14; i++){
            if (f[i] == 2){
                pair2 = true;
            }
            if (f[i] == 3){
                pair3 = true;
            }
            if (pair2 && pair3){
                return true;
            }
        }
        return false;
    }

   bool straight(int f[]){
        int counter = 0;
        for (int i = 0; i < 14; i++){
            if (f[i] == 1){
                counter++;
            }
            else{
                counter = 0;
            }
            if (counter == 5){
                return true;
            }
        }
        return false;
    }

   bool flush(int s[]){
        for (int i = 0; i < 5; i++){
            if (s[i] == 5){
                return true;
            }
        }
        return false;
    }

   bool fourOfAKind(int f[]){
        for (int i = 0; i < 14; i++){
            if (f[i] == 4){
                return true;
            }
        }
        return false;
    }

   bool threeOfAKind(int f[]){
        for (int i = 0; i < 14; i++){
            if (f[i] ==3){
                return true;
            }
        }
        return false;
    }

   bool pair(int f[]){
        for (int i = 0; i < 14; i++){
            if (f[i] == 2){
                return true;
            }
        }
        return false;
    }
    
   bool twoPairs(int f[]){
        int pairCount = 0;
        for (int i = 0; i < 14; i++){
            if (f[i] >=2){
                pairCount++;
            }
            if (pairCount >= 2){
                return true;
            }
        }
        return false;
    }
public:
   DeckOfCards(){
        string faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"}; 
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"}; 

        // populate deck with Card objects 
        for (int i = 0; i < 52; i++) { 
            deck[i].setFace(faces[i % 13]);
            deck[i].setSuit(suits[i / 13]);
        }
    }
   
   void shuffle(){
        // next call to method dealCard should start at deck[0] again
        currentCard = 0; 
        srand(time(0));
        // for each Card, pick another random Card (0-51) and swap them
        for (int first = 0; first < 52; first++) {
            // select a random number between 0 and 51
            int second = rand() % 51;

            // swap current Card with randomly selected Card
            Card temp = deck[first]; 
            deck[first] = deck[second];
            deck[second] = temp;
        } 
    }
   
   Card dealCard() {
        // determine whether Cards remain to be dealt
        if (currentCard < 52) {
            return deck[currentCard++]; // return current Card in array
        } 
        else {
            return Card();
        } 
    }
   
   
   string evaluateHand(Card hand[]){

        int suitsFound[5] = {0,0,0,0,0};
        int facesFound[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        for (int i = 0; i < 5; i++){
           if (hand[i].getSuit() == "Hearts"){
              suitsFound[0]++;
           }
           else if (hand[i].getSuit() == "Clubs"){
              suitsFound[1]++;
           }
           else if (hand[i].getSuit() == "Spades"){
              suitsFound[2]++;
           }
           else if (hand[i].getSuit() == "Diamonds"){
              suitsFound[3]++;
           }
           else{
              suitsFound[4]++;
           }
            
           if (hand[i].getFace() == "Ace"){facesFound[0]++;}
           else if (hand[i].getFace() == "Deuce"){facesFound[1]++;}
           else if (hand[i].getFace() == "Three"){facesFound[2]++;}
           else if (hand[i].getFace() == "Four"){facesFound[3]++;}
           else if (hand[i].getFace() == "Five"){facesFound[4]++;}
           else if (hand[i].getFace() == "Six"){facesFound[5]++;}
           else if (hand[i].getFace() == "Seven"){facesFound[6]++;}
           else if (hand[i].getFace() == "Eight"){facesFound[7]++;}
           else if (hand[i].getFace() == "Nine"){facesFound[8]++;}
           else if (hand[i].getFace() == "Ten"){facesFound[9]++;}
           else if (hand[i].getFace() == "Jack"){facesFound[10]++;}
           else if (hand[i].getFace() == "Queen"){facesFound[11]++;}
           else if (hand[i].getFace() == "King"){facesFound[12]++;}
           else {facesFound[13]++;}    
        }
        for (int i = 0; i < 14; i++){
           cout << facesFound[i] << ' ';
        }
        cout << endl;
         for (int i = 0; i < 5; i++){
            cout << suitsFound[i] << ' ';
         }
        if (facesFound[13] != 0 || suitsFound[4] != 0){
            return "ERROR";
        }

        if (fullHouse(facesFound)){
            return "Full house!";
        }

        if (straight(facesFound)){
            return "Straight!";
        }

        if (flush(suitsFound)){
            return "Flush!";
        }

        if (fourOfAKind(facesFound)){
            return "Four of a kind!";
        }

        if (threeOfAKind(facesFound)){
            return "Three of a kind";
        }

        if (twoPairs(facesFound)){
            return "Two pairs";
        }

        if (pair(facesFound)){
            return "One pair";
        }
        
        return "Nothing";
   }
};
#endif /* DECKOFCARDS_H */

