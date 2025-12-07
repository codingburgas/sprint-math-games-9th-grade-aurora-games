#ifndef UTILS_H
#define UTILS_H

void wait(double seconds); // Function to pause execution for a specified number of seconds
void screenClear(); // Function to clear the console screen
void putData(string inputLanguage, string inputDifficulty); // Function to save language and difficulty settings to a file
void getData(); // Function to get language and difficulty settings from a file
short getRandomNumber(short from, short to); // Function to generate a random number within a specified range
#endif