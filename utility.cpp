/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Vibha Ganapathy
 * vibhagan
 *
 * EECS 183: Project 3
 * Fall 2025
 *
 * Implementing utility functions
 */

#include "utility.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************


string toUpperCase(string original) {
    //the variable y represents the result
    string y;
    for (int i = 0; i < original.length(); i++) {
        //the variable x represents the letter
        char x = original[i];
        if (x >= 'a' && x <= 'z') {
            x = x - 'a' + 'A';
        }
        y = y + x;
    }
    return y;
}

string removeNonAlphas(string original) {
    string y;
    for (int i = 0; i < original.length(); i++) {
        char x = original[i];
        if (x >= 'a' && x <= 'z') {
            y = y + x;
        }
        else if (x >= 'A' && x <= 'Z') {
            y = y + x;
        }
    }
    return y;
}

int charToInt(char original) {
    if (original == '0') {
        return 0;
    }
    else if (original == '1') {
        return 1;
    }
    else if (original == '2') {
        return 2;
    }
    else if (original == '3') {
        return 3;
    }
    else if (original == '4') {
        return 4;
    }
    else if (original == '5') {
        return 5;
    }
    else if (original == '6') {
        return 6;
    }
    else if (original == '7') {
        return 7;
    }
    else if (original == '8') {
        return 8;
    }
    else {
        return 9;
    }
}

string removeDuplicate(string original) {
    string y;
    for (int i = 0; i < original.length(); i++) {
        char x = original[i];
        bool seen = false;
        for (int j = 0; j < y.length(); j++) {
            if (y[j] == x) {
                seen = true;
                break;
            }
        }
        if (!seen) {
            y += x;
        }
    }
    return y;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
