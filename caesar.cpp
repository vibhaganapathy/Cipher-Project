/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Vibha Ganapathy
 * vibhagan
 *
 * EECS 183: Project 3
 * Fall 2025
 *
 * Caesar Cipher
 */

#include "caesar.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

char shiftAlphaCharacter(char c, int n) {
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            if (c == 'Z') {
                c = 'A';
            }
            else if (c == 'z') {
                c = 'a';
            }
            else {
                c++;
            }
        }
    }
    else {
        for (int i = 0; i < -n; i++) {
            if (c == 'A') {
                c = 'Z';
            }
            else if (c == 'a') {
                c = 'z';
            }
            else {
                c--;
            }
        }
    }
    return c;
}

string caesarCipher(string original, int key, bool encrypt) {
    if (encrypt == true) {
        for (int i = 0; i < original.length(); i++) {
            if (original[i] >= 'A' && original[i] <= 'Z') {
                original[i] = shiftAlphaCharacter(original[i], key);
            }
            else if (original[i] >= 'a' && original[i] <= 'z') {
                original[i] = shiftAlphaCharacter(original[i], key);
            }
        }
        return original;
    }
    else {
        for (int i = 0; i < original.length(); i++) {
            if (original[i] >= 'A' && original[i] <= 'Z') {
                original[i] = shiftAlphaCharacter(original[i], -key);
            }
            else if (original[i] >= 'a' && original[i] <= 'z') {
                original[i] = shiftAlphaCharacter(original[i], -key);
            }
        }
        return original;
    }
}
