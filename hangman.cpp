#include <iostream>
#include <string>
#include <vector>
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

vector<string> correctChars;

void generateWord(string secretWord) {
    int wordLength = secretWord.length();
    cout<<"\nSecret Word: ";
    for (int i = 0; i < wordLength; i++) {
        cout << "_ ";
    }
    cout<<"\n";
}

void 

int main() {
    char guessedChar = 'x';

    string testWord = "abacus";

    int life = 0;
    do {
        clrscr();
        generateGameTitle();
        hangmanLife(life);
        generateWord(testWord);
        if (life >= 6) {
            break;
        }
        cout << "\nEnter a character: ";
        cin >> guessedChar;
        if(checkForPresence(guessedChar)) {
            correctChars.push_back(guessedChar);
        } else {
            life++;
        };
    } while((int)guessedChar != 27);

    cout << "\nYou lost the game. Better luck next time.";
    return 0;
}


//TODO Create check for presence()
//Possibly combint above function and generateWord()