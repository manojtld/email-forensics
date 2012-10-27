//
//  LexicalLetterFeatures.h
//  source-code
//
//  Created by Guna Prasaad on 27/10/12.
//  Copyright (c) 2012 Guna Prasaad. All rights reserved.
//

#ifndef __source_code__LexicalLetterFeatures__
#define __source_code__LexicalLetterFeatures__

#include <iostream>
#include <map>
#define NONE 0
#define END_OF_SENTENCE 1
#define END_OF_WORD 2

using namespace std;

class LexicalLetterFeatures {
    int N;
    int digits;
    int letters;
    int uppercaseLetters;
    int specialCharCount;
    int spaces;
    int tabs;
    int shiftReturns;
    map<char,int> alphabets;
    map<char,int> specialCharacters;
    public :
    LexicalLetterFeatures();
    int addCharacter(char c);
};
#endif /* defined(__source_code__LexicalLetterFeatures__) */
