#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// Functions

// Function for waiting for time (Time in seconds)
void wait(double seconds) {
    int start = clock();
    while (clock() - start < (seconds * 1000)) {}
}

// Console cleaning function
void screenClear() {
    system("cls");
}

short getDifficulty() {
    return 0;
}

string getLanguage() {
    return "";
}

short saveConfig(short difficulty, string language) {
    return 0;
}

short getRandomNumber(short from, short to) {
    srand(time(NULL));
    return (rand() % to) + from;
}

string getRandomWord(short difficulty, string language, short randomNumber) {
    // Words

    string wordsEn1Difficulty[30] = {};
    string wordsEn2Difficulty[30] = {};
    string wordsEn3Difficulty[30] = {};

    string wordsBg1Difficulty[30] = {};
    string wordsBg2Difficulty[30] = {};
    string wordsBg3Difficulty[30] = {};

    string wordsRu1Difficulty[30] = {};
    string wordsRu2Difficulty[30] = {};
    string wordsRu3Difficulty[30] = {};

    switch (difficulty) {
        case 1:
            if (language == "en") {
                return wordsEn1Difficulty[randomNumber];
            }
            else if (language == "bg") {
                return wordsBg1Difficulty[randomNumber];
            }
            else if (language == "ru") {
                return wordsRu1Difficulty[randomNumber];
            }
            else {
                cout << "Incorrect language, try again";
            }
            break;

        case 2:
            if (language == "en") {
                return wordsEn2Difficulty[randomNumber];
            }
            else if (language == "bg") {
                return wordsBg2Difficulty[randomNumber];
            }
            else if (language == "ru") {
                return wordsRu2Difficulty[randomNumber];
            }
            else {
                cout << "Incorrect language, try again";
            }
            break;

        case 3:
            if (language == "en") {
                return wordsEn3Difficulty[randomNumber];
            }
            else if (language == "bg") {
                return wordsBg3Difficulty[randomNumber];
            }
            else if (language == "ru") {
                return wordsRu3Difficulty[randomNumber];
            }
            else {
                cout << "Incorrect language, try again";
            }
            break;
    }
}

void showMainMenu() {

}

void displayWordState(char openedLetters[], string word) {

}

void startGameWithBot(string word) {

}

bool checkLetter(char letter, char openedLetters[], string word) {
    return 0;
}

bool isWordGuessed(char openedLetters[], string word) {
    return 0;
}

void chooseLanguage() {

}

void chooseDifficulty() {

}

void settingsMenu() {

}

// Main

int main() {
    bool running = true;
    string language = getLanguage();
    short difficulty = getDifficulty();

    while (running) {
        showMainMenu();
        short input;
        cin >> input;

    }
    return 0;
}