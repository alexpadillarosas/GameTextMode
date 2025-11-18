#pragma once
#include <iostream>

using namespace std;

class Player {
public:
	string nickname;
	string name;
	int score;

	Player();
	Player(string nickname, string name, int score);

	
	void addScore(int points);

private:
	string fullname;

};