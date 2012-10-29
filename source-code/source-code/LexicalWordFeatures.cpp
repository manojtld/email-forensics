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
            //returns the number of words with the length i

int LexicalWordFeatures::wordnumber(int i) {

    map<string,int>::iterator it;
    int count = 0;
    it = wordmap.begin();
    while(it != wordmap.end()) {
    string k = (*it).first;
    if(k.length() == i)
       oount = count+(*it).second;

    it++;
    }
    return count;
    }

//returns number of words in a map k that have appeared i times

int word-number(map<string,int> k,int i) {

    map<string,int>::iterator it;
    it = k.begin();
    int count = 0;
    while(it != k.end()) {
    if((*it).second == i)
     count++;
    }
    return count;
    }

int LexicalWordFeatures::yules-measure() {

   
    map<string,int>::iterator it;
    it = wordmap.begin();
    int high;
    while(it != wordmap.end()) {
    if((*it).second > high)
     high = (*it).second;
    }

    it = wordmap.begin();
    int i=1;
    int sum = 0;
    nt squaresum = 0;
    while(i <= high) {
 
     int k = word-number(wordmap,i);
     sum = sum + i*k;
     squaresum = squaresum + i*i*k;
     i++;it++;
    }

    float yules = 10*10*10*10(squaresum - 1)/(sum * sum);
    
    return yules;

    }


     






    


float LexicalWordFeatures::yules-measure()  {





/* 
 
 Hapax Legomena : Outputs all words that have been used only once
 Hapax Dislegomena : Outputs all words that have been used more than once
 
 Yule's K Measure : 
 refer http://www.scribd.com/doc/26850869/Yule-s-k-Final-No-Name
Manoj Please complete this. I will not be able to do this as i will be in a place where internet is a problem. 

I hope above two are very easy as i have wordMap. 
For yule's measure you have to do some hacks to get nuber of words with same frequency as a particular word. 
*/