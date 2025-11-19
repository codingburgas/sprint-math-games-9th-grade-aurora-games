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

string getRandomWord(string words[]) {
    return "";
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