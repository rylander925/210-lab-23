/*
COMSC-210 | Lab 23 | Rylan Der
IDE Used: Visual Studio Code
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;
const int IGNORE_STREAM_CHARS = 100;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();




    return 0;
}

/**
 * Output and receive user input for goat management menu
 * Validates input
 * @return Menu option as an integer: 1=Add, 2=Delete, 3=Output List, 4=Quit
 */
int main_menu() {
    int choice;

    //output menu once
    cout << "*** GOAT MANAGER 3001 ***" << endl
         << "[1] Add a goat"            << endl
         << "[2] Delete a goat"         << endl
         << "[3] List goats"            << endl
         << "[4] Quit"                  << endl;
    
    //validate input
    do {
        if (cin.fail()) {
            cout << "Choice must be an integer" << endl;
            cin.clear();
        } else if (choice < 1 || choice > 4) {
            cout << "Choice must be 1, 2, 3, or 4" << endl;
        }
        cin.ignore(IGNORE_STREAM_CHARS, '\n');

        cout << "Choice -->" << endl;
        cin >> choice;
    } while(cin.fail() || choice < 1 || choice > 4);

    return choice;
}

