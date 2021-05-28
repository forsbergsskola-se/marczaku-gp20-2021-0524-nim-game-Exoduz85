#pragma once
#include <cstdlib>
using namespace std;

class AI{
public:
	int score = 0;
	int takeSticks() {
		int randomNumb = 0;
		for(int i = 0; i < rand() % 300; i++)
		{
			randomNumb = rand() % 3 + 1;
		}
		return randomNumb;
	}
};