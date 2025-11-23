#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

string language = "en";
int difficulty = 1;

void showMainMenu();
void startGameWithBot(string word, string hint);
void startGame1v1(string word, string hint);
void exitInMainMenu();
void chooseLanguage();
void chooseDifficulty();

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
    return difficulty;
}

string getLanguage() {
    return language;
}

short saveConfig(short difficulty, string language) {
    return 0;
}

void showBeforeGameMenu() {
    screenClear();
    cout << "1. Play with bot" << endl << "2. Play 1v1" << endl << "3. Exit" << endl << "> ";
}

short getRandomNumber(short from, short to) {
    return from + rand() % (to - from + 1);
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
        "картина", "автобус", "ребёнок", "деревня", "паспорт" };
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
    "Place" }; // TODO: Add hint
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
    cin >> input;
    cout << ">";

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
    cin >> input;
    cout << ">";

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

void startGame() {
    string language = getLanguage();
    short input, difficulty = getDifficulty();
    bool running = true;

    short randomNumber = getRandomNumber(0, 14);
    string word = getRandomWord(difficulty, language, randomNumber),
        hint = getHintForRandomWord(difficulty, language, randomNumber);

    showBeforeGameMenu();
    cin >> input;
    switch (input) {
    case 1:
        startGameWithBot("коридор", hint);
        break;
    case 2:
        startGame1v1(word, hint);
        break;
    case 3:
        exitInMainMenu();
        break;
    }
}

void about() {
    
}

void showMainMenu() {
    screenClear();

    int input;

    ifstream file("../images/welcome.txt");   // relative path

    if (!file.is_open()) {
        cout << "Cannot open file!\n";
    }

    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }

    file.close();
    cout << R"(
                        +----------------------------+
                        |       WHEEL OF WORDS       |
                        +----------------------------+
                        |  1) Start Game             |
                        |  2) Settings               |
                        |  3) About                  |
                        |  4) Exit                   |
                        +----------------------------+
)";
    cout << ">";
    cin >> input;

    switch (input) {
        case 1:
            startGame();
            break;
        case 2:
            settingsMenu();
            break;
        case 3:
            about();
        case 4:
            exitInMainMenu();
            break;
    }


}



void exitInMainMenu() {
    // Exit in main menu
    screenClear();
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
    screenClear();
    if (who == 1) {
        // Player 1 wins
        cout << "Player 1 wins!";
    }
    else {
        // Player 2 wins
        cout << "Player 2 wins!";
    }
    cout << endl << endl;
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

char getRandomUnguessedLetter(string language, char guessedLetters[]) {
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

bool exitFromGame() {
    char answer;

    screenClear();
    cout << "Are you sure you want to exit the game? (y/n) > ";
    cin >> answer;
    answer = tolower(answer);
    if (answer == 'y') {
        screenClear();
        // Exit to main menu
        return true;
    }
    // Player doesn't want to exit
    screenClear();
    return false;
}

short spinWheel() {
    short wheelVariants[16] = { 0, 1, 2, 3, // Special
        4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }; // Points
    short currentIndex = getRandomNumber(0, 15);
    short steps = getRandomNumber(30, 50);
    float delay = 0.05;

    for (short i = 0; i < steps; i++) {
        currentIndex++;
        if (currentIndex >= 16) {
            currentIndex = 0;
        }
        if (steps - i < 15) {
            delay += 0.1;
        }
        wait(delay);
    }

    return wheelVariants[currentIndex];
}

void showPlusMenu() {
    screenClear();
    cout << "Which letter do you want to know?" << endl << "> ";
}

short getIndexOfRandomUnopenedLetter(char openedLetters[]) {
    short options[7], lastIndexInOptions = 0, random;
    for (short i = 0; i < 7; i++) {
        if (openedLetters[i] == ' ') {
            options[lastIndexInOptions++] = i;
        }
    }
    random = getRandomNumber(0, lastIndexInOptions - 1);
    return options[random];
}

void startGameWithBot(string word, string hint) {
    char openedLetters[7] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char guessedLetters[33] = { 0 };

    short input, guessedLettersLength = 0, onWheel, playerPoints = 0, botPoints = 0,
        pointsOnWheel[12] = { 350, 400, 450, 500, 600, 650, 700, 750, 800, 850, 950, 1000 };
    string language = getLanguage(), displayWheelVariants[16] = {
        "B", "+", "S", "X",
        "350", "400", "450", "500", "600", "650", "700", "750", "800", "850", "950", "1000"
    };
    bool gameRunning = true;
    bool isPlayerTurn = true;

    while (gameRunning && !isWordGuessed(openedLetters, word)) {

        if (isPlayerTurn) {
            screenClear();
            cout << "Player spin wheel...";
            onWheel = spinWheel();
            cout << endl << "Player have " << displayWheelVariants[onWheel] << " on wheel!";
            wait(3);
            screenClear();

            // B on wheel
            if (onWheel == 0) {
                playerPoints = 0;
                isPlayerTurn = false;
            }
            // + on wheel
            else if (onWheel == 1) {
                showPlusMenu();
                cin >> input;
                openedLetters[input] = word[input];
                isPlayerTurn = false;
            }
            // S on wheel
            else if (onWheel == 2) {
                isPlayerTurn = false;
            }
            // Player have points on wheel
            else if (onWheel >= 3) {
                showGameMenu(openedLetters, hint);
                cin >> input;
                if (input == 1) { // Letter guess
                    char letter;
                    cin >> letter;

                    if (isLetterInAlphabet(letter, language)) {
                        if (!isLetterGuessed(letter, guessedLetters)) {
                            guessedLetters[guessedLettersLength++] = tolower(letter);
                            if (indexOfLetterInWord(letter, word) >= 0) {
                                // Correct
                                if (onWheel == 3) {
                                    playerPoints *= 2;
                                }
                                else {
                                    playerPoints += pointsOnWheel[onWheel - 4];
                                }

                                // Open ALL instances of the letter
                                for (int i = 0; i < 7; i++) {
                                    if (tolower(word[i]) == tolower(letter)) {
                                        openedLetters[i] = word[i];
                                    }
                                }
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
                        gameRunning = false;
                        win(1);
                        return;
                    }
                    else {
                        // Wrong word
                        gameRunning = false;
                        win(2);
                    }
                }
                else if (input == 3) { // Exit
                    if (exitFromGame()) {
                        return;
                    }
                }
            }
            if (isWordGuessed(openedLetters, word)) {
                win(1);
                return;
            }
        }
        else {
            screenClear();
            cout << "Bot spin wheel...";
            onWheel = spinWheel();
            cout << endl << "Bot have " << displayWheelVariants[onWheel] << " on wheel!";
            wait(3);
            screenClear();
            showGameMenu(openedLetters, hint);

            // B on wheel
            if (onWheel == 0) {
                botPoints = 0; // Fixed: Bot loses points, not player
                isPlayerTurn = true;
            }
            // + on wheel
            else if (onWheel == 1) {
                input = getIndexOfRandomUnopenedLetter(openedLetters);
                openedLetters[input] = word[input];
                isPlayerTurn = true;
            }
            // S on wheel
            else if (onWheel == 2) {
                isPlayerTurn = true;
            }
            // Bot have points on wheel
            else if (onWheel >= 3) {
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
                    gameRunning = false;
                    win(2);
                    return;
                }
                else {
                    char botLetter = getRandomUnguessedLetter(language, guessedLetters);
                    if (botLetter != ' ') {
                        // Bot choose
                        wait(1);
                        guessedLetters[guessedLettersLength++] = botLetter;
                        if (indexOfLetterInWord(botLetter, word) >= 0) {
                            // Bot guessed correctly
                            if (onWheel == 3) {
                                botPoints *= 2;
                            }
                            else {
                                botPoints += pointsOnWheel[onWheel - 4];
                            }

                            // Open ALL instances of the letter for Bot
                            for (int i = 0; i < 7; i++) {
                                if (tolower(word[i]) == tolower(botLetter)) {
                                    openedLetters[i] = word[i];
                                }
                            }
                            isPlayerTurn = false;
                        }
                        else {
                            // Bot missed
                            isPlayerTurn = true;
                        }
                    }
                }
            }
            if (isWordGuessed(openedLetters, word)) {
                gameRunning = false;
                win(2);
                return;
            }
        }
    }
}

void startGame1v1(string word, string hint) {
    char openedLetters[7] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char guessedLetters[33] = { 0 };

    short input, guessedLettersLength = 0, onWheel, player1Points = 0, player2Points = 0,
        pointsOnWheel[12] = { 350, 400, 450, 500, 600, 650, 700, 750, 800, 850, 950, 1000 };
    string language = getLanguage(), displayWheelVariants[16] = {
        "B", "+", "S", "X",
        "350", "400", "450", "500", "600", "650", "700", "750", "800", "850", "950", "1000"
    };
    bool gameRunning = true;
    bool isPlayer1Turn = true;

    while (gameRunning && !isWordGuessed(openedLetters, word)) {

        if (isPlayer1Turn) {
            screenClear();
            cout << "Player 1 spin wheel...";
            onWheel = spinWheel();
            cout << endl << "Player 1 have " << displayWheelVariants[onWheel] << " on wheel!";
            wait(3);
            screenClear();

            // B on wheel
            if (onWheel == 0) {
                player1Points = 0;
                isPlayer1Turn = false;
            }
            // + on wheel
            else if (onWheel == 1) {
                showPlusMenu();
                cin >> input;
                openedLetters[input] = word[input];
                isPlayer1Turn = false;
            }
            // S on wheel
            else if (onWheel == 2) {
                isPlayer1Turn = false;
            }
            // Player have points on wheel
            else if (onWheel >= 3) {
                showGameMenu(openedLetters, hint);
                cin >> input;

                // Player 1 move
                if (input == 1) { // Letter guess
                    char letter;
                    cin >> letter;

                    if (isLetterInAlphabet(letter, language)) {
                        if (!isLetterGuessed(letter, guessedLetters)) {
                            guessedLetters[guessedLettersLength++] = tolower(letter);
                            if (indexOfLetterInWord(letter, word) >= 0) {
                                // Correct
                                if (onWheel == 3) {
                                    player1Points *= 2;
                                }
                                else {
                                    player1Points += pointsOnWheel[onWheel - 4];
                                }

                                // Open ALL instances of the letter
                                for (int i = 0; i < 7; i++) {
                                    if (tolower(word[i]) == tolower(letter)) {
                                        openedLetters[i] = word[i];
                                    }
                                }
                                isPlayer1Turn = true;
                            }
                            else {
                                // No letter in word
                                isPlayer1Turn = false;
                            }
                        }
                        else {
                            // Already guessed letter
                            isPlayer1Turn = false;
                        }
                    }
                    else {
                        // Incorrect symbol
                        isPlayer1Turn = false;
                    }
                }
                else if (input == 2) { // Word guess
                    string guess;
                    cin >> guess;
                    if (isWordGuessedByWordGuess(guess, word)) {
                        gameRunning = false;
                        win(1);
                        return;
                    }
                    else {
                        // Wrong word
                        gameRunning = false;
                        win(2);
                    }
                }
                else if (input == 3) { // Exit
                    if (exitFromGame()) {
                        return;
                    }
                }
                if (isWordGuessed(openedLetters, word)) {
                    win(1);
                    return;
                }
            }
        }
        // Player 2 move
        else {
            screenClear();
            cout << "Player 2 spin wheel...";
            onWheel = spinWheel();
            cout << endl << "Player 2 have " << displayWheelVariants[onWheel] << " on wheel!";
            wait(3);
            screenClear();

            // B on wheel
            if (onWheel == 0) {
                player2Points = 0; // Fixed: P2 loses points
                isPlayer1Turn = true;
            }
            // + on wheel
            else if (onWheel == 1) {
                showPlusMenu();
                cin >> input;
                openedLetters[input] = word[input];
                isPlayer1Turn = true;
            }
            // S on wheel
            else if (onWheel == 2) {
                isPlayer1Turn = true;
            }
            // Player have points on wheel
            else if (onWheel >= 3) {

                showGameMenu(openedLetters, hint);
                cin >> input;

                if (input == 1) { // Letter guess
                    char letter;
                    cin >> letter;

                    if (isLetterInAlphabet(letter, language)) {
                        if (!isLetterGuessed(letter, guessedLetters)) {
                            guessedLetters[guessedLettersLength++] = tolower(letter);
                            if (indexOfLetterInWord(letter, word) >= 0) {
                                // Correct
                                if (onWheel == 3) {
                                    player2Points *= 2;
                                }
                                else {
                                    player2Points += pointsOnWheel[onWheel - 4];
                                }

                                // Open ALL instances of the letter
                                for (int i = 0; i < 7; i++) {
                                    if (tolower(word[i]) == tolower(letter)) {
                                        openedLetters[i] = word[i];
                                    }
                                }
                                isPlayer1Turn = false;
                            }
                            else {
                                // No letter in word
                                isPlayer1Turn = true;
                            }
                        }
                        else {
                            // Already guessed letter
                            isPlayer1Turn = true;
                        }
                    }
                    else {
                        // Incorrect symbol
                        isPlayer1Turn = true;
                    }
                }
                else if (input == 2) { // Word guess
                    string guess;
                    cin >> guess;
                    if (isWordGuessedByWordGuess(guess, word)) {
                        gameRunning = false;
                        win(2);
                        return;
                    }
                    else {
                        // Wrong word
                        gameRunning = false;
                        win(1);
                    }
                }
                else if (input == 3) { // Exit
                    if (exitFromGame()) {
                        return;
                    }
                }
                if (isWordGuessed(openedLetters, word)) {
                    win(2);
                    return;
                }
            }
        }
    }
}

void chooseDifficulty() {
    screenClear();
    int input;
    cout << R"(
                        +----------------------------------------------------------+
                        |                    DIFFICULTY LEVEL                      |
                        +----------------------------------------------------------+
                        |  1) Easy (Short words, common vacabulary)                |
                        |  2) Normal (Medium length words, varied difficulty)      |
                        |  3) Hard (Long words, rare vacabulary)                   |
                        |  4) Back                                                 |
                        +----------------------------------------------------------+
)";
    cin >> input;
    cout << ">";

    switch (input) {
    case 1:
        difficulty = 1;
        break;
    case 2:
        difficulty = 2;
        break;
    case 3:
        difficulty = 3;
        break;
    case 4:
        settingsMenu();
    }

    settingsMenu();
}

void rulesMenu() {

}

// Main

int main() {
    system("chcp 1251 >nul");
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    showMainMenu();

    return 0;
}