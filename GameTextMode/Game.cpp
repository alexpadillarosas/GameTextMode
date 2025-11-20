#include "Game.h"

Game::Game() {
    this->title = "Unknown";
    this->yearCreated = 2025;
}

Game::Game( string t, int year)  {
    this->title = t;
    this->yearCreated = year;
}

void Game::setTitle( string t) {
    title = t;
}

void Game::setYearCreated(int year) {
    yearCreated = year;
}

string Game::getTitle()  {
    return title;
}

int Game::getYearCreated()  {
    return yearCreated;
}

vector<string> Game::getInstructions()  {
    return instructions;
}

void Game::addInstruction( string instruction) {
    instructions.push_back(instruction);
}

void Game::printInstructions()  {
    cout << "Instructions for " << title << ":" << endl;
    for (int i = 0; i < instructions.size(); i++) {
        cout << i + 1 << ". " << instructions[i] << endl;
    }
}