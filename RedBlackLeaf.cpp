#include "RedBlackLeaf.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

RedBlackLeaf::RedBlackLeaf() {
    data = "";
	freqCount = 0;
    left = 0;
    right = 0;
	parent = 0;
	color = 0;	//Black
}

RedBlackLeaf::RedBlackLeaf(string dataIn, RedBlackLeaf* leftIn, RedBlackLeaf* rightIn, RedBlackLeaf* parentIn, int colorIn) {
    data = dataIn;
	freqCount = 1;
    left = leftIn;
    right = rightIn;
	parent = parentIn;
	color = colorIn;
}

string RedBlackLeaf::getData() {
    return data;
}

void RedBlackLeaf::setData(string dataIn) {
    data = dataIn;
}

int RedBlackLeaf::getFreqCount() {
	return freqCount;
}

void RedBlackLeaf::setFreqCount(int freqCountIn) {
	freqCount = freqCountIn;
}

RedBlackLeaf* RedBlackLeaf::getLeftLeaf() {
    return left;
}

void RedBlackLeaf::setLeftLeaf(RedBlackLeaf* leftIn) {
    left = leftIn;
}

RedBlackLeaf* RedBlackLeaf::getRightLeaf() {
    return right;
}

void RedBlackLeaf::setRightLeaf(RedBlackLeaf* rightIn) {
    right = rightIn;
}

RedBlackLeaf* RedBlackLeaf::getParent() {
    return parent;
}

void RedBlackLeaf::setParent(RedBlackLeaf* parentIn) {
    parent = parentIn;
}

int RedBlackLeaf::getColor() {
    return color;
}

void RedBlackLeaf::setColor(int colorIn) {
    color = colorIn;
}

void RedBlackLeaf::increFreq() {
	freqCount++;
}

//RedBlackLeaf::~RedBlackLeaf(){}
