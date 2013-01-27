#include "Forest.h"
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
	double avg = 0;
    struct timeval start, finish;
	
	if (argc != 2) {
		cerr << "ERROR: Check Your Input AGAIN!\n";
		return 0;
	}
	for (int i = 0; i < 50; i++) 
	{
		Forest* forest = new Forest();
		forest->openFile(argv[1]);

		int REPS = 5;
		gettimeofday(&start, NULL);
		forest->parseText();
		for(int j = 0; j < REPS; j++) 
		{
			forest->printFrequency();
			forest->uniqueWordCount();
			forest->totalWordCount();
			forest->totalCharCount();
		} 
		gettimeofday(&finish, NULL);
	
		double totalTime = (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 
				+ (double)(finish.tv_usec - start.tv_usec)) / (double)REPS;
		cout << totalTime << " microseconds" << endl;
		avg += totalTime;

		delete forest;
	}
	cout << avg << endl;
}
