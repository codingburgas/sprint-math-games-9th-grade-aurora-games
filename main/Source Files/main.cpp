#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../Header Files/globals.h"
#include "../Header Files/main.h"
#include "../Header Files/utils.h"
#include "../Header Files/words.h"
#include "../Header Files/game.h"
using namespace std;
string difficulty;
string language;

void rulesMenu() {
    screenClear();
    cout << R"(
           +------------------------------------------------------+
           |               R U L E S   O F   T H E   G A M E      |
           +------------------------------------------------------+
           |                                                      |
           |  Players guess a 7-letter word by spinning a wheel.  |
           |  A correct letter guess earns points and continues   |
           |  the turn.                                           |
           |                                                      |
           |  WHEEL SECTIONS:                                     |
           |                                                      |
           |  - Points (350-950): Guess a letter for points.      |
           |  - 'B' (Bankrupt): Lose all points. Turn ends.       |
           |  - 'S' (Skip): Turn is passed.                       |
           |  - '+' (Plus): Reveal one letter for free. Turn ends.|
           |                                                      |
           |  GUESSING:                                           |
           |                                                      |
           |  Players can guess a letter or the full word.        |
           |  A correct word guess is an IMMEDIATE WIN.           |
           |  An incorrect word guess is an IMMEDIATE LOSS.       |
           |                                                      |
           |  1) Exit                                             |
           +------------------------------------------------------+
)" << endl;
}

void chooseLanguage() {
    screenClear();
    int input;
    cout << R"(
                        +----------------------------+
                        |       LANGUAGE SELECT      |
                        +----------------------------+
            
                        |  1) English                |
                        |  2) Bulgarian              |
                        |  3) Russian                |
                        |  4) Back                   |
                        +----------------------------+
    )";
    cout << "> ";
    cin >> input;

    switch (input) {
    case 1:
        language = "en";
        break;
    case 2:
        language = "bg";
        break;
    case 3:
        language = "ru";
        break;
    case 4:
        settingsMenu();
        break;
    }

    settingsMenu();
}

void chooseDifficulty() {
    screenClear();
    int input;
    cout << R"(
                        +----------------------------------------------------------+
                        |                    DIFFICULTY LEVEL                      |
                        +----------------------------------------------------------+
                        |  1) Easy (Common vocabulary)                             |
                        |  2) Normal (Intermediate difficulty)                     |
                        |  3) Hard (Complex vocabulary)                            |
                        |  4) Back                                                 |
                        +----------------------------------------------------------+
)";
    cout << ">";
    cin >> input;

    switch (input) {
    case 1:
        difficulty = "1";
        break;
    case 2:
        difficulty = "2";
        break;
    case 3:
        difficulty = "3";
        break;
    case 4:
        settingsMenu();
    }

    settingsMenu();
}

void settingsMenu() {
    screenClear();
    int input;
    cout << R"(
                        +----------------------------+
                        |          SETTINGS          |
                        +----------------------------+
                        |  1) Change Language        |
                        |  2) Change Difficulty      |
                        |  3) Back                   |
                        +----------------------------+
)";
    cout << "> ";
    cin >> input;

    switch (input) {
    case 1:
        chooseLanguage();
        break;
    case 2:
        chooseDifficulty();
        break;
    case 3:
        showMainMenu();
        break;
    }
}

void showBeforeGameMenu() {
    screenClear();
    cout << R"(
                    +----------------------------+
                    |         MAIN MENU          |
                    +----------------------------+
                    |  1) Play with a bot        |
                    |  2) Play PvP               |
                    |  3) Exit                   |
                    +----------------------------+
                    |  >                         |
                    +----------------------------+
)" << endl;
}

void exitInMainMenu() {
    screenClear();
    showMainMenu();
}

void startGame() {
    short input;
    bool running = true;

    short randomNumber = getRandomNumber(0, 14);
    string word = getRandomWord(difficulty, language, randomNumber),
        hint = getHintForRandomWord(difficulty, language, randomNumber);

    showBeforeGameMenu();
    cin >> input;
    switch (input) {
    case 1:
        startGameWithBot(word, hint);
        break;
    case 2:
        startGame1v1(word, hint);
        break;
    case 3:
        exitInMainMenu();
        break;
    }
}

void showMainMenu() {
    screenClear();
    cout << R"(
                        +----------------------------+
                        |       WHEEL OF WORDS       |
                        +----------------------------+
                        |  1) Start Game             |
                        |  2) Settings               |
                        |  3) Rules                  |
                        |  4) Exit                   |
                        +----------------------------+
    )";
    cout << "> ";

    short input;
    bool running = true;
    while (running) {
        cin >> input;
        switch (input) {
        case 1: // Play
            startGame();
            showMainMenu();
            break;
            
        case 2: // Options
            settingsMenu();
            break;
        case 3: // Rules
            rulesMenu();
            cout << "> ";
            cin >> input;
            showMainMenu();
            break;
            
        case 4: // Exit
            running = false;
            return;
        default: // Incorrect input;
            
            cout << "Incorrect input, try again > ";
            break;
        }
    }
    screenClear();
}
int main() {
    system("chcp 1251 >nul");
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    putData();
    showMainMenu();
    return 0;
}