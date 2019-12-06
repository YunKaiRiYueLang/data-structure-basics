#pragma once
#include <string>
#include <vector>

#define range 9973//哈希表 表长
///#define multiply 23//

using namespace std;

string handleString(string inputWord);//处理字符串:空格 标点 大小写 长度太短的单词

struct hashNode//定义链表节点:单词 词频 节点指针
{
	string word;
	int count;
	hashNode *next;
}; 
