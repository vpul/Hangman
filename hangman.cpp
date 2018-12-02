#include <iostream>
#include <string>
#include <vector> //For push & pop function
#include <algorithm>  //For using find() function
#include <fstream> //For retriving word from files
#include <stdlib.h> //For random number
#include <ctime> //To provide time as random seed

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
    #ifdef _WIN32
        system("CLS");
    #else      //for Linux and Mac
        system("clear");
    #endif
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
int gameWon = 0;

int generateWord(string secretWord, char guessedChar) {  
    cout<<"\nSecret Word: ";
    int guessedCharExits = 0;
    int noOfUnderscores = 0;
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guessedChar && secretWord[i] != '-') {
            cout << guessedChar << " ";
            guessedCharExits = 1;
        } else if (find(correctChars.begin(), correctChars.end(), secretWord[i]) != correctChars.end()) {
            cout << secretWord[i] << " ";
        } else {
            if (secretWord[i] == '-') {
                cout << "- ";
            } else {
                cout << "_ ";
                noOfUnderscores++;
            }
        } 
    }
    cout<<"\n\n";

    if(noOfUnderscores == 0) {
        gameWon = 1;
    }

    if (guessedChar == ' ' || guessedChar == '-') {
        return 0;
    }

    if (guessedCharExits == 0) {
        if (find(misses.begin(), misses.end(), guessedChar) == misses.end()) {
            misses.push_back(guessedChar);
            life++;
        }
    } else if (find(correctChars.begin(), correctChars.end(), guessedChar) == correctChars.end()) {
        correctChars.push_back(guessedChar);
    }
}

// void printCorrectChars() {
//     cout << "correctChars:";
//     for (int i = 0; i < correctChars.size(); i++) {
//         cout << correctChars[i] << " ";
//     }
//     cout << "\n";
// }


string getSecretWord(int catagory) {
    string wordlistFiles[] = {"months", "colors", "tech_companies", "automobile_companies", "countries", "foods", "fruits", "movies", "tv_series", "sports"};

    string line;
    vector<string> wordListArray;
    //For C++ 1997 Compiler
    //ifstream wordList((wordlistFiles[catagory-1] + ".txt").c_str());
    ifstream wordList(wordlistFiles[catagory - 1] + ".txt");
    if (wordList.is_open()) {
        int i = 0;
        while (getline(wordList, line)) {
            wordListArray.push_back(line);
            i++;
        }
        wordList.close();
        srand(time(NULL));
        return wordListArray[rand() % i];
    } else {
        cout << "Unable to open file";
    }
}


int main() {
    char guessedChar = ' ';
    generateGameTitle();
    string catagories[] = {"Months", "Colors", "Tech Comanies", "Automobile Companies", "Countries", "Foods", "Fruits", "Movies", "TV Series", "Sports"};
    cout << "Catagories:\n";
    int catagoriesLength = (sizeof(catagories)/sizeof(catagories[0]));
    for (int i = 1; i <= catagoriesLength; i++) {
        cout<< i <<". " << catagories[i-1] << "\n";
    }
    cout << "\nChoose a number corresponding to the catagory: ";
    int catagory;
    cin >> catagory;
    string secretWord = getSecretWord(catagory);

    do {
        clrscr();
        generateGameTitle();
        generateWord(secretWord, guessedChar);
        printMisses();
        //printCorrectChars();
        hangmanLife(life);
        if (life >= 6) {
            cout << "\nYou lost. The secret word is " << secretWord << ".\n";
            break;
        } else if (gameWon == 1) {
            cout << "\n"
            " __   __        __   __       ___                ___    __        __    /        __                __\n"        
            "/  ` /  \\ |\\ | / _` |__)  /\\   |  |  | |     /\\   |  | /  \\ |\\ | /__`  /    \\ / /  \\ |  |    |  | /  \\ |\\ |\n"  
            "\\__, \\__/ | \\| \\__> |  \\ /~~\\  |  \\__/ |___ /~~\\  |  | \\__/ | \\| .__/ .      |  \\__/ \\__/    |/\\| \\__/ | \\|\n";
            break;
        }
        cout << "\nPick a letter: ";
        cin >> guessedChar;
        guessedChar = tolower(guessedChar);
    } while((int)guessedChar != 27);
    return 0;
}