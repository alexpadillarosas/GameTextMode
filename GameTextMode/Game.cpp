#include "Game.h"

Game::Game() {
    this->title = "Unknown";
    this->yearCreated = 2025;
}

Game::Game(const string& t, int year)  {
    this->title = t;
    this->yearCreated = year;
}

void Game::setTitle(const string& t) {
    title = t;
}

void Game::setYearCreated(int year) {
    yearCreated = year;
}

string Game::getTitle() const {
    return title;
}

int Game::getYearCreated() const {
    return yearCreated;
}

vector<string> Game::getInstructions() const {
    return instructions;
}

void Game::addInstruction(const string& instruction) {
    instructions.push_back(instruction);
}

void Game::printInstructions() const {
    cout << "Instructions for " << title << ":" << endl;
    for (int i = 0; i < instructions.size(); i++) {
        cout << i + 1 << ". " << instructions[i] << endl;
    }
}