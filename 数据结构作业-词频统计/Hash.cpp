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
	index[key] = newNode;/*冲突了就在这个位置组成一个链表*/
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

void Hash::writeOutTable()//写入的时候,应该顺便排个序;
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
		for (i = P; i > 0 && tmp.count > outTable[i - 1].count; i--)// 这里我想得到递减序列
		{
			outTable[i]= outTable[i - 1];
		}
		outTable[i] = tmp;
	}
}
void Hash::limitLength(int &length)
{

}