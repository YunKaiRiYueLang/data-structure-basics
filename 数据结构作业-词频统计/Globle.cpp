#include "Globle.h"

string handleString(string inputWord)
{
	string word;
	for (int i = 0; i < inputWord.size(); i++)
	{
		if (inputWord[i] >= 65 && inputWord[i] <= 90)
		{
			char tmp = inputWord[i] + 32;
			word.push_back(tmp);
		}
		else if (inputWord[i] >= 97 && inputWord[i] <= 122)
		{
			word.push_back(inputWord[i]);
		}
		else if (inputWord[i] == 45 || inputWord[i] == 39)
		{
			word.push_back(inputWord[i]);
		}
	}
	if (word.size() < 3)
	{
		word = "";
	}
	return word;
}