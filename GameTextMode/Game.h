#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Game {

private:
    string title;
    int yearCreated;
    vector<string> instructions;
public:
    // Default constructor
    Game();

    // Parameterized constructor
    Game(const string& title, int year);

    // Setters
    void setTitle(const string& title);
    void setYearCreated(int year);

    // Getters
    string getTitle() const;
    int getYearCreated() const;
    vector<string> getInstructions() const;

    // Methods to modify instructions
    void addInstruction(const string& instruction);
    void printInstructions() const;
};