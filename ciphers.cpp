/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Vibha Ganapathy
 * vibhagan
 *
 * EECS 183: Project 3
 * Winter 2025
 *
 * Function implementations for ciphers
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************

void ciphers() {
    string cipherType;
    string mode;
    string message;
    string key;

    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): " << endl;
    getline(cin, cipherType);
    cipherType = toUpperCase(cipherType);

    if (!(cipherType == "CAESAR" || cipherType == "C" ||
          cipherType == "VIGENERE" || cipherType == "V" ||
          cipherType == "POLYBIUS" || cipherType == "P")) {
        cout << "Invalid cipher!" << endl;
        return;
    }

    cout << "Encrypt or decrypt: " << endl;
    getline(cin, mode);
    mode = toUpperCase(mode);

    bool encrypt;
    if (mode == "ENCRYPT" || mode == "E") {
        encrypt = true;
    } else if (mode == "DECRYPT" || mode == "D") {
        encrypt = false;
    } else {
        cout << "Invalid mode!" << endl;
        return;
    }

    cout << "Enter a message: " << endl;
    getline(cin, message);

    if (cipherType == "POLYBIUS" || cipherType == "P") {
        for (int i = 0; i < (int)message.length(); i++) {
            char h = message[i];
            if (encrypt) {
                if (!( (h >= 'A' && h <= 'Z') || (h >= 'a' && h <= 'z') || h == ' ' )) {
                    cout << "Invalid message!" << endl;
                    return;
                }
            } else {
                if (!( (h >= '0' && h <= '9') || h == ' ' )) {
                    cout << "Invalid message!" << endl;
                    return;
                }
            }
        }
        message = toUpperCase(message);
    }

    cout << "What is your key: " << endl;
    getline(cin, key);

    string output;

    if (cipherType == "CAESAR" || cipherType == "C") {
        int change = stoi(key);
        output = caesarCipher(message, change, encrypt);
    }
    else if (cipherType == "VIGENERE" || cipherType == "V") {
        string key2 = removeNonAlphas(key);
        if (key2.length() == 0) {
            cout << "Invalid key!" << endl;
            return;
        }
        output = vigenereCipher(message, key, encrypt);
    }
    else {
        key = toUpperCase(key);
        key = removeDuplicate(key);

        for (int i = 0; i < (int)key.length(); i++) {
            char c = key[i];
            bool isAlpha = (c >= 'A' && c <= 'Z');
            bool isDigit = (c >= '0' && c <= '9');
            if (!(isAlpha || isDigit)) {
                cout << "Invalid key!" << endl;
                return;
            }
        }

        char grid[SIZE][SIZE];
        output = polybiusSquare(grid, key, message, encrypt);
    }

    if (encrypt) {
        cout << "The encrypted message is: " << output << endl;
    } else {
        cout << "The decrypted message is: " << output << endl;
    }
}

