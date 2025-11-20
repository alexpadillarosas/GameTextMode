#pragma once
#include <iostream>
#include <cstdlib> // Required for system()
#include <limits>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Player.h"

using namespace std;

enum Justification { Left, Centre, Right };

class Canvas {
public:
	
	string title;
	string footer;
	int width;

	
	Canvas();
	Canvas(int width);
	void printBricksRowOf(int n, bool changeLine);
	void printJustified(string text, int width, Justification justify);
	void printHeader(string text, int width);
    void printWelcomeScreen(string title, string subtitle, string description);
    void pressEnterToContinue();
    void clearScreen();
    void printASCIIfromFile(string fileName);
	void printASCIIArt(string filename);
	void printScreen( string title,  string content);
	void printScoreboard( string title,  string content);
	void printMainMenu();
	void printScreenInvalidOption();
	void printScreenWithContent(string title, string subtitle, vector<string> content);
	string printScoreboardInputPlayer();

private:
	void doNothing();
};