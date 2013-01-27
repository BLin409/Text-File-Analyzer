#ifndef RED_BLACK_TREE_H__
#define RED_BLACK_TREE_H__

#include "RedBlackLeaf.h"
#include <sstream>
#include <string>

class RedBlackTree
{
    public:
        RedBlackTree();
        void insert(std::string word);
        void traverseInorder();
		void sort(std::stringstream* ssWordList);
		int getMaxFreq();
		int getUniqueWordCount();
		int getWordCount();
		int getCharCount();
        ~RedBlackTree();

    private:
        RedBlackLeaf* root;
		int maxFreqCount;
		int uniqueWordCount;
		int wordCount;
		int charCount;
        void insert_aux(RedBlackLeaf* newRedBlackLeaf, RedBlackLeaf* subTreeRoot);
		void insert_fix(RedBlackLeaf* newLeaf);
		void rotateLeft(RedBlackLeaf* newLeaf);
		void rotateRight(RedBlackLeaf* newLeaf);	
		void traverseInorder_aux(RedBlackLeaf* subTreeRoot);
		void sort_aux(RedBlackLeaf* subTreeRoot, std::stringstream* ssWordList);
};

#endif
