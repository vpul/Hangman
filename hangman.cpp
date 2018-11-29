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

void generateWord(string secretWord, char guessedChar) {
    cout<<"\nSecret Word: ";
    int counter = 0;
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guessedChar) {
            cout << guessedChar << " ";
            counter++;
        } else {
            int counter2 = 0;
            for (int j = 0; j < correctChars.size(); j++) {
                if (secretWord[i] == correctChars[j]) {
                    cout << correctChars[j] << " ";
                    counter2++;
                    break;
                }
            }
            if (counter2 ==0){
                cout << "_ ";
            }
        } 
    }
    cout<<"\n\n";
    if (counter == 0  && guessedChar != ' ') {
        misses.push_back(guessedChar);
        life++;
    } else {
        correctChars.push_back(guessedChar);
    }
}

int main() {
    char guessedChar = ' ';

    string testWord = "abacus";
    
    do {
        clrscr();
        generateGameTitle();
        hangmanLife(life);
        generateWord(testWord, guessedChar);
        printMisses();
        if (life >= 6) {
            break;
        }
        cout << "\nPick a letter: ";
        cin >> guessedChar;
    } while((int)guessedChar != 27);

    cout << "\nYou lost the game. Better luck next time.";
    return 0;
}


//Check if game finished
//Avoid repetation of misses