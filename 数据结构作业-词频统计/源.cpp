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
	cout << "请输入运算命令的完整文件名（包含路径和扩展名）：";
	cin >> inputFileName;
	cout << "请输入希望保存运算结果的文件名（包含路径和扩展名）：";
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
	outputFile << "程序主体部分执行时间（毫秒）：" << time;// 写入统计用时
	outputFile.close();
	return 0;
}