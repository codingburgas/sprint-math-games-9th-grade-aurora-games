#ifndef GAME_H
#define GAME_H
#include <string>
using namespace std;

void startGameWithBot(string word, string hint); // Function to start the game against a bot (single player).
void startGame1v1(string word, string hint); // Function to start the game in 1v1 mode (two players).
void displayWordState(char openedLetters[], string word);
bool isWordGuessed(char openedLetters[], string word);
bool isLetterGuessed(char letter, char guessedLetters[]); 
void showGameMenu(char openedLetters[], string hint, short player1Points, short player2Points);
void win(short who);
bool isLetterInAlphabet(char letter, string language); 
short indexOfLetterInWord(char letter, string word); // Finds the index of a letter in the word; returns -1 if not found.
bool isWordGuessedByWordGuess(string guess, string word); 
short howMuchLettersGuessed(char openedLetters[], string word); // Counts how many letters have been guessed in the word.
char getRandomUnguessedLetter(string language, char guessedLetters[]); // Gets a random unguessed letter from the alphabet based on the language.
bool exitFromGame(); // Prompts the user to confirm exiting the game; returns true if confirmed.
void wheelAnimation(short currentIndex); // Displays the spinning wheel animation at a given index.
short spinWheel(); // Simulates spinning the wheel and returns the final index.
void showPlusMenu(); 
short getIndexOfRandomUnopenedLetter(char openedLetters[]); // Gets a random index of an unopened letter in the word.
#endif