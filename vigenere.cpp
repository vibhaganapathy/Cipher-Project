/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Vibha Ganapathy
 * vibhagan
 *
 * EECS 183: Project 3
 * Fall 2025
 *
 * Vignere Cipher
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string vigenereCipher(string original, string keyword, bool encrypt) {
    string key = toUpperCase(removeNonAlphas(keyword));
    int j = 0;
    for (int i = 0; i < original.length(); i++) {
        char c = original[i];
        
        bool a = (c >= 'A' && c <= 'Z');
        bool b = (c >= 'a' && c <= 'z');
        if (a || b) {
            if (j == key.length()) {
                j = 0;
            }
            int k = key[j] - 'A';
            if (!encrypt) {
                k = -k;
            }
            original[i] = shiftAlphaCharacter(c, k);
            j++;
        }
    }
    return original;
}
