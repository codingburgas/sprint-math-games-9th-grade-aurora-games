#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../Header Files/words.h"

using namespace std;

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

string hintsEn1Difficulty[15] = { "People", "People", "Abstract", "People", "House", "Food",
"Object", "Abstract", "Abstract", "House", "People", "Abstract", "Nature", "Place",
"Place" };
string hintsEn2Difficulty[15] = { "People", "People", "Abstract", "Nature", "Place",
"Abstract", "Object", "Abstract", "Abstract", "People", "Abstract", "Abstract",
"Abstract", "Abstract", "People" };
string hintsEn3Difficulty[15] = { "Abstract", "Abstract", "House", "Object",
"Abstract", "House", "Body", "Abstract", "Object", "Abstract", "Abstract", "Object",
"Science", "Nature", "Nature" };
string hintsBg1Difficulty[15] = { "Хора", "Място", "Обект", "Обект",
"Обект", "Хора", "Абстракция", "Природа", "Абстракция", "Абстракция", "Природа", "Обект",
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

string getRandomWord(string difficulty, string language, short randomNumber) {
    if (difficulty == "1") {
        if (language == "en") {
            return wordsEn1Difficulty[randomNumber];
        }
        else if (language == "bg") {
            return wordsBg1Difficulty[randomNumber];
        }
        else if (language == "ru") {
            return wordsRu1Difficulty[randomNumber];
        }
    }
    else if (difficulty == "2") {
        if (language == "en") {
            return wordsEn2Difficulty[randomNumber];
        }
        else if (language == "bg") {
            return wordsBg2Difficulty[randomNumber];
        }
        else if (language == "ru") {
            return wordsRu2Difficulty[randomNumber];
        }
    }
    else if (difficulty == "3") {
        if (language == "en") {
            return wordsEn3Difficulty[randomNumber];
        }
        else if (language == "bg") {
            return wordsBg3Difficulty[randomNumber];
        }
        else if (language == "ru") {
            return wordsRu3Difficulty[randomNumber];
        }
    }
    return wordsEn2Difficulty[randomNumber];
}

string getHintForRandomWord(string difficulty, string language, short randomNumber) {
    if (difficulty == "1") {
        if (language == "en") {
            return hintsEn1Difficulty[randomNumber];
        }
        else if (language == "bg") {
            return hintsBg1Difficulty[randomNumber];
        }
        else if (language == "ru") {
            return hintsRu1Difficulty[randomNumber];
        }
    }

    else if (difficulty == "2") {
        if (language == "en") {
            return hintsEn2Difficulty[randomNumber];
        }
        else if (language == "bg") {
            return hintsBg2Difficulty[randomNumber];
        }
        else if (language == "ru") {
            return hintsRu2Difficulty[randomNumber];
        }
    }

    else if (difficulty == "3") {
        if (language == "en") {
            return hintsEn3Difficulty[randomNumber];
        }
        else if (language == "bg") {
            return hintsBg3Difficulty[randomNumber];
        }
        else if (language == "ru") {
            return hintsRu3Difficulty[randomNumber];
        }
    }
    return hintsEn2Difficulty[randomNumber];
}