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

void printLineWithPoints(string label, int points) {
    cout << "                    |  " << label << ": " << points;
    int tempPoints = points, length = 0, spacesNeeded;
    if (tempPoints == 0) {
        length = 1;
    }
    else {
        while (tempPoints > 0) {
            tempPoints /= 10;
            length++;
        }
    }
    spacesNeeded = 19 - length;
    for (int i = 0; i < spacesNeeded; i++) {
        cout << " ";
    }
    cout << "|" << endl;
}

void hintOutput(string hint) {
    // +--------------------------------------+
    // |  Hint: Example                       |
    cout << "                    +--------------------------------------+" << endl << "                    |  Hint: " << hint;
    for (short i = 0; i < 30 - hint.length(); i++) {
        cout << " ";
    }
    cout << "|";
}
void playerPointsOutput(int player1Points, int player2Points) {
    cout << "                    +--------------------------------------+" << endl;
    printLineWithPoints("Player 1 Points", player1Points);
    printLineWithPoints("Player 2 Points", player2Points);
    cout << "                    +--------------------------------------+" << endl;
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

void showGameMenu(char openedLetters[], string hint, short player1Points, short player2Points) {
    cout << "                    +--------------------------------------+" << endl;
    cout << "                    |  WORD: ";
    for (short i = 0; i < 7; i++) {
        if (openedLetters[i] == ' ') cout << "_ ";
        else cout << openedLetters[i] << " ";
    }
    cout << "                |" << endl;
    playerPointsOutput(player1Points, player2Points);
    cout << endl;
    hintOutput(hint);
    cout << R"(
                    +--------------------------------------+
                    |  1) Guess letter                     |
                    |  2) Guess word                       |
                    |  3) Exit                             |
                    +--------------------------------------+

                    > )";
}

void win(short who) {
    screenClear();
    if (who == 1) {
        // Player 1 wins
        cout << R"(
                    +--------------------------------------+
                    |            Player 1 wins!            |
                    +--------------------------------------+
)" << endl;
    }
    else {
        // Player 2 wins
        cout << R"(
                    +--------------------------------------+
                    |            Player 2 wins!            |
                    +--------------------------------------+
)" << endl;

    }
    wait(5);
    showMainMenu();
}

bool isLetterInAlphabet(char letter, string language) {
    string alphabet;
    if (language == "en") {
        alphabet = "abcdefghijklmnopqrstuvwxyz";
    }
    else if (language == "bg") {
        alphabet = "                              ";
    }
    else if (language == "ru") {
        alphabet = "                                ";
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

short indexOfLetterInWord(char letter, string word) {
    for (short i = 0; i < 7; i++) {
        if (letter == word[i]) {
            return i;
        }
    }
    return -1;
}

bool isWordGuessedByWordGuess(string guess, string word) {
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
        alphabet = "                              ";
    }
    else if (language == "ru") {
        alphabet = "                                ";
    }
    else {
        return ' ';
    }

    string candidates = "";
    short candidatesLength = 0;
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
            candidatesLength++;
        }
    }

    if (candidatesLength > 0) {
        short randomNumber = getRandomNumber(0, candidatesLength - 1);
        return candidates[randomNumber];
    }
    return ' ';
}

bool exitFromGame() {
    char answer;

    screenClear();
    cout << R"(
                    +---------------------------------------+
                    |Are you sure you want to exit the game?|
                    |(y/n)                                  |
                    +---------------------------------------+

                    >
)";
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

void wheelAnimation(short currentIndex) {
    string displayWheelVariants[20] = {
       "850", "950", " B ", " + ", " S ", " X ",
       "350", "400", "450", "500", "600", "650", "700", "750", "800", "850", "950", " B ", " + "
    };
    currentIndex += 2;
    screenClear();
    cout << R"(
                                      \   /
                                       \ /
                    +-------+-------+-------+-------+-------+ 
    )";
    cout << "                |  " << displayWheelVariants[currentIndex - 2] << "  |  ";
    cout << displayWheelVariants[currentIndex - 1] << "  |  ";
    cout << displayWheelVariants[currentIndex] << "  |  ";
    cout << displayWheelVariants[currentIndex + 1] << "  |  ";
    cout << displayWheelVariants[currentIndex + 2] << "  |";
    cout << R"(
                    +-------+-------+-------+-------+-------+
                                       / \
                                      /   \
    )";
}

short spinWheel() {
    short currentIndex = getRandomNumber(0, 14);
    short steps = getRandomNumber(30, 50);
    float delay = 0.05;
    for (short i = 0; i < steps; i++) {
        currentIndex++;
        if (currentIndex >= 15) {
            currentIndex = 0;
        }
        if (steps - i < 15) {
            delay += 0.1;
        }
        wheelAnimation(currentIndex);
        wait(delay);
    }

    return currentIndex;
}

void showPlusMenu() {
    screenClear();
    cout << R"(
                    +---------------------------------------+
                    |   Which letter do you want to know?   |
                    +---------------------------------------+

                       > )" << endl;
}

short getIndexOfRandomUnopenedLetter(char openedLetters[]) {
    short options[7], lastIndexInOptions = 0, random;
    for (short i = 0; i < 7; i++) {
        if (openedLetters[i] == ' ') {
            options[lastIndexInOptions++] = i;
        }
    }
    if (lastIndexInOptions == 0) {
        return 0;
    }
    random = getRandomNumber(0, lastIndexInOptions - 1);
    return options[random];
}

void startGameWithBot(string word, string hint) {
    char openedLetters[7] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char guessedLetters[33] = { 0 };

    short input, guessedLettersLength = 0, onWheel, playerPoints = 0, botPoints = 0,
        pointsOnWheel[11] = { 350, 400, 450, 500, 600, 650, 700, 750, 800, 850, 950 };
    string displayWheelVariants[15] = {
        " B ", " + ", " S ", " X ",
        "350", "400", "450", "500", "600", "650", "700", "750", "800", "850", "950" };
    bool gameRunning = true;
    bool isPlayerTurn = true;

    while (gameRunning && !isWordGuessed(openedLetters, word)) {

        if (isPlayerTurn) {
            screenClear();
            cout << R"(
                    +---------------------------------------+
                    |       Player spins the wheel...       |
                    +---------------------------------------+
            )" << endl;
            wait(2);
            onWheel = spinWheel();
            cout << R"(
                    +---------------------------------------+
                    |       Player has )" << displayWheelVariants[onWheel] << R"( on wheel!        |
                    +---------------------------------------+
            )" << endl;
            wait(2);
            screenClear();

            // B on wheel
            if (onWheel == 0) {
                playerPoints = 0;
                isPlayerTurn = false;
            }
            // + on wheel
            else if (onWheel == 1) {
                do {
                    showPlusMenu();
                    cin >> input;
                } while (input > 7 || input < 1);
                openedLetters[input + 1] = word[input + 1];
                isPlayerTurn = false;
            }
            // S on wheel
            else if (onWheel == 2) {
                isPlayerTurn = false;
            }
            // Player have points on wheel
            else if (onWheel >= 3) {
                do {
                    showGameMenu(openedLetters, hint, playerPoints, botPoints);
                    cin >> input;
                } while (input < 0 || input > 3);
                cout << "                    > ";
                if (input == 1) { // Letter guess
                    char letter;
                    cin >> letter;
                    if (isLetterInAlphabet(letter, language)) {
                        if (!isLetterGuessed(letter, guessedLetters)) {
                            guessedLetters[guessedLettersLength++] = tolower(letter);
                            if (indexOfLetterInWord(letter, word) >= 0) {
                                cout << R"(
                    +---------------------------------------+
                    |          Correct!    (^_^)            |
                    +---------------------------------------+
                                )" << endl;
                                wait(2);
                                if (onWheel == 3) {
                                    playerPoints *= 2;
                                }
                                else {
                                    playerPoints += pointsOnWheel[onWheel - 4];
                                }
                                for (int i = 0; i < 7; i++) {
                                    if (tolower(word[i]) == tolower(letter)) {
                                        openedLetters[i] = word[i];
                                    }
                                }
                                isPlayerTurn = true;
                            }
                            else {
                                cout << R"(
                    +--------------------------------------+
                    |    No letter in the word!  (T_T)     |
                    +--------------------------------------+
                                )" << endl;
                                wait(2);
                                isPlayerTurn = false;
                            }
                        }
                        else {
                            cout << R"(
                    +--------------------------------------+
                    |      Already guessed the letter!     |
                    +--------------------------------------+
                            )" << endl;
                            wait(2);
                            isPlayerTurn = false;
                        }
                    }
                    else {
                        cout << R"(
                    +--------------------------------------+
                    |      Incorrect symbol!   (0_0)       |
                    +--------------------------------------+
                           )" << endl;
                        wait(2);
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
                        cout << R"(
                    +--------------------------------------+
                    |         Wrong word!     (T_T)        |
                    +--------------------------------------+
                        )" << endl;
                        wait(2);
                        gameRunning = false;
                        win(2);
                    }
                }
                else if (input == 3) { // Exit
                    if (exitFromGame()) {
                        return;
                    }
                }
                else {
                    cout << R"(
                    +---------------------------------------+
                    |      Incorrect input!    (x_x)        |
                    +---------------------------------------+
                    )" << endl;
                    wait(2);
                }
            }
            if (isWordGuessed(openedLetters, word)) {
                win(1);
                return;
            }
        }
        else {
            screenClear();
            cout << R"(
                    +---------------------------------------+
                    |          Bot spins the wheel...       |
                    +---------------------------------------+
            )" << endl;
            wait(2);
            onWheel = spinWheel();
            cout << "                +---------------------------------------+" << endl <<
                "                    |        Bot has " << displayWheelVariants[onWheel] << " on wheel!          |" << endl <<
                "                    +---------------------------------------+";
            wait(3);
            screenClear();
            showGameMenu(openedLetters, hint, playerPoints, botPoints);

            // B on wheel
            if (onWheel == 0) {
                botPoints = 0;
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
                            cout << R"(
                    +---------------------------------------+
                    |         Bot guessed correctly!        |
                    +---------------------------------------+
                            )" << endl;
                            wait(2);
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
                            cout << R"(
                    +---------------------------------------+
                    |              Bot missed!              |
                    +---------------------------------------+
                            )" << endl;
                            wait(2);
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
        pointsOnWheel[11] = { 350, 400, 450, 500, 600, 650, 700, 750, 800, 850, 950 };
    string displayWheelVariants[16] = {
        " B ", " + ", " S ", " X ",
        "350", "400", "450", "500", "600", "650", "700", "750", "800", "850", "950" };
    bool gameRunning = true;
    bool isPlayer1Turn = true;

    while (gameRunning && !isWordGuessed(openedLetters, word)) {

        if (isPlayer1Turn) {
            screenClear();
            cout << R"(
                    +---------------------------------------+
                    |         Player 1 spins wheel...       |
                    +---------------------------------------+
            )" << endl;
            wait(2);
            onWheel = spinWheel();

            cout << "                    +---------------------------------------+" << endl <<
                "                    |     Player 1 has " << displayWheelVariants[onWheel] << " on wheel!        |" << endl <<
                "                    +---------------------------------------+";
            wait(3);
            //cout << endl << "Player 1 has" << displayWheelVariants[onWheel] << " on wheel!";
            //wait(3);
            screenClear();

            // B on wheel
            if (onWheel == 0) {
                player1Points = 0;
                isPlayer1Turn = false;
            }
            // + on wheel
            else if (onWheel == 1) {
                do {
                    showPlusMenu();
                    cin >> input;
                } while (input < 0 || input > 7);
                openedLetters[input + 1] = word[input + 1];
                isPlayer1Turn = false;
            }
            // S on wheel
            else if (onWheel == 2) {
                isPlayer1Turn = false;
            }
            // Player have points on wheel
            else if (onWheel >= 3) {
                // cout << word << endl;
                do {
                    showGameMenu(openedLetters, hint, player1Points, player2Points);
                    cin >> input;
                } while (input < 0 || input > 3);

                // Player 1 move
                if (input == 1) { // Letter guess
                    char letter;
                    cin >> letter;

                    if (isLetterInAlphabet(letter, language)) {
                        if (!isLetterGuessed(letter, guessedLetters)) {
                            guessedLetters[guessedLettersLength++] = tolower(letter);
                            if (indexOfLetterInWord(letter, word) >= 0) {
                                cout << R"(
                    +---------------------------------------+
                    |            Correct!    (^_^)          |
                    +---------------------------------------+
                                )" << endl;
                                wait(2);
                                if (onWheel == 3) {
                                    player1Points *= 2;
                                }
                                else {
                                    player1Points += pointsOnWheel[onWheel - 4];
                                }
                                for (int i = 0; i < 7; i++) {
                                    if (tolower(word[i]) == tolower(letter)) {
                                        openedLetters[i] = word[i];
                                    }
                                }
                                isPlayer1Turn = true;
                            }
                            else {
                                cout << R"(
                    +---------------------------------------+
                    |    No letter in the word!   (T_T)     |
                    +---------------------------------------+
                                )" << endl;
                                wait(2);
                                isPlayer1Turn = false;
                            }
                        }
                        else {
                            cout << R"(
                    +---------------------------------------+
                    |   Already guessed the letter! (0_0)   |
                    +---------------------------------------+
                                )" << endl;
                            wait(2);
                            isPlayer1Turn = false;
                        }
                    }
                    else {
                        cout << R"(
                    +---------------------------------------+
                    |       Incorrect symbol!   (x_x)       |
                    +---------------------------------------+
                                )" << endl;
                        wait(2);
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
                else {
                    cout << R"(
                    +---------------------------------------+
                    |      Incorrect input!     (x_x)       |
                    +---------------------------------------+
                                )" << endl;
                    wait(2);
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
            cout << R"(
                    +---------------------------------------+
                    |        Player 2 spins wheel...        |
                    +---------------------------------------+
                               )" << endl;
            wait(2);
            onWheel = spinWheel();
            cout << "                    +---------------------------------------+" << endl <<
                "                    |     Player 2 has " << displayWheelVariants[onWheel] << " on wheel!           |" << endl <<
                "                    +---------------------------------------+";
            wait(3);
            screenClear();

            // B on wheel
            if (onWheel == 0) {
                player2Points = 0;
                isPlayer1Turn = true;
            }
            // + on wheel
            else if (onWheel == 1) {
                do {
                    showPlusMenu();
                    cin >> input;
                } while (input < 0 || input > 7);
                openedLetters[input + 1] = word[input + 1];
                isPlayer1Turn = true;
            }
            // S on wheel
            else if (onWheel == 2) {
                isPlayer1Turn = true;
            }
            // Player have points on wheel
            else if (onWheel >= 3) {
                cout << word << endl;
                do {
                    showGameMenu(openedLetters, hint, player1Points, player2Points);
                    cin >> input;
                } while (input < 0 || input > 3);

                if (input == 1) { // Letter guess
                    char letter;
                    cin >> letter;

                    if (isLetterInAlphabet(letter, language)) {
                        if (!isLetterGuessed(letter, guessedLetters)) {
                            guessedLetters[guessedLettersLength++] = tolower(letter);
                            if (indexOfLetterInWord(letter, word) >= 0) {
                                cout << R"(
                    +---------------------------------------+
                    |            Correct!      (^_^)        |
                    +---------------------------------------+
                                )" << endl;
                                wait(2);
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
                                cout << R"(
                    +---------------------------------------+
                    |   No letter in the word!    (T_T)     |
                    +---------------------------------------+
                                )" << endl;
                                wait(2);
                                isPlayer1Turn = true;
                            }
                        }
                        else {
                            cout << R"(
                    +---------------------------------------+
                    |   Already guessed the letter!  (0_0)  |
                    +---------------------------------------+
                                )" << endl;
                            wait(2);
                            isPlayer1Turn = true;
                        }
                    }
                    else {
                        cout << R"(
                    +---------------------------------------+
                    |       Incorrect symbol!   (x_x)       |
                    +---------------------------------------+
                                )" << endl;
                        wait(2);
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