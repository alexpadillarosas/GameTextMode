#include "Player.h"
#include <ctime>
#include <string>

Player::Player() {

	score = 0;
	
	srand(time(NULL));
	// 60 to 99, rand() -> 0 and 1
	int temp = rand() % 40 + 600000;
	nickname = to_string(temp);
	
}

Player::Player(string nickname, string name, int score) {
    this->nickname = nickname;
    this->name = name;
    this->score = score;
}

void Player::addScore(int points) {
	score = score + points;
}


