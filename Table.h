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

using namespace std;

class Table {
private:
   map<string, int> players;
   map<string, list<int>> endingStats;
   list<int> player1Stats;
   list<int> player2Stats;
   list<int> player3Stats;
public:

   Table(int numPlayers) {
        int tempN;
        string tempS;
        cout << "Enter starting cash for all players: ";
        cin >> tempN;

        for (int i = 0; i < numPlayers; i++) { //Setting up player maps
            cout << "Enter player " << i + 1 << "'s name: ";
            cin >> tempS;
            players.insert(pair<string, int>(tempS, tempN));

            if (i == 0) {
                endingStats.insert(pair<string, list<int>>(tempS, player1Stats));
                player1Stats.push_back(tempN);
            }
            if (i == 1) {
                endingStats.insert(pair<string, list<int>>(tempS, player2Stats));
                player2Stats.push_back(tempN);
            }
            if (i == 2) {
                endingStats.insert(pair<string, list<int>>(tempS, player3Stats));
                player3Stats.push_back(tempN);
            }
        }
    }

    void printPlayers() {
        cout << "Player   Bank" << endl;
        cout << "-------------" << endl;
        for (auto pair : players) {
            cout << pair.first << " - $";
            cout << pair.second << endl;
        }
    }
   
   
};

#endif /* Table.h */

