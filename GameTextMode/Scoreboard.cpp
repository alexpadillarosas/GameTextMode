#include "Scoreboard.h"

bool Scoreboard::readPlayersFromFile( string filename, vector<Player>& players) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nickname, name, scoreStr;

        if (getline(ss, nickname, '-') &&
            getline(ss, name, '-') &&
            getline(ss, scoreStr)) {
            
            try {
                int score = stoi(scoreStr);
                Player player(nickname, name, score);
                // p.nickname = nickname;
                // p.name = name;
                // p.score = score;

                players.push_back(player);
            } catch (const invalid_argument&) {
                cerr << "Invalid score format in line: " << line << endl;
            }
        } else {
            cerr << "Invalid line format: " << line << endl;
        }
    }

    file.close();
    return true;
}

string Scoreboard::buildScoreboardString( vector<Player>& players) {
    stringstream ss;
    //setw(n) reserves 'n' positions of lenght, inside will send text
    ss << left << setw(15) << "Nickname" 
       << left << setw(25) << "Name" 
       << right << setw(10) << "Score" << endl;
    ss << string(50, '-') << endl;  //string(x, char)  creates a string of n characters containing the value of 'char'
    for (const auto& player : players) {
        ss << left << setw(15) << player.nickname
           << left << setw(25) << player.name
           << right << setw(10) << player.score << endl;
    }
    return ss.str();
}

void Scoreboard::storeEntry( string nickname,  string name, int points) {
    ofstream file("leaderboard.txt", ios::app); // Open in append mode
    if (!file.is_open()) {
        cerr << "Error: Could not open file leaderboard.txt for writing." << endl;
        return;
    }
    file << nickname << "-" << name << "-" << points << endl;
    file.close();
}

void Scoreboard::sortPlayersByScore(vector<Player>& players) {
    sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.score > b.score; // Sort in descending order
        });
}
