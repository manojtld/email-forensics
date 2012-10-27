//
//  LexicalLetterFeatures.cpp
//  source-code
//
//  Created by Guna Prasaad on 27/10/12.
//  Copyright (c) 2012 Guna Prasaad. All rights reserved.
//

#include "LexicalLetterFeatures.h"

bool isSpecialCharacter(char ch) {
    int ascii = ch;
    return ((ascii >= 33 && ascii <= 47) || (ascii >= 58 && ascii <= 64) || (ascii >= 91 && ascii <= 96) || (ascii >= 123 && ascii <= 126));
}

bool isSentenceTerminator(char ch) {
    return (ch == '!' || ch == '.' || ch == ';');
}

LexicalLetterFeatures::LexicalLetterFeatures() {
    N = 0;
    digits = 0;
    letters = 0;
    uppercaseLetters = 0;
    spaces = 0;
    tabs = 0;
    shiftReturns = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        alphabets.insert(pair<char,int>(c,0));
    }
    for(char c = '!'; c <= '/'; c++) {
        specialCharacters.insert(pair<char,int>(c,0));
    }
    for(char c = ':'; c<= '@'; c++) {
        specialCharacters.insert(pair<char,int>(c,0));
    }
    for(char c = '['; c<= '_'; c++) {
        specialCharacters.insert(pair<char,int>(c,0));
    }
    for(char c = '{'; c<= '~'; c++) {
        specialCharacters.insert(pair<char,int>(c,0));
    }
}

int LexicalLetterFeatures::addCharacter(char ch) {
    int retVal = NONE;
    N++;    //Increasing total characters count
    
    if(isalpha(ch)) {
        letters++;          //Increasing total alphabets count
        alphabets[tolower(ch)]++;    //Increasing specific alphabet count
        if(isupper(ch)) {
            uppercaseLetters++;     //Increasing count for uppercase letters
        }
    } else if (isdigit(ch)) {
        digits++;
    } else if (isSentenceTerminator(ch)) {
        retVal = END_OF_SENTENCE;
    } else if (isspace(ch)) {
        if(ch == ' ') {
            spaces++;
        } else if (ch == '\t') {
            tabs++;
        } else {
            shiftReturns++;
        }
        retVal = END_OF_WORD;
    } else if (isSpecialCharacter(ch)) {
        specialCharCount++;     //Increasing total spl char count
        specialCharacters[ch]++;    //Increasing specific count
    }
    return retVal;
}