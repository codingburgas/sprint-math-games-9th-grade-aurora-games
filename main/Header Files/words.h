#ifndef WORDS_H
#define WORDS_H
#include <string>
using namespace std;

string getRandomWord(string difficulty, string language, short randomNumber);
string getHintForRandomWord(string difficulty, string language, short randomNumber);
#endif