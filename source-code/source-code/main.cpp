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

int main(int argc, const char * argv[])
{

   string word;
    ifstream file;
	int letters=0;
	int characters = 0;
	int specialchars = 0;
	int uppercase = 0;
	int lowercase = 0;
	int numbers = 0;
	int spaces = 0;
	int punctuation = 0;
	int tabs = 0;
	int ascii;

	
	
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
			
			if((ascii>64)&&(ascii<91)) 
			{
			    uppercase++;
			}
			
			else if((ascii>96)&&(ascii<123))
			{
				lowercase++;
			}
			
			else if((ascii>=39)&&(ascii<=64))
			{
                characters++;	
			}
			
			else if(!isalpha(ch))
			{
				numbers++;
			}
			
			else if(isspace(ch))
			{
				spaces++;
			}
			
			else if(ispunct(ch))
			{
				punctuation++;
			}
			else if(ch == '\t')
			{
				tabs++;
			}
			
            else
            {
            	specialchars++;
            }
			
	}
	letters = uppercase+lowercase;
	cout << "countletters are " << letters << endl;
	cout << "characters are " << characters << endl; 
	cout << "letter to character count ratio" << letters/characters <<endl;
	cout << "digits to character count ratio" << numbers/characters <<endl;
	cout << "uppercase letters to character count ratio" << uppercase/characters <<endl;
	cout << "tabs to character count ratio" << tabs/characters <<endl;
	
	file.close();
    std::cout << "Hello, World!\n";
    return 0;
}

