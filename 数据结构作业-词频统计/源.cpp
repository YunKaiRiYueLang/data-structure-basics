#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Hash.h"
#include "Globle.h"

using namespace std;

int main()
{
	string input, inputFileName, outputFileName;
	cout << "��������������������ļ���������·������չ������";
	cin >> inputFileName;
	cout << "������ϣ���������������ļ���������·������չ������";
	cin >> outputFileName;
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open(inputFileName);
	outputFile.open(outputFileName);
	string inputWord;
	Hash hashTable;
	clock_t start, end;
	double time;
	start = clock();
	while (inputFile >> inputWord)
	{
		//cout << inputWord << endl;
		//getchar();
		hashTable.hashWord(handleString(inputWord));
	}
	inputFile.close();
	hashTable.writeOutTable();
	end = clock();
#if 1
	hashTable.insertionSort();
#endif
	for (int i = 0; i < hashTable.outTable.size(); i++)
	{
		outputFile << setw(30) << setiosflags(ios::left) << hashTable.outTable[i].word << ' ' << hashTable.outTable[i].count << endl;
	}
	
	time = (double)(end - start);
	outputFile << "�������岿��ִ��ʱ�䣨���룩��" << time;// д��ͳ����ʱ
	outputFile.close();
	return 0;
}