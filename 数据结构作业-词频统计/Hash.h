#pragma once
#include <vector>
#include <string>
#include "Globle.h"

class Hash
{
	hashNode *index[range] = { NULL };
	int collision = 0;
public:
	Hash();
	~Hash();
	void hashWord(string word);
	void writeOutTable();
	int calculateHash(string word);
	vector <hashNode> outTable;
	//为了逻辑上的清晰,没有直接在函数里加成段的代码.单独写出来,单独使用.写时麻烦了一些,用和看代码时方便很多.
	void insertionSort();// 移动数据非指针,可以在成vector前插入.
	void limitLength(int &length);//限制单词数量.
}; 
