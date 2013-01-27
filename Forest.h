#ifndef FOREST_H__
#define FOREST_H__

#include "RedBlackTree.h"
#include <fstream>
#include <sstream>

class Forest
{
    public:
        Forest();
		void openFile(char* fileName);
    	void parseText();
		void sort();
    	void printFrequency();
		void uniqueWordCount();
		void totalWordCount();
		void totalCharCount();
        ~Forest();

    private:
        RedBlackTree* forest;
		char** bWordList;
		int* length;
		std::stringstream ssUniqueWords;
		std::stringstream ssTotalWords;
		std::stringstream ssTotalChars;
		int maxFreqCount;
		std::ifstream fin;
        std::ofstream fout;
};

#endif
