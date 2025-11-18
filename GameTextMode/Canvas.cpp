#include "Canvas.h"

/**
* prints out bricks in a row
* n : the number of bricks to print
* changeLine : true = change line
*/
void Canvas::printBricksRowOf(int n, bool changeLine) {
	char brick = 178;
	for (int i = 0; i < n; i++)
	{
		cout << brick;
	}
	if (changeLine == true) {
		cout << endl;
	}
}

void Canvas::printJustified(string text, int width, Justification justify)  // 0 justified left, 1 = justified centered, 2 = right
{
	if (width < 0) return;

	int textLength = text.length();
	int totalPadding = width - textLength;

	if (totalPadding < 0) {
		//if text is longer than width, truncate it
		cout << text.substr(0, width) << endl;
		return;
	}

	int leftPadding = 0;
	int rightPadding = 0;

	switch (justify)
	{
	case Left:
		leftPadding = 0;
		rightPadding = totalPadding;
		break;
	case Centre:
		leftPadding = totalPadding / 2;
		rightPadding = totalPadding - leftPadding;
		break;
	case Right:
		rightPadding = 0;
		leftPadding = totalPadding;
		break;
	}
	//print 1 brick
	printBricksRowOf(1, false);
	if (justify == Left) { //there is no left padding so the 2 characters for the bricks must be subtracted from the right
		rightPadding = rightPadding - 2;
	}

	if (justify == Right) {//there is no right padding so the 2 characters for the bricks must be subtracted from the left
		leftPadding = leftPadding - 2;
	}

	if (justify == Centre) {//subtract 1 character from the left (to be used by the left brick) and 1 from the right
		leftPadding--;
		rightPadding--;
	}

	//print left padding
	cout << string(leftPadding, ' ');
	//print text
	cout << text;
	//right padding
	cout << string(rightPadding, ' ');
	//print right brick
	printBricksRowOf(1, false);
	cout << endl;

}

void Canvas::printHeader(string text, int width) {

	printBricksRowOf(width, true);
	printJustified(text, width, Centre);
	printBricksRowOf(width, true);
}

void Canvas::printWelcomeScreen(string title, string subtitle, string description){
    clearScreen();
    printHeader(title,this->width);
    printJustified("", this->width, Centre);
    printJustified(subtitle, this->width, Centre);
    printJustified("", this->width, Centre);
    printJustified("", this->width, Centre);
    
    //break the string into small chunks
    int size = description.length();
    // since we have screens of 80 characters per row
    // we can place 78 characters in a row as we need another 2 for the screen borders
    // let's give another 4 chars on each side, so available for content 78 - 8 = 70
    // divide the string in portions of 70 characters
    int content_length = (this->width - 2 - 8);
    int num_rows = size / content_length;
    if (size % content_length != 0 ){
        num_rows++;
    }
    // cout << num_rows<<endl;
    int lineChars = this->width - 10;
    
    for(int i=0; i < num_rows; i++){
        // string line = description.substr(70*i, 70);
        string line = description.substr(lineChars*i, lineChars);
        // cout << endl;
        // cout << line << endl;
        printJustified(line, this->width, Centre);
    }
    printJustified("", this->width, Centre);
    printJustified("", this->width, Centre);
    printBricksRowOf(this->width, true);
    pressEnterToContinue();
}

Canvas::Canvas(){
    
}

Canvas::Canvas(int width){
    this->width = width;
}

void Canvas::pressEnterToContinue(){
	cout << "\nPress Enter to continue...";
	if (cin.peek() == '\n')  // check if newline already in buffer
		cin.ignore();
	else
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Canvas::printASCIIfromFile(string fileName){
    string line = "";
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.is_open()){
        while(getline(inFile, line))
        {
            cout<< line << endl;
        }
        
    }else{
        cout << "File failed to load. "<< endl;
        cout << "Image not displayed." << endl;
    }
    inFile.close ();
}

void Canvas::printASCIIArt(string filename) {
	clearScreen();
	printASCIIfromFile(filename);
	pressEnterToContinue();
}

void Canvas::clearScreen(){
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Linux/macOS
    #endif
}

void Canvas::doNothing() {
	cout << "Do Nothing";
}

void Canvas::printScreen(const string& title, const string& content)
{
    clearScreen();  // optional, remove if you don't want auto-clear
    printHeader(title, this->width);
    printJustified("", this->width, Centre);

    // Split `content` into lines by '\n' and print each within the border
    string line;
    stringstream ss(content);
    while (getline(ss, line)) {
        // If a line is too long, wrap it
        int maxLineLength = this->width - 10; // a bit of margin inside the frame
        for (size_t i = 0; i < line.length(); i += maxLineLength) {
            string sub = line.substr(i, maxLineLength);
            printJustified(sub, this->width, Centre);
        }
    }

    printJustified("", this->width, Centre);
    printBricksRowOf(this->width, true);
    pressEnterToContinue();
    
}

/**
 * @brief Print the Scoreboard using the generic function print screen.
 *
 * @param title Screen title
 * @param content Content to display, a whole string with new lines to separate rows.
 * @return nothing
 */
void Canvas::printScoreboard(const string& title, const string& content)
{
    printScreen(title, content);  // Reuse the printScreen function
}
void Canvas::printMainMenu()
{
    clearScreen();
    printHeader("Calculator", this->width);
    printJustified(" 1: Instructions", this->width, Left);
    printJustified(" 2: Play the Game", this->width, Left);
    printJustified(" 3: Scoreboard", this->width, Left);
    printJustified(" 4: Exit", this->width, Left);
    printBricksRowOf(this->width, true);
	//Do not wait for user input here(press enter to continue..), we will manage it in the main game loop
}

void Canvas::printScreenInvalidOption() {
    clearScreen();
    printHeader("Invalid Option", this->width);
    printJustified("", this->width, Centre);
    printJustified("", this->width, Centre);
    printJustified("Select a number between 1 and 4", this->width, Centre);
    printJustified("", this->width, Centre);
    printJustified("", this->width, Centre);
    printBricksRowOf(this->width, true);
    pressEnterToContinue();
}

/**
 * @brief Print a screen .
 *
 * @param title Title for the screen
 * @param subtitle Subtitle for the screen
 * @param content Vector of strings representing the content lines
 * @return nothing
 */
void Canvas::printScreenWithContent(string title, string subtitle, vector<string> content) {
    clearScreen();
    printHeader(title, this->width);
    printJustified(subtitle, this->width, Centre);
    printBricksRowOf(this->width, true);
    for (const auto& line : content) {
        printJustified(line, this->width, Centre);
    }
    printBricksRowOf(this->width, true);
    pressEnterToContinue();
}

string Canvas::printScoreboardInputPlayer() {
    string nickname;
    clearScreen();

    printHeader("Enter Your Nickname", this->width);
    printJustified("", this->width, Centre);
    printJustified("Please type your nickname and press Enter:", this->width, Centre);
    printJustified("", this->width, Centre);
    printBricksRowOf(this->width, true);

    // Input field (no borders)
    cout << "Nickname: ";

    // Clean input buffer just in case
    if (cin.peek() == '\n')
        cin.ignore();

    getline(cin, nickname);

    // Optional: validate empty nicknames
    while (nickname.empty()) {
        cout << "Nickname cannot be empty. Please enter again: ";
        getline(cin, nickname);
    }

    printJustified("", this->width, Centre);
    printBricksRowOf(this->width, true);

    cout << "\nNickname saved! Press Enter to continue...";
    return nickname;

}