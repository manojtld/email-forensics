//
//  main.cpp
//  source-code
//
//  Created by Guna Prasaad on 21/10/12.
//  Copyright (c) 2012 Guna Prasaad. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/*Edit main.cpp to make appropriate calls
 First addCharacter to LexicalLetterFeatures Class
 Then based on return call LexicalWordFeatures appropriately. Remember you have to keep appending every letter to form the string to pass to LexicalWordFeatures. */

int main(int argc, const char * argv[])
{

   string word;
    ifstream file;
	int letters=0;
	int characters = 0;
    int sentences = 0;
    int sentence_word_count = 0;
    int words = 0;
    int word_letter_count = 0;
	int specialchars = 0;
	int uppercase = 0;
	int lowercase = 0;
	int numbers = 0;
	int spaces = 0;
	int punctuation = 0;
	int tabs = 0;
	int ascii;
    int token_count= 0;
    int sentence_count = 0; //note sentence does not mean a sentence, it is a clause
    float average_letter_count = 0.0;
    float average_word_count = 0.0;

	
	
	file.open("Myfile.txt"); 
	if(!file)
	{
		cout << "Could not open file" << endl;
		return 1;
	}
	char ch;
	while(file.get(ch))
	{ 
			
			ascii = ch;
			
        if(ch=='!' || ch == '?' || ch == '.')
            {
                punctuation++;
            
                /*word metrics update*/
                average_letter_count = (average_letter_count*token_count + word_letter_count)/++token_count;
                word_letter_count = 0;
            
                /*sentence metrics update*/
                average_word_count = (average_word_count*sentence_count + sentence_word_count)/++sentence_count;
                sentence_word_count = 0;
            
            }
			else if((ascii>64)&&(ascii<91))
			{
			    uppercase++; word_letter_count++;
			}
			
			else if((ascii>96)&&(ascii<123))
			{
				lowercase++; word_letter_count++;
			}
			
			else if((ascii>=39)&&(ascii<=64))
			{
                characters++; 
			}
			
			else if(isdigit(ch))
			{
				numbers++;
			}
			
			else if(isspace(ch))
			{
				spaces++;
                average_letter_count = (average_letter_count*token_count + word_letter_count)/++token_count;
                word_letter_count = 0;
                sentence_word_count++;
			}
			
            else if(ispunct(ch))
			{
				punctuation++;
                
                /*word metrics update*/
                average_letter_count = (average_letter_count*token_count + word_letter_count)/++token_count;
                word_letter_count = 0;
            }

			else if(ch == '\t')
			{
				tabs++;
                average_letter_count = (average_letter_count*token_count + word_letter_count)/++token_count;
                word_letter_count = 0;
                ++sentence_word_count;
                
			}
            else if (ch == '.') {
                sentences++;
                average_letter_count = (average_letter_count*token_count + word_letter_count)/++token_count;
                word_letter_count = 0;
                sentence_word_count++;
                average_word_count = (average_word_count*sentence_count + sentence_word_count)/++sentence_count;
                sentence_word_count = 0;
            }
			
            else
            {
            	specialchars++;
            }
			
	}
	letters = uppercase+lowercase;
	cout << "Total number of letters \t" << letters << endl;
	cout << "characters are " << characters << endl; 
	cout << "letter to character count ratio" << (float)letters/(float)characters <<endl;
	cout << "digits to character count ratio" << (float)numbers/(float)characters <<endl;
	cout << "uppercase letters to character count ratio" << (float)uppercase/(float)characters <<endl;
	cout << "tabs to character count ratio" << (float)tabs/(float)characters <<endl;
    cout << "number of spaces"<<spaces<<endl;
    cout << "total number of words "<<token_count<<endl;
    cout << "total number of sentences "<<sentence_count<<endl;
    cout << "average words in a sentence" << average_word_count<<endl;
    cout << "average letters in a word"<<average_letter_count<<endl;
    
	
	file.close();
    return 0;
}

