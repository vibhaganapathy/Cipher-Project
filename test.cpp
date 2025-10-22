/*
 * test.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Vibha Ganapathy
 * vibhagan
 *
 * EECS 183: Project 3
 * Fall 2025
 *
 * Testing the functions
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testShiftAlphaCharacter();
void testMixKey();
void testFillGrid();
void testFindInGrid();
void testCaesarCipher();
void testVigenereCipher();
void testPolybiusSquare();

void startTests() {
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testMixKey();
    testFillGrid();
    testFindInGrid();
    testCaesarCipher();
    testVigenereCipher();
    testPolybiusSquare();

    return;
}

void testToUpperCase() {
    cout << "Now testing function toUpperCase()" << endl;
    cout << "Expected: \"DIAG @ 11 P.M.\", Actual: \""
         << toUpperCase("Diag @ 11 p.m.") << "\"" << endl;
}

void testRemoveNonAlphas() {
    cout << "Now testing function removeNonAlphas()" << endl;
    cout << "Expected: \"Diagpm\", Actual: \""
         << removeNonAlphas("Diag @ 11 p.m.") << "\"" << endl;
    cout << "Expected: \"EECS\", Actual: \""
         << removeNonAlphas("__E-E_C+S!!") << "\"" << endl;
    cout << "Expected: \"\", Actual: \""
         << removeNonAlphas("") << "\"" << endl;
}

void testRemoveDuplicate() {
    cout << "Now testing function removeDuplicate()" << endl;
    cout << "Expected: \"HELOWRD\", Actual: \""
         << removeDuplicate("HELLOWORLD") << "\"" << endl;
    cout << "Expected: \"ECS183\", Actual: \""
         << removeDuplicate("EECCSS118833") << "\"" << endl;
}

void testCharToInt() {
    cout << "Now testing function charToInt()" << endl;
    cout << "Expected: 0, Actual: " << charToInt('0') << endl;
    cout << "Expected: 5, Actual: " << charToInt('5') << endl;
    cout << "Expected: 9, Actual: " << charToInt('9') << endl;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function shiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'" << endl;
    cout << "Expected: 'C', Actual: '" << shiftAlphaCharacter('X', 5) << "'" << endl;
    cout << "Expected: 'V', Actual: '" << shiftAlphaCharacter('X', 50) << "'" << endl;
    return;
}

void testFillGrid() {
    cout << "Now testing function fillGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    printGrid(grid);
}

void testMixKey() {
    cout << "Now testing function mixKey()" << endl;
    cout << "Expected: 'POLYBIUSACDEFGHJKMNQRTVWXZ0123456789', Actual: '"
         << mixKey("POLYBIUS") << "'" << endl;
}

void testFindInGrid() {
    cout << "Now testing function findInGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: '00', Actual: '" << findInGrid('A', grid) << "'" << endl;
    cout << "Expected: '01', Actual: '" << findInGrid('B', grid) << "'" << endl;
}

void testCaesarCipher() {
    cout << "Now testing function caesarCipher()" << endl;
    cout << "Expected: \"Cuuj cu qj jxu Tyqw qj 11 f.c.\", Actual: \""
         << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << "\"" << endl;
    cout << "Expected: \"Meet me at the Diag at 11 p.m.\", Actual: \""
         << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << "\"" << endl;
}

void testVigenereCipher() {
    cout << "Now testing function vigenereCipher()" << endl;
    cout << "Expected: \"Euyb dv ee lxy Lzrk ll 11 f.g.\", Actual: \"" << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true) << "\"" << endl;
    cout << "Expected: \"Meet me at the Diag at 11 p.m.\", Actual: \"" << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) << "\"" << endl;
}

void testPolybiusSquare() {
    cout << "Now testing function polybiusSquare()" << endl;
    char grid[SIZE][SIZE];
    cout << "Expected: \"11110533 000102 1533 341411 04113334\", Actual: \""
         << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << "\"" << endl;
    cout << "Expected: \"EECS 183 IS THE BEST\", Actual: \""
         << polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false) << "\"" << endl;
}




