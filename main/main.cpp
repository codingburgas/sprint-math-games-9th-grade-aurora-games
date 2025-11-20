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

void showBeforeGameMenu() {

}

short getRandomNumber(short from, short to) {
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

string getHintForRandomWord(short difficulty, string language, short randomNumber) {
    // Hints

    string hintsEn1Difficulty[30] = {};
    string hintsEn2Difficulty[30] = {};
    string hintsEn3Difficulty[30] = {};

    string hintsBg1Difficulty[30] = {};
    string hintsBg2Difficulty[30] = {};
    string hintsBg3Difficulty[30] = {};

    string hintsRu1Difficulty[30] = {};
    string hintsRu2Difficulty[30] = {};
    string hintsRu3Difficulty[30] = {};


    switch (difficulty) {
    case 1:
        if (language == "en") {
            return hintsEn1Difficulty[randomNumber];
        }
        else if (language == "bg") {
            return hintsBg1Difficulty[randomNumber];
        }
        else if (language == "ru") {
            return hintsRu1Difficulty[randomNumber];
        }
        else {
            cout << "Incorrect language, try again";
        }
        break;

    case 2:
        if (language == "en") {
            return hintsEn2Difficulty[randomNumber];
        }
        else if (language == "bg") {
            return hintsBg2Difficulty[randomNumber];
        }
        else if (language == "ru") {
            return hintsRu2Difficulty[randomNumber];
        }
        else {
            cout << "Incorrect language, try again";
        }
        break;

    case 3:
        if (language == "en") {
            return hintsEn3Difficulty[randomNumber];
        }
        else if (language == "bg") {
            return hintsBg3Difficulty[randomNumber];
        }
        else if (language == "ru") {
            return hintsRu3Difficulty[randomNumber];
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

bool isWordGuessed(char openedLetters[], string word) {
    return 0;
}

bool isLetterGuessed(char letter, char guessedLetters[]) {
    for (short i = 0; i < 7; i++) {
        if (letter == guessedLetters[i]) {
            return true;
        }
    }
    return false;
}

void showGameMenu() {

}

void win(short who) {

}

// Check if a letter is in the alphabet
bool isLetterInAlphabet(char letter, string language) {
    string alphabet;
    if (language == "en") {
        alphabet = "abcdefghijklmnopqrstuvwxyz";
    }
    else if (language == "bg") {
        alphabet = "абвгдежзийклмнопрстуфхцчшщъьюя";
    }
    else if (language == "ru") {
        alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    }
    else {
        return false;
    }
    letter = tolower(letter);
    for (short i = 0; i < alphabet.length(); i++) {
        if (alphabet[i] == letter) {
            return true;
        }
    }
    return false;
}

// Check if a letter is in the word
short indexOfLetterInWord(char letter, string word) {
    for (short i = 0; i < 7; i++) {
        if (letter == word[i]) {
            return i;
        }
    }
    return -1;
}

bool isWordGuessedByWordGuess(string guess, string word) {
    string language = getLanguage();
    for (short i = 0; i < 7; i++) {
        if (!isLetterInAlphabet(guess[i], language) || guess[i] != word[i]) {
            return false;
        }
    }
    return true;
}

void startGameWithBot(string word, string hint) {
    char openedLetters[7] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        guessedLetters[32];
    short input, guessedLettersLength = 0;
    string language = getLanguage();

    while (!isWordGuessed(openedLetters, word)) {
        showGameMenu();
        cin >> input;

        // Player guess letter
        if (input == 1) {
            char letter;
            cin >> letter;
            if (isLetterInAlphabet(letter, language)) {

                if (!isLetterGuessed(letter, guessedLetters)) {
                    guessedLetters[guessedLettersLength++] = letter;

                    short indexOfLetter = indexOfLetterInWord(letter, word);
                    if (indexOfLetter > 0) {
                        openedLetters[indexOfLetter] = letter;
                    }
                    else {
                        // TODO: Incorrect letter
                    }
                }
                else {
                    // TODO: Letter isn't in alphabet
                }

            }
            else {
                cout << "Incorrect Input!";
            }
        }

        // Player guess word
        else if (input == 2) {
            string guess;
            cin >> guess;
            if (isWordGuessedByWordGuess(guess, word)) {
                win(1);
            }
            else {
                // TODO: The word is guessed incorrect
            }
        }

        screenClear();
    }
}

bool checkLetter(char letter, char openedLetters[], string word) {
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
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    bool running = true;
    string language = getLanguage();
    short difficulty = getDifficulty();

    while (running) {
        showMainMenu();
        short input;
        cin >> input;
        if (input == 1) {
            screenClear();
            showBeforeGameMenu();
            cin >> input;
            if (input == 1) {
                short randomNumber = getRandomNumber(0, 30);
                string word = getRandomWord(difficulty, language, randomNumber), hint = getHintForRandomWord(difficulty, language, randomNumber);
                screenClear();
                startGameWithBot(word, hint);
            }
        }
    }
    return 0;
}