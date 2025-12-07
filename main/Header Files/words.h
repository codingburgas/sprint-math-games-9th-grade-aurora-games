#ifndef WORDS_H
#define WORDS_H
#include <string>
using namespace std;

string getRandomWord(string difficulty, string language, short randomNumber); // Retrieves a random 7-letter word based on difficulty, language, and a random index
string getHintForRandomWord(string difficulty, string language, short randomNumber); // Retrieves a hint for a random word based on difficulty, language, and a random index
#endif