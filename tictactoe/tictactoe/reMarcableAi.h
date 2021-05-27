#pragma once
#include <iostream>
#include <vector>
using namespace std;

// I know, class names should start with a capital letter but i could not resist!
class reMarcableAi{
	int r1 = 0;
	int r2 = 0;
public:
	vector<int> getPosition(char(&myArray)[3][3]){
		// make AI check if any two spaces are occupied by double X's, if so place O in the right spot.
		vector<int> result;
		for(int i = 0; i < 3; i++){
			if((myArray[i][0] && myArray[i][1]) == 'X' && myArray[i][2] == ' '){
				result.assign({i, 2});
				return result;
			}
			if((myArray[i][2] == myArray[i][1]) == 'X' && myArray[i][0] == ' '){
				result.assign({i, 0});
				return result;
			}
			if((myArray[2][i] == myArray[1][i]) == 'X' && myArray[0][i] == ' '){
				result.assign({0, i});
				return result;
			}
			if((myArray[0][i] == myArray[1][i]) == 'X' && myArray[2][i] == ' '){
				result.assign({2, i});
				return result;
			}
			if((myArray[2][i] == myArray[0][i]) == 'X' && myArray[1][i] == ' '){
				result.assign({1, i});
				return result;
			}
			if((myArray[i][0] == myArray[i][2]) == 'X' && myArray[i][1] == ' '){
				result.assign({i, 1});
				return result;
			}
			if(i == 0 || i == 2){
				if(((myArray[2][0] == myArray[0][2]) == 'X' || (myArray[0][0] == myArray[2][2]) == 'X') && myArray[1][1] == ' '){
					result.assign({1, 1});
					return result;
				}
			}
		}
		while(myArray[r1][r2] != ' '){
			r1 = rand() % 3;
			r2 = rand() % 3;
		}
		result.assign({r1, r2});
		return result;
	}
};