#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../Header Files/globals.h"
#include "../Header Files/utils.h"

using namespace std;

void wait(double seconds) {
    int start = clock();
    while (clock() - start < (seconds * 1000)) {}
}

short getRandomNumber(short from, short to) {
    return from + rand() % (to - from + 1);
}

void screenClear() {
    system("cls");
}

void getData() {
    string path = "../../data.txt";
    ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    {
        cout << R"(
                    +--------------------------------------+
                    |     Error: File can not be opened    |
                    +--------------------------------------+
)" << endl;
    }
    else
    {
        if (getline(fin, language)) {
            if (getline(fin, difficulty)) {
                cout << language << endl;
                cout << difficulty << endl;
            }
            else {
                cout << R"(
                    +--------------------------------------+
                    |              ERROR                   |
                    +--------------------------------------+
                    |  Only one parameter found:           |
                    |  )" << language << R"(               |
                    +--------------------------------------+
)" << endl;
            }
        }
        else {
            cout << "Error: File is empty" << endl;
        }
    }
    fin.close();
}

void putData(string inputLanguage, string inputDifficulty) {
    string path = "../../data.txt";
    ofstream fout;
    fout.open(path, ios::out);

    if (!fout.is_open())
    {
        cout << "Error: File can not be opened" << endl;
    }
    else {
        fout << language << endl;
        fout << difficulty << endl;

        fout.close();
    }
}