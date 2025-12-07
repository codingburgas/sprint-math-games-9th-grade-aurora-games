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
// Displays the rules of the game
void rulesMenu() {
    screenClear();
    cout << R"(
       +------------------------------------------------------+
       |             R U L E S   O F   T H E   G A M E        |
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
       |  - 'X' (Double): Doubles the current score.          |
       |                                                      |
       |  GUESSING:                                           |
       |                                                      |
       |  Players can guess a letter or the full word.        |
       |  A correct word guess is an IMMEDIATE WIN.           |
       |  An incorrect word guess is an IMMEDIATE LOSS.       |
       |                                                      |
       |  1) Exit                                             |
       +------------------------------------------------------+
       >)";
}
// Allows the user to choose a language
void chooseLanguage() {
    screenClear();
    char input;
    cout << R"(
                        +---------------------------------------+
                        |            LANGUAGE SELECT            |
                        +---------------------------------------+
                        |  1) English                           |
                        |  2) Bulgarian                         |
                        |  3) Russian                           |
                        |  4) Back                              |
                        +---------------------------------------+
                        > )";
    cin >> input;
    switch (input) {
    case '1':
        language = "en";
        putData(language, difficulty);
        break;
    case '2':
        language = "bg";
        putData(language, difficulty);
        break;
    case '3':
        language = "ru";
        putData(language, difficulty);
        break;
    case '4':
        break;
    default:
        chooseLanguage();
        break;
    }
	settingsMenu();
}
// Allows the user to choose a difficulty level
void chooseDifficulty() {
    screenClear();
    char input;
    cout << R"(
                        +---------------------------------------+
                        |           DIFFICULTY LEVEL            |
                        +---------------------------------------+
                        |  1) Easy (Common vocabulary)          |
                        |  2) Normal (Intermediate difficulty)  |
                        |  3) Hard (Complex vocabulary)         |
                        |  4) Back                              |
                        +---------------------------------------+
                        > )";
    cin >> input;

    switch (input) {
    case '1':
        difficulty = "1";
        putData(language, difficulty);
        break;
    case '2':
        difficulty = "2";
        putData(language, difficulty);
        break;
    case '3':
        difficulty = "3";
        putData(language, difficulty);
        break;
    case '4':
        settingsMenu();
    default:
        chooseDifficulty();
        break;
    }
    settingsMenu();
}
// Displays the settings menu
void settingsMenu() {
    screenClear();
    char input;
    cout << R"(
                        +---------------------------------------+
                        |                SETTINGS               |
                        +---------------------------------------+
                        |  1) Change Language                   |
                        |  2) Change Difficulty                 |
                        |  3) Back                              |
                        +---------------------------------------+
                        > )";
    cin >> input;

    switch (input) {
    case '1':
        chooseLanguage();
        break;
    case '2':
        chooseDifficulty();
        break;
    case '3':
        showMainMenu();
        break;
    default:
        settingsMenu();
        break;
    }
}
// Displays the menu before starting the game
void showBeforeGameMenu() {
    screenClear();
    cout << R"(
                        +---------------------------------------+
                        |                MAIN MENU              |
                        +---------------------------------------+
                        |  1) Play with a bot                   |
                        |  2) Play PvP                          |
                        |  3) Exit                              |
                        +---------------------------------------+
                        > )";
}

void exitInMainMenu() {
    screenClear();
    showMainMenu();
}

void startGame() {
    char input;
    short randomNumber = getRandomNumber(0, 14);
    string word = getRandomWord(difficulty, language, randomNumber),
        hint = getHintForRandomWord(difficulty, language, randomNumber);

    showBeforeGameMenu();
    cin >> input;
    switch (input) {
    case '1':
        startGameWithBot(word, hint);
        break;
    case '2':
        startGame1v1(word, hint);
        break;
    case '3':
        exitInMainMenu();
        break;
    default:
        startGame();
        break;
    }
}
// Displays the main menu of the game
void showMainMenu() {
    screenClear();
    cout << R"(
                        +---------------------------------------+
                        |            WHEEL OF FORTUNE           |
                        +---------------------------------------+
                        |  1) Start Game                        |
                        |  2) Settings                          |
                        |  3) Rules                             |
                        |  4) Exit                              |
                        +---------------------------------------+
                        > )";
    char input;
    cin >> input;
    switch (input) {
    case '1': // Play
        startGame();
        showMainMenu();
        break;
    case '2': // Options
        settingsMenu();
        break;
    case '3': // Rules
        rulesMenu();
        cin >> input;
        showMainMenu();
        break;
    case '4': // Exit
        return;
    default: // Incorrect input;
        showMainMenu();
        break;
    }
    screenClear();
}
// Main function
int main() {
    system("chcp 1251 >nul");
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    getData();
    showMainMenu();
    return 0;
}