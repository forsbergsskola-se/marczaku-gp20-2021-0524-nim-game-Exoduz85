#pragma once
#include <cstdlib>
using namespace std;
class AI{
public:
	int makeMove() {
		int randomNumb = rand() % 3 + 1;
		return randomNumb;
	}
};

