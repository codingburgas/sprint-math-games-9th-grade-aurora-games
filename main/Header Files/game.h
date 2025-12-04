#ifndef GAME_H
#define GAME_H
#include <string>
using namespace std;

void startGameWithBot(string word, string hint);
void startGame1v1(string word, string hint);

void displayWordState(char openedLetters[], std::string word);
bool isWordGuessed(char openedLetters[], std::string word);
bool isLetterGuessed(char letter, char guessedLetters[]);
void showGameMenu(char openedLetters[], std::string hint, short player1Points, short player2Points);
void win(short who);
bool isLetterInAlphabet(char letter, std::string language);
short indexOfLetterInWord(char letter, std::string word);
bool isWordGuessedByWordGuess(std::string guess, std::string word);
short howMuchLettersGuessed(char openedLetters[], std::string word);
char getRandomUnguessedLetter(std::string language, char guessedLetters[]);
bool exitFromGame();
void wheelAnimation(short currentIndex);
short spinWheel();
void showPlusMenu();
short getIndexOfRandomUnopenedLetter(char openedLetters[]);
#endif