//
//  LexicalWordFeatures.h
//  source-code
//
//  Created by Guna Prasaad on 27/10/12.
//  Copyright (c) 2012 Guna Prasaad. All rights reserved.
//

#ifndef __source_code__LexicalWordFeatures__
#define __source_code__LexicalWordFeatures__

#include <iostream>
#include <map>
#include <string>
using namespace std;

class LexicalWordFeatures {
    int totalCharactersCount;
    int tokenCount;
    int sentenceCount;
    int totalLettersCount;
    int shortWordsCount;
    int wordLengthFrequencyTable[20];
    map<string, int> wordMap;
public:
    LexicalWordFeatures();
    void incrementCharacterCount(); 
    void addWord(string s);
    void addSentence(string s);
};

#endif /* defined(__source_code__LexicalWordFeatures__) */
