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
	//Ϊ���߼��ϵ�����,û��ֱ���ں�����ӳɶεĴ���.����д����,����ʹ��.дʱ�鷳��һЩ,�úͿ�����ʱ����ܶ�.
	void insertionSort();// �ƶ����ݷ�ָ��,�����ڳ�vectorǰ����.
	void limitLength(int &length);//���Ƶ�������.
}; 
