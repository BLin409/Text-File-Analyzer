#ifndef RedBlackLeaf_H__
#define RedBlackLeaf_H__

#include <string>

class RedBlackLeaf
{
    public:
        RedBlackLeaf();
        RedBlackLeaf(std::string dataIn, RedBlackLeaf* leftIn, RedBlackLeaf* rightIn, RedBlackLeaf* parentIn, int colorIn);
        std::string getData();
        void setData(std::string dataIn);
		int getFreqCount();
		void setFreqCount(int freqCountIn);
        RedBlackLeaf* getLeftLeaf();
        void setLeftLeaf(RedBlackLeaf* leftIn);
        RedBlackLeaf* getRightLeaf();
        void setRightLeaf(RedBlackLeaf* rightIn);
		RedBlackLeaf* getParent();
        void setParent(RedBlackLeaf* parentIn);
		int getColor();
		void setColor(int colorIn);
		void increFreq();
//		~RedBlackLeaf();

    private:
		RedBlackLeaf* left;
		RedBlackLeaf* right;
		RedBlackLeaf* parent;
		int color;
		std::string data;
		int freqCount;
};

#endif
