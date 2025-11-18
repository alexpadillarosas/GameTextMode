#include <iostream>
#include "Canvas.h"
#include "Player.h"
#include <string>

#include <cstdlib>

#include <fstream>
#include <vector>
#include "Scoreboard.h"
#include "Game.h"
using namespace std;

//for the images: https://www.asciiart.eu/


void showMenu();
void showBanner();
void showScoreboard();
void showWelcomeScreen();
void showInvalidOptionScreen();
void showInstructions();
void startGame();

int main()
{
	//these 2 options are outside of the loop, as we will only show it when the user starts the program.
	showBanner();
	showWelcomeScreen();

	int option;
	do {
		showMenu();
		cout << "Select and option: " << endl;
		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover newline when the user input the option

		if (option == 1) {
			showInstructions();
		}
		else if (option == 2) {
			// call a function play game
			//TODO: add your game function inside startGame()
			startGame();
		}
		else if (option == 3) {
			// call a function to display the scoreboard
			showScoreboard();
		}
		else if (option == 4) {
			// quit the game
			cout << "Bye" << endl;
			break;
		}
		else { // to check invalid selected options
			showInvalidOptionScreen();
		}
	} while (true);

}

void showMenu() {
	Canvas myCanvas(120);
	myCanvas.printMainMenu();
}

void showBanner() {
	Canvas myCanvas(120);
	myCanvas.printASCIIArt("Image.txt");
}

void showWelcomeScreen() {
	Canvas myCanvas(120);
	string description = "Space Invaders is considered one of the most influential and greatest video games of all time, having ushered in the golden age of arcade video games and Japan's long-lasting global success in the video games industry.It inspired several prolific game designers to join the industry and influenced numerous games across different genres.";
	myCanvas.printWelcomeScreen("Welcome", "Space Invaders", description);
}

void showScoreboard() {

	Scoreboard scoreboard;
	vector<Player> players;
	string filename = "leaderboard.txt";

	scoreboard.readPlayersFromFile(filename, players);// load players vector with data from file
	scoreboard.sortPlayersByScore(players);
	string content = scoreboard.buildScoreboardString(players); // build a string with the info from the players' vector

	Canvas myCanvas(120);
	myCanvas.printScoreboard("SCOREBOARD", content);	// display the string using canvas class

}

void showInvalidOptionScreen() {
	Canvas myCanvas(120);
	myCanvas.printScreenInvalidOption();
}


/**
 * @brief Shows the instruction screen.
 * @return nothing
 */
void showInstructions() {
	
	Game game("Space Invaders", 2025);
	game.addInstruction("1) Set up the pieces");
	game.addInstruction("2) Complete the puzzle");
	game.addInstruction("3) Quit as soon as you can");
	
	Canvas myCanvas(120);
	string title = game.getTitle() + " @" + to_string(game.getYearCreated());
	myCanvas.printScreenWithContent(title, "Instructions", game.getInstructions());
}

void startGame() {
	int currentScore = 70;
	// plug in here your game code function and make it return the score the player got
	//TODO:

	//This is to add the user to the hall of fame.
	Scoreboard scoreboard;
	Canvas myCanvas(120);
	//we only store the user if it has score more than the minimum points
	if (currentScore > scoreboard.minScoreToEnter) {

		string nickname = myCanvas.printScoreboardInputPlayer();
		//save the new entry in the file
		scoreboard.storeEntry(nickname, "", currentScore);
	}

}
