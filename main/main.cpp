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

    string wordsEn1Difficulty[30] = { "Teacher", "Student", "Morning", "Brother", "Kitchen",
        "Chicken", "Picture", "Address", "Problem", "Bedroom",
        "Husband", "Evening", "Country", "Village", "Airport" };
    string wordsEn2Difficulty[30] = { "Captain", "Manager", "History", "Weather", "Library",
        "Success", "Message", "Journey", "Society", "Partner",
        "Freedom", "Science", "Balance", "Opinion", "Officer" };
    string wordsEn3Difficulty[30] = { "Anxiety", "Justice", "Cabinet", "Diamond", "Silence",
        "Blanket", "Stomach", "Mystery", "Bicycle", "Economy",
        "Disease", "Machine", "Gravity", "Thunder", "Volcano" };

    string wordsBg1Difficulty[30] = { "Приятел", "Магазин", "Автобус", "Картина", "Телефон",
        "Роднина", "Отговор", "Планина", "Усмивка", "Проблем",
        "Градина", "Подарък", "Закуска", "Играчка", "Седмица" };
    string wordsBg2Difficulty[30] = { "Държава", "Природа", "Свобода", "История", "Болница",
        "Цигулка", "Капитан", "Полицай", "Фотьойл", "Плодове",
        "Вестник", "Самолет", "Стадион", "Надежда", "Маймуна" };
    string wordsBg3Difficulty[30] = { "Коридор", "Пържола", "Столица", "Тениска", "Водопад",
        "Минерал", "Дисплей", "Учебник", "Молитва", "Чувство",
        "Миризма", "Шоколад", "Желание", "Решение", "Причина" };

    string wordsRu1Difficulty[30] = { "Телефон", "Магазин", "Человек", "Кровать", "Учитель",
        "Капуста", "Комната", "Сосиска", "Барабан", "Медведь",
        "Картина", "Автобус", "Ребенок", "Деревня", "Паспорт" };
    string wordsRu2Difficulty[30] = { "Шоколад", "Рассвет", "Договор", "Загадка", "Корабль",
        "Лягушка", "Комната", "Подарок", "Капитан", "Морковь",
        "Генерал", "Скрипка", "Самолет", "Пылесос", "Бутылка" };
    string wordsRu3Difficulty[30] = { "Скепсис", "Колодец", "Водопад", "Призрак", "Сметана",
        "Диагноз", "Реакция", "Встреча", "Экватор", "Ящерица",
        "Коридор", "Фонарик", "Рубашка", "Котлета", "Блокнот" };

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

    string hintsEn1Difficulty[30] = {"Person", "Abstract/Time", "People", "House", "Food/Nature",
    "Object", "Abstract", "Abstract", "House", "People", "Abstract/Time", "Nature/Place", "Place",
    "Place"};
    string hintsEn2Difficulty[30] = {"People", "People", "Abstract", "Nature", "Place",
    "Abstract", "Object/Abstract", "Abstract", "Abstract", "People", "Abstract", "Abstract",
    "Abstract", "Abstract", "People"};
    string hintsEn3Difficulty[30] = { "Abstract/Feeling", "Abstract", "House/Object", "Object/Nature",
    "Abstract", "House", "Body", "Abstract", "Object", "Abstract", "Abstract/Science", "Object",
    "Science", "Thunder", "Nature" };

    string hintsBg1Difficulty[30] = {"Хора", "Място", "Обект", "Обект",
    "Обект", "Хора", "Абстракция", "Природа", "Абстракция/Тяло", "Абстракция", "Дом/Природа", "Обект",
    "Храна", "Обект", "Време" };
    string hintsBg2Difficulty[30] = { "Място/Общество", "Природа", "Абстракция", "Абстракция",
    "Място", "Обект/Музика", "Хора", "Хора", "Обект", "Храна", "Обект", "Обект",
    "Място", "Абстракция", "Природа" };
    string hintsBg3Difficulty[30] = { "Къща", "Храна", "Място", "Обект/Дрехи",
    "Природа", "Природа", "Техника", "Обект", "Абстракция", "Абстракция", "Абстракция", "Храна",
    "Абстракция", "Абстракция", "Абстракция" };

    string hintsRu1Difficulty[30] = { "Предмет", "Место", "Люди", "Дом",
    "Люди", "Еда", "Дом", "Еда", "Предмет", "Природа", "Предмет", "Предмет",
    "Люди", "Место", "Предмет" };
    string hintsRu2Difficulty[30] = { "Абстракция/Предмет", "Люди", "Еда", "Люди",
    "Предмет", "Предмет", "Дом", "Еда/Предмет", "Еда", "Природа", "Абстракция", "Абстракция",
    "Предмет", "Природа", "Природа" };
    string hintsRu3Difficulty[30] = { "Абстракция", "Дом/Природа", "Природа", "Мистика",
    "Еда", "Наука", "Абстракция", "Абстракция", "Природа/Наука", "Природа", "Дом", "Предмет",
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

    short num = getRandomNumber(0, 15);
    short difficulty = getRandomNumber(1, 3);
    cout << getRandomWord(difficulty, "bg", num) << getHintForRandomWord(difficulty, "bg", num);
    return 0;
}