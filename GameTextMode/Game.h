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
    Game( string title, int year);

    // Setters
    void setTitle( string title);
    void setYearCreated(int year);

    // Getters
    string getTitle() ;
    int getYearCreated() ;
    vector<string> getInstructions() ;

    // Methods to modify instructions
    void addInstruction( string instruction);
    void printInstructions() ;
};