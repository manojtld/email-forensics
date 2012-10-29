//
//  LexicalWordFeatures.cpp
//  source-code
//
//  Created by Guna Prasaad on 27/10/12.
//  Copyright (c) 2012 Guna Prasaad. All rights reserved.
//

#include "LexicalWordFeatures.h"
#include <string>


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

/*int LexicalWordFeatures::wordnumber(int i) {

    map<string,int>::iterator it;
    int count = 0;
    it = wordMap.begin();
    while(it != wordMap.end()) {
    string k = (*it).first;
    if(k.length() == i)
       oount = count+(*it).second;

    it++;
    }
    return count;
    }  */

//returns number of words in a map k that have appeared i times

int wordnumber(map<string,int> k,int i) {

    map<string,int>::iterator it;
    it = k.begin();
    int count = 0;
    while(it != k.end()) {
    if((*it).second == i)
     count++;
     
     it++;
    }
    return count;
    }

float LexicalWordFeatures::yulesmeasure() {

   
    map<string,int>::iterator it;
    it = wordMap.begin();
    int high=0;
    while(it != wordMap.end()) {
    if((*it).second > high)
     high = (*it).second;
     
     it++;
    }

    int i=1;
    int sum = 0;
    int squaresum = 0;
    while(i <= high) {
     map<string,int>::iterator it;
     it = wordMap.begin();
     int k = 0;
     while(it != wordMap.end()) {
    	if((*it).second == i)
    	 k++;
     
     	it++;
   	 }
     sum = sum + i*k;
     squaresum = squaresum + i*i*k;
     i++;
    }

    float yules = 10*10*10*10*(squaresum - 1)/(sum * sum);
    
    cout<<yules;

    }
    
    
    
    string LexicalWordFeatures::hapexlegomena() {

			map<string,int>::iterator ite;
			ite = wordMap.begin();
			int probe =0;
			while(ite != wordMap.end())
		{
 			if((*ite).second == 1){
			 	legomenavector.push((*ite).first);
			 	probe = 1;
			 }
 		     
			 ite++;
		}
             if(probe == 1)
             {
             	while (legomenavector.size() != 0 ) {
 				cout<<legomenavector.front()<<" ";
 				legomenavector.pop();
             }
             }
             else
             cout<<"";
			 
 			}
 			

		string LexicalWordFeatures::hapexdislegomena() {

			map<string,int>::iterator ite;
			ite = wordMap.begin();
			int probe =0;
			while(ite != wordMap.end())
		{
 			if((*ite).second != 1){
			 	dislegomenavector.push((*ite).first);
			 	probe = 1;
			 }
 		     
			 ite++;
		}
             if(probe == 1)
             {
             	while (dislegomenavector.size() != 0 ) {
 				cout<<dislegomenavector.front()<<" ";
 				dislegomenavector.pop();
             }
             }
             else
             cout<<"";
			 
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