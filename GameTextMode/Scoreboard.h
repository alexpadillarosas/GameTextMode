#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Player.h"
#include <iomanip>

using namespace std;

class Scoreboard {
public:
	int minScoreToEnter = 60; // Minimum score required to enter the scoreboard

    bool readPlayersFromFile( string filename, vector<Player>& players);
    string buildScoreboardString(vector<Player>& players);
 	void storeEntry( string nickname,  string name, int points);
	void sortPlayersByScore(vector<Player>& players);


private:
// 	string fullname;

};