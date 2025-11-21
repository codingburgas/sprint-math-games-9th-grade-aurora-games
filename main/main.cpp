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
    return 1;
}

string getLanguage() {
    return "ru";
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

    string wordsEn1Difficulty[15] = { "teacher", "student", "morning", "brother", "kitchen",
    "chicken", "picture", "address", "problem", "bedroom",
    "husband", "evening", "country", "village", "airport" };
    string wordsEn2Difficulty[15] = { "captain", "manager", "history", "weather", "library",
        "success", "message", "journey", "society", "partner",
        "freedom", "science", "balance", "opinion", "officer" };
    string wordsEn3Difficulty[15] = { "anxiety", "justice", "cabinet", "diamond", "silence",
        "blanket", "stomach", "mystery", "bicycle", "economy",
        "disease", "machine", "gravity", "thunder", "volcano" };

    string wordsBg1Difficulty[15] = { "приятел", "магазин", "автобус", "картина", "телефон",
        "роднина", "отговор", "планина", "усмивка", "проблем",
        "градина", "подарък", "закуска", "играчка", "седмица" };
    string wordsBg2Difficulty[15] = { "държава", "природа", "свобода", "история", "болница",
        "цигулка", "капитан", "полицаи", "фотьойл", "плодове",
        "вестник", "самолет", "стадион", "надежда", "маймуна" };
    string wordsBg3Difficulty[15] = { "коридор", "пържола", "столица", "тениска", "водопад",
        "минерал", "дисплей", "учебник", "молитва", "чувство",
        "миризма", "шоколад", "желание", "решение", "причина" };

    string wordsRu1Difficulty[15] = { "телефон", "магазин", "человек", "кровать", "учитель",
        "капуста", "комната", "сосиска", "барабан", "медведь",
        "картина", "автобус", "ребенок", "деревня", "паспорт" };
    string wordsRu2Difficulty[15] = { "шоколад", "рассвет", "договор", "загадка", "корабль",
        "лягушка", "комната", "подарок", "капитан", "морковь",
        "генерал", "скрипка", "самолет", "пылесос", "бутылка" };
    string wordsRu3Difficulty[15] = { "скепсис", "колодец", "водопад", "призрак", "сметана",
        "диагноз", "реакция", "встреча", "экватор", "ящерица",
        "коридор", "фонарик", "рубашка", "котлета", "блокнот" };

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
        break;
    }
    return "";
}

string getHintForRandomWord(short difficulty, string language, short randomNumber) {
    // Hints

    string hintsEn1Difficulty[15] = { "Person", "Abstract", "People", "House", "Food",
    "Object", "Abstract", "Abstract", "House", "People", "Abstract", "Nature", "Place",
    "Place" };
    string hintsEn2Difficulty[15] = { "People", "People", "Abstract", "Nature", "Place",
    "Abstract", "Object", "Abstract", "Abstract", "People", "Abstract", "Abstract",
    "Abstract", "Abstract", "People" };
    string hintsEn3Difficulty[15] = { "Abstract", "Abstract", "House", "Object",
    "Abstract", "House", "Body", "Abstract", "Object", "Abstract", "Abstract", "Object",
    "Science", "Thunder", "Nature" };

    string hintsBg1Difficulty[15] = { "Хора", "Място", "Обект", "Обект",
    "Обект", "Хора", "Абстракция", "Природа", "Абстракция", "Абстракция", "Дом", "Обект",
    "Храна", "Обект", "Време" };
    string hintsBg2Difficulty[15] = { "Място", "Природа", "Абстракция", "Абстракция",
    "Място", "Обект", "Хора", "Хора", "Обект", "Храна", "Обект", "Обект",
    "Място", "Абстракция", "Природа" };
    string hintsBg3Difficulty[15] = { "Къща", "Храна", "Място", "Обект",
    "Природа", "Природа", "Техника", "Обект", "Абстракция", "Абстракция", "Абстракция", "Храна",
    "Абстракция", "Абстракция", "Абстракция" };

    string hintsRu1Difficulty[15] = { "Предмет", "Место", "Люди", "Дом",
    "Люди", "Еда", "Дом", "Еда", "Предмет", "Природа", "Предмет", "Предмет",
    "Люди", "Место", "Предмет" };
    string hintsRu2Difficulty[15] = { "Абстракция", "Люди", "Еда", "Люди",
    "Предмет", "Предмет", "Дом", "Еда", "Еда", "Природа", "Абстракция", "Абстракция",
    "Предмет", "Природа", "Природа" };
    string hintsRu3Difficulty[15] = { "Абстракция", "Дом", "Природа", "Мистика",
    "Еда", "Наука", "Абстракция", "Абстракция", "Природа", "Природа", "Дом", "Предмет",
    "Предмет", "Еда", "Предмет" };


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
        break;
    }
    return "";
}

void showMainMenu() {

}

void displayWordState(char openedLetters[], string word) {

}

bool isWordGuessed(char openedLetters[], string word) {
    for (short i = 0; i < 7; i++) {
        if (openedLetters[i] == ' ') {
            return false;
        }
    }
    return true;
}

bool isLetterGuessed(char letter, char guessedLetters[]) {
    letter = tolower(letter);
    for (short i = 0; i < 32; i++) {
        if (letter == guessedLetters[i]) {
            return true;
        }
    }
    return false;
}

void showGameMenu(char openedLetters[], string hint) {
    // TODO: this menu
    cout << "WORD: ";
    for (short i = 0; i < 7; i++) {
        if (openedLetters[i] == ' ') cout << "_ ";
        else cout << openedLetters[i] << " ";
    }
    cout << endl << "HINT: " << hint << endl;
    cout << "1. Guess letter" << endl << "2. Guess word" << endl << "3. Exit" << endl << "> ";
}

void win(short who) {
    if (1) {
        // Player 1 wins
    }
    else {
        // Player 2 wins
    }
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
    if (guess.length() != 7) return false;

    for (short i = 0; i < 7; i++) {
        if (!isLetterInAlphabet(guess[i], language) || tolower(guess[i]) != tolower(word[i])) {
            return false;
        }
    }
    return true;
}

short howMuchLettersGuessed(char openedLetters[], string word) {
    short result = 0;
    for (short i = 0; i < 7; i++) {
        if (openedLetters[i] != ' ') {
            result++;
        }
    }
    return result;
}

char getRandomUnGuessedLetter(string language, char guessedLetters[]) {
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
        return ' ';
    }

    string candidates = "";
    for (short i = 0; i < alphabet.length(); i++) {
        bool isGuessed = false;
        for (short j = 0; j < 32; j++) {
            if (guessedLetters[j] == alphabet[i]) {
                isGuessed = true;
                break;
            }
        }
        if (!isGuessed) {
            candidates += alphabet[i];
        }
    }

    if (candidates.length() > 0) {
        short randomNumber = getRandomNumber(0, candidates.length() - 1);
        return candidates[randomNumber];
    }
    return ' ';
}

void exitFromGame() {

}

void startGameWithBot(string word, string hint) {
    char openedLetters[7] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char guessedLetters[32];

    short input, guessedLettersLength = 0;
    string language = getLanguage();
    bool gameRunning = true;
    bool isPlayerTurn = true;

    while (gameRunning && !isWordGuessed(openedLetters, word)) {

        if (isPlayerTurn) {
            screenClear();
            showGameMenu(openedLetters, hint);
            cin >> input;

            // Player's move
            if (input == 1) { // Letter guess
                char letter;
                cin >> letter;

                if (isLetterInAlphabet(letter, language)) {
                    if (!isLetterGuessed(letter, guessedLetters)) {
                        guessedLetters[guessedLettersLength++] = tolower(letter);
                        if (indexOfLetterInWord(letter, word) >= 0) {
                            // Correct
                            openedLetters[indexOfLetterInWord(letter, word)] = word[indexOfLetterInWord(letter, word)];
                            isPlayerTurn = true;
                        }
                        else {
                            // No letter in word
                            isPlayerTurn = false;
                        }
                    }
                    else {
                        // Already guessed letter
                        isPlayerTurn = false;
                    }
                }
                else {
                    // Incorrect symbol
                    isPlayerTurn = false;
                }
            }
            else if (input == 2) { // Word guess
                string guess;
                cin >> guess;
                if (isWordGuessedByWordGuess(guess, word)) {
                    win(1);
                    return;
                }
                else {
                    // Wrong word
                    wait(1);
                    isPlayerTurn = false;
                }
            }
            else if (input == 3) { // Exit
                exitFromGame();
                return;
            }

            if (isWordGuessed(openedLetters, word)) {
                win(1);
                return;
            }
        }
        else {
            screenClear();
            showGameMenu(openedLetters, hint);
            // Bot is thinking
            wait(1.5);

            bool botWinsNow = false;
            short lettersOpenedCount = howMuchLettersGuessed(openedLetters, word);
            if (lettersOpenedCount == 5) {
                if (getRandomNumber(1, 8) == 1) {
                    botWinsNow = true;
                }
            }
            else if (lettersOpenedCount == 6) {
                if (getRandomNumber(1, 5) != 1) {
                    botWinsNow = true;
                }
            }
            if (botWinsNow) {
                win(2);
                return;
            }
            else {
                char botLetter = getRandomUnGuessedLetter(language, guessedLetters);
                if (botLetter != ' ') {
                    // Bot choose
                    wait(1);
                    guessedLetters[guessedLettersLength++] = botLetter;
                    if (indexOfLetterInWord(botLetter, word) >= 0) {
                        // Bot guessed correctly
                        openedLetters[indexOfLetterInWord(botLetter, word)] = word[indexOfLetterInWord(botLetter, word)];
                        isPlayerTurn = false;
                    }
                    else {
                        // Bot missed
                        isPlayerTurn = true;
                    }
                }
            }
            if (isWordGuessed(openedLetters, word)) {
                win(2);
                return;
            }
        }
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
    system("chcp 1251 >nul");
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    short num = getRandomNumber(0, 15);
    startGameWithBot(getRandomWord(1, "ru", num), getHintForRandomWord(1, "ru", num));

    return 0;
}