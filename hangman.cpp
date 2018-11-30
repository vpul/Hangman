#include <iostream>
#include <string>
#include <vector> //For push & pop function
#include <algorithm>  //For using find() function
using namespace std;

void generateGameTitle() {
    cout <<
        " _    _\n"
        "| |  | |\n"
        "| |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __\n"
        "|  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\\n"
        "| |  | | (_| | | | | (_| | | | | | | (_| | | | | \n"
        "|_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n"
        "                     __/ | \n"
        "                    |___/  \n";
}

void hangmanLife(int n) {
    string hangmanArt[] = {
        "_________\n"
        "|/      |\n"
        "|        \n"
        "|        \n"
        "|        \n"
        "|        \n"
        "|        \n"
        "|        \n",

        "_________ \n"
        "|/      | \n"
        "|      (_)\n"
        "|         \n"
        "|         \n"
        "|         \n"
        "|         \n"
        "|         \n",

        "_________ \n"
        "|/      | \n"
        "|      (_)\n"
        "|       | \n"
        "|       | \n"
        "|         \n"
        "|         \n"
        "|         \n",

        "_________ \n"
        "|/      | \n"
        "|      (_)\n"
        "|      \\| \n"
        "|       | \n"
        "|         \n"
        "|         \n"
        "|         \n",

        "_________ \n"
        "|/      | \n"
        "|      (_)\n"
        "|      \\|/\n"
        "|       | \n"
        "|         \n"
        "|         \n"
        "|         \n",

        "_________ \n"
        "|/      | \n"
        "|      (_)\n"
        "|      \\|/\n"
        "|       | \n"
        "|      /  \n"
        "|         \n"
        "|         \n",

        "_________ \n"
        "|/      | \n"
        "|      (_)\n"
        "|      \\|/\n"
        "|       | \n"
        "|      / \\\n"
        "|         \n"
        "|         \n"
    };
    cout << hangmanArt[n];
}

void clrscr() {
    cout << "\033[2J\033[1;1H";
}

vector<char> correctChars;
vector<char> misses;

void printMisses() {
    cout << "Misses: ";
    for (int i = 0; i < misses.size(); i++) {
        cout << misses[i] << " ";
    }
    cout << "\n";
}


int life = 0;

int generateWord(string secretWord, char guessedChar) {
    if (guessedChar == ' ') {
        return 0;
    }

    cout<<"\nSecret Word: ";
    int guessedCharExits = 0;
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guessedChar) {
            cout << guessedChar << " ";
            guessedCharExits = 1;
        } else if (find(correctChars.begin(), correctChars.end(), secretWord[i]) != correctChars.end()) {
            cout << secretWord[i] << " ";
        } else {
            cout << "_ ";
        } 
    }
    cout<<"\n\n";
    if (guessedCharExits == 0 && (find(misses.begin(), misses.end(), guessedChar) == misses.end())) {
        misses.push_back(guessedChar);
        life++;
    } else if (find(correctChars.begin(), correctChars.end(), guessedChar) == correctChars.end()) {
        correctChars.push_back(guessedChar);
    }
}

void printCorrectChars() {
    cout << "correctChars:";
    for (int i = 0; i < correctChars.size(); i++) {
        cout << correctChars[i] << " ";
    }
    cout << "\n";
}

int main() {
    char guessedChar = ' ';

    string secretWord = "abacus";
    
    do {
        clrscr();
        generateGameTitle();
        generateWord(secretWord, guessedChar);
        printMisses();
        printCorrectChars();
        hangmanLife(life);
        if (life >= 6) {
            cout << "\nYou lost. Better luck next time.";
            break;
        } else if (correctChars.size() == secretWord.length()) {
            cout << "\n"
            " __   __        __   __       ___                ___    __        __    /        __                __\n"        
            "/  ` /  \\ |\\ | / _` |__)  /\\   |  |  | |     /\\   |  | /  \\ |\\ | /__`  /    \\ / /  \\ |  |    |  | /  \\ |\\ |\n"  
            "\\__, \\__/ | \\| \\__> |  \\ /~~\\  |  \\__/ |___ /~~\\  |  | \\__/ | \\| .__/ .      |  \\__/ \\__/    |/\\| \\__/ | \\|";
            break;
        }
        cout << "\nPick a letter: ";
        cin >> guessedChar;
    } while((int)guessedChar != 27);
    return 0;
}


//Check if game finished
//Avoid repetation of misses
//Fix bug places misses on correctChars