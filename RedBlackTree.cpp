/**
 * Special Thanks to http://www.cs.auckland.ac.nz/~jmor159/PLDS210/niemann/s_rbt.txt
 */

#include "RedBlackTree.h"
#include "RedBlackLeaf.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

RedBlackTree::RedBlackTree() 
{
    root = 0;
	maxFreqCount = 1;
	uniqueWordCount = 0;
	wordCount = 0;
	charCount = 0;
}

void RedBlackTree::insert(string word) 
{
    RedBlackLeaf* newLeaf = new RedBlackLeaf(word, 0, 0, 0, 1);
    if (root == 0) {
        root = newLeaf;
        RedBlackTree::insert_fix(newLeaf);
		uniqueWordCount++;
    } else {
        RedBlackTree::insert_aux(newLeaf, root);
    }
}

void RedBlackTree::traverseInorder() {
    if (root != 0) {
        RedBlackTree::traverseInorder_aux(root);
    } else {
    	cout << "Tree is empty!" << endl;
    }
}

void RedBlackTree::sort(stringstream* ssWordList) {
	if (root != 0) {
		RedBlackTree::sort_aux(root, ssWordList);
	}
}

int RedBlackTree::getMaxFreq() {
	return maxFreqCount;
}

int RedBlackTree::getUniqueWordCount() {
	return uniqueWordCount;
}

int RedBlackTree::getWordCount() {
	return wordCount;
}

int RedBlackTree::getCharCount() {
	return charCount;
}

RedBlackTree::~RedBlackTree() 
{
    stack<RedBlackLeaf*> s;
    RedBlackLeaf* current = root;

    while (current != 0) 
	{
        if (current->getLeftLeaf() != 0) {
            s.push(current);
            current = current->getLeftLeaf();
        } else if (current->getRightLeaf() != 0) {
            s.push(current);
            current = current->getRightLeaf();
        } else {
            delete current;
            if (!s.empty()) {
                RedBlackLeaf* temp = s.top();
                if (temp->getLeftLeaf() == current) {
                    temp->setLeftLeaf(0);
                } else {
                    temp->setRightLeaf(0);
                }
                current = s.top();
                s.pop();
            } else {
                current = 0;
            }
        }
    }
}

void RedBlackTree::insert_aux(RedBlackLeaf* newLeaf, RedBlackLeaf* subTreeRoot) 
{
	int result = (subTreeRoot->getData()).compare(newLeaf->getData());
    if (result > 0) {
        if (subTreeRoot->getLeftLeaf() == 0) {
			newLeaf->setParent(subTreeRoot);
            subTreeRoot->setLeftLeaf(newLeaf);
			insert_fix(newLeaf);
			RedBlackTree::uniqueWordCount++;
        } else {
            insert_aux(newLeaf, subTreeRoot->getLeftLeaf());
        }
    } else if (result < 0) {
        if (subTreeRoot->getRightLeaf() == 0) {
			newLeaf->setParent(subTreeRoot);
            subTreeRoot->setRightLeaf(newLeaf);
			RedBlackTree::insert_fix(newLeaf);
			uniqueWordCount++;
        } else {
            insert_aux(newLeaf, subTreeRoot->getRightLeaf());
        }
    } else {
        subTreeRoot->increFreq();
		if (subTreeRoot->getFreqCount() > maxFreqCount) {
			maxFreqCount = subTreeRoot->getFreqCount();
		}
        delete newLeaf;
    }
}

void RedBlackTree::insert_fix(RedBlackLeaf* newLeaf)
{
	while (newLeaf != root && ((newLeaf->getParent())->getColor() == 1))
	{
		RedBlackLeaf* parent = newLeaf->getParent();
		RedBlackLeaf* uncle1 = (parent->getParent())->getLeftLeaf();
		RedBlackLeaf* uncle2 = (parent->getParent())->getRightLeaf();
		if (parent == uncle1) {
			if (uncle2 != NULL && (uncle2->getColor() == 1)) {
				parent->setColor(0);
				uncle2->setColor(0);
				newLeaf = parent->getParent();
				newLeaf->setColor(1);
			} else {
				if (newLeaf == parent->getRightLeaf()) {
					newLeaf = parent;
					RedBlackTree::rotateLeft(newLeaf);
				}
				parent->setColor(0);
				(parent->getParent())->setColor(1);
				RedBlackTree::rotateRight(parent->getParent());
			}
		} else {
			if (uncle1 != NULL && (uncle1->getColor() == 1)) {
				parent->setColor(0);
				uncle1->setColor(0);
				newLeaf = parent->getParent();
				newLeaf->setColor(1);
			} else {
				if (newLeaf == parent->getLeftLeaf()) {
					newLeaf = parent;
					RedBlackTree::rotateRight(newLeaf);
				}
				parent->setColor(0);
				(parent->getParent())->setColor(1);
				RedBlackTree::rotateLeft(parent->getParent());
			}
		}
	}
	root->setColor(0);
}

void RedBlackTree::rotateLeft(RedBlackLeaf* newLeaf) 
{
	RedBlackLeaf* right = newLeaf->getRightLeaf();
	RedBlackLeaf* temp = right->getLeftLeaf();
	
	newLeaf->setRightLeaf(temp);
	if (temp != 0) {
		temp->setParent(newLeaf);
	}
	
	if (right != 0) {
		right->setParent(newLeaf->getParent());
	}
	
	temp = newLeaf->getParent();
	if (temp != 0) {
		if (newLeaf == temp->getLeftLeaf()) {
			temp->setLeftLeaf(right);
		} else {
			temp->setRightLeaf(right);
		}
	} else {
		root = right;
	}
	
	right->setLeftLeaf(newLeaf);
	if (newLeaf != 0) {
		newLeaf->setParent(right);
	}
}

void RedBlackTree::rotateRight(RedBlackLeaf* newLeaf)
{
	RedBlackLeaf* left = newLeaf->getLeftLeaf();
	RedBlackLeaf* temp = left->getRightLeaf();
	
	newLeaf->setLeftLeaf(temp);
	if (temp != 0) {
		temp->setParent(newLeaf);
	}
	
	if (left != 0) {
		left->setParent(newLeaf->getParent());
	}
	
	temp = newLeaf->getParent();
	if (temp != 0) {
		if (newLeaf == temp->getRightLeaf()) {
			temp->setRightLeaf(left);
		} else {
			temp->setLeftLeaf(left);
		}
	} else {
		root = left;
	}
	
	left->setRightLeaf(newLeaf);
	if (newLeaf != 0) {
		newLeaf->setParent(left);
	}
}

void RedBlackTree::traverseInorder_aux(RedBlackLeaf* subTreeRoot) 
{
    if (subTreeRoot->getLeftLeaf() != 0) {
        traverseInorder_aux(subTreeRoot->getLeftLeaf());
    }
    cout << subTreeRoot->getData() << " " << subTreeRoot->getFreqCount() << endl;
    if (subTreeRoot->getRightLeaf() != 0) {
        traverseInorder_aux(subTreeRoot->getRightLeaf());
    }
}

void RedBlackTree::sort_aux(RedBlackLeaf* subTreeRoot, stringstream* ssWordList) 
{
    if (subTreeRoot->getLeftLeaf() != 0) {
        sort_aux(subTreeRoot->getLeftLeaf(), ssWordList);
    }

	int freqCount = subTreeRoot->getFreqCount();
    ssWordList[freqCount - 1] << "The frequency of the word " << subTreeRoot->getData() << " is: " << freqCount << "\n";
	wordCount += freqCount;
	charCount += (freqCount * (subTreeRoot->getData()).size());
	
    if (subTreeRoot->getRightLeaf() != 0) {
        sort_aux(subTreeRoot->getRightLeaf(), ssWordList);
    }
}
