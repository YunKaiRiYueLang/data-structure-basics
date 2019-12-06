#include "Hash.h"
#include "Globle.h"
#include <string>
using namespace std;
Hash::Hash()
{
}

Hash::~Hash()
{
}

void Hash::hashWord(string word)
{
	int key = calculateHash(word);
	hashNode *tmp = index[key];
	while (tmp != NULL)
	{
		if (tmp->word == word)
		{
			tmp->count++;
			return;
		}
		tmp = tmp->next;
		collision += 1;
	}
	hashNode *newNode = new hashNode;
	newNode->count = 1;
	newNode->word = word;
	newNode->next = index[key];
	index[key] = newNode;/*��ͻ�˾������λ�����һ������*/
}

int Hash::calculateHash(string word)
{
	int h = 0;
	for (int i = 0; i < word.size(); i++)
	{
		h = 31 * h + word[i];
		h %= 65536;
	}
	int key = h % range;
	return key;
}

void Hash::writeOutTable()//д���ʱ��,Ӧ��˳���Ÿ���;
{
	for (int i = 0; i < range; i++)
	{
		for (hashNode *tmp = index[i]; tmp != NULL; tmp = tmp->next)
		{
			hashNode outTemp;
			outTemp.count = tmp->count;
			outTemp.word = tmp->word;
			outTemp.next = NULL;
			outTable.push_back(outTemp);
		}
	}
}
void Hash::insertionSort()
{
	for (int P = 1; P < outTable.size(); P++)
	{
		hashNode tmp = outTable[P]; int i = 0;
		for (i = P; i > 0 && tmp.count > outTable[i - 1].count; i--)// ��������õ��ݼ�����
		{
			outTable[i]= outTable[i - 1];
		}
		outTable[i] = tmp;
	}
}
void Hash::limitLength(int &length)
{

}