//
//  LexicalWordFeatures.cpp
//  source-code
//
//  Created by Guna Prasaad on 27/10/12.
//  Copyright (c) 2012 Guna Prasaad. All rights reserved.
//

#include "LexicalWordFeatures.h"

LexicalWordFeatures::LexicalWordFeatures() {
    totalCharactersCount = 0;
    tokenCount = 0;
    sentenceCount = 0;
    totalLettersCount = 0;
    shortWordsCount = 0;
    for(int i = 0; i< 20; i++) {
        wordLengthFrequencyTable[i] = 0;
    }
}

void LexicalWordFeatures::incrementCharacterCount() {
    totalCharactersCount++;
}

void LexicalWordFeatures::addWord(string s) {
    tokenCount++;
    totalLettersCount += s.length();
    if (s.length() <= 3) {
        shortWordsCount++;
    }
    wordLengthFrequencyTable[s.length()-1]++;
    if(wordMap.find(s) == wordMap.end()) {
        wordMap.insert(pair<string,int>(s,1));
    } else {
        wordMap[s]++;
    }
}

void LexicalWordFeatures::addSentence(string s) {
    sentenceCount++;
    tokenCount++;
    totalLettersCount += s.length();
    if (s.length() <= 3) {
        shortWordsCount++;
    }
    wordLengthFrequencyTable[s.length()-1]++;
    if(wordMap.find(s) == wordMap.end()) {
        wordMap.insert(pair<string,int>(s,1));
    } else {
        wordMap[s]++;
    }
}

/* 
 
 Hapax Legomena : Outputs all words that have been used only once
 Hapax Dislegomena : Outputs all words that have been used more than once
 
 Yule's K Measure : 
 refer http://www.scribd.com/doc/26850869/Yule-s-k-Final-No-Name
Manoj Please complete this. I will not be able to do this as i will be in a place where internet is a problem. 

I hope above two are very easy as i have wordMap. 
For yule's measure you have to do some hacks to get nuber of words with same frequency as a particular word. 
*/