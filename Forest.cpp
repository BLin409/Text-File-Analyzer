#include "Forest.h"
#include "RedBlackTree.h"
#include "RedBlackLeaf.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

Forest::Forest() 
{
    forest = new RedBlackTree();
	maxFreqCount = 1;
}

void Forest::openFile(char* fileName) {
	fin.open(fileName);
    if (!fin.is_open()) {        
		cerr << "ERROR: The input file does not exist!\n";
        exit(0);
    }
}

void Forest::parseText()
{
	fin.seekg(0, ios::end);
    streampos length = fin.tellg();
    fin.seekg(0, ios::beg);
    
    char *buffer = new char[length];
    fin.read(buffer, length);
    
    stringstream ss;
    ss.rdbuf()->pubsetbuf(buffer, length);
    while(!ss.eof())
    {
        string word;
        ss >> word;
        if(word != "")
			forest->insert(word);
    }

	sort();
	delete [] buffer;
    fin.close();
}

void Forest::sort() 
{
	maxFreqCount = forest->getMaxFreq();
	stringstream* ssWordList = new stringstream[maxFreqCount];
	forest->sort(ssWordList);	
	
	length = new int[maxFreqCount];
	bWordList = new char*[maxFreqCount];
	for (int i = 0; i < maxFreqCount; i++) 
	{
		ssWordList[i].seekg(0, ios::end);
		length[i] = ssWordList[i].tellg();
		ssWordList[i].seekg(0, ios::beg);

		bWordList[i] = new char[length[i]];
		ssWordList[i].read(bWordList[i], length[i]);
	}
	
	ssUniqueWords << "The number of unique words is: " << forest->getUniqueWordCount() << "\n";	
	ssTotalWords << "The number of words is: " << forest->getWordCount() << "\n";
	ssTotalChars << "The number of words is: " << forest->getWordCount() << "\n";
	
	delete [] ssWordList;
}

void Forest::printFrequency()
{
	fout.open("wordDetails.txt");
    if (!fout.is_open()) {        
		cerr << "ERROR: The output file is invalid!\n";
        exit(0);
    }
    for (int i = 0; i < maxFreqCount; i++) {
		fout.write(bWordList[i], length[i]);
	}
}

void Forest::uniqueWordCount() {
	fout << ssUniqueWords.rdbuf();
	ssUniqueWords.seekg(ios::beg);
}

void Forest::totalWordCount() {
	fout << ssTotalWords.rdbuf();
	ssTotalWords.seekg(ios::beg);
}

void Forest::totalCharCount() {
	fout << ssTotalChars.rdbuf();
	ssTotalChars.seekg(ios::beg);
	fout.close();
}

Forest::~Forest() 
{
	delete forest;
	
	for (int i = 0; i < maxFreqCount; i++) {
		delete [] bWordList[i];
	}
	delete [] bWordList;
	delete [] length;
}
