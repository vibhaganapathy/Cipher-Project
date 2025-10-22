/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Vibha Ganapathy
 * vibhagan
 *
 * EECS 183: Project 3
 * Fall 2025
 *
 * Polybius Cipher
 */


#include "polybius.h"
#include <string>
using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string mixKey(string key) {
    for (char h = 'A'; h <= 'Z'; h++) {
        bool z = false;
        for (int j = 0; j < key.length(); j++) {
            if (key[j] == h) {
                z = true;
            }
        }
        if (!z) {
            key += h;
        }
    }
    
    for (char h = '0'; h <= '9'; h++) {
        bool z = false;
        for (int j = 0; j < key.length(); j++) {
            if (key[j] == h) {
                z = true;
            }
        }
        if (!z) {
            key += h;
        }
    }
    return key;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    int k = 0;
    for (int f = 0; f < SIZE; f++) {
        for (int c = 0; c < SIZE; c++) {
            grid[f][c] = content[k];
            k++;
        }
    }
    return;
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    string s;
    for (int f = 0; f < SIZE; f++) {
        for (int p = 0; p < SIZE; p++) {
            if (grid[f][p] == c) {
                s += char('0' + f);
                s += char('0' + p);
            }
        }
    }
    return s;
}


string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt) {
    string content = mixKey(key);
    fillGrid(grid, content);

    if (encrypt == true) {
        string m;
        for (int i = 0; i < original.length(); i++) {
            char h = original[i];
            if (h == ' ') {
                m += ' ';
            } else {
                m += findInGrid(h, grid);
            }
        }
        return m;
    }
    else {
        string n;
        for (int i = 0; i < original.length(); i++) {
            if (original[i] == ' ') {
                n += ' ';
            } else {
                int f = charToInt(original[i]);
                i++;
                int p = charToInt(original[i]);
                n += grid[f][p];
            }
        }
        return n;
    }
}
