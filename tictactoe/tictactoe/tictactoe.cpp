#include <iostream>
#include <vector>
#include "ExtensionMethods.h"
using namespace std;

const int x = 3;
const int y = 3;
char board[x][y];

string playerX = "";
string playerO = "";
string column = "";
string row = "";
int c = 0;
int r = 0;
int gameStatus = 3;

void printBoard(){
    cout << "\n\n\t" << board[0][2] << '|' << board[1][2] << '|' << board[2][2] <<  endl;
    cout << "\t" << "-----" << endl;
    cout << "\t" << board[0][1] << '|' << board[1][1] << '|' << board[2][1] <<  endl;
    cout << "\t" << "-----" << endl;
    cout << "\t" << board[0][0] << '|' << board[1][0] << '|' << board[2][0] << "\n\n";
}

int checkBoard(){
	// 0 = tie
    // 1 = player one wins
    // 2 = player two wins
    // 3 = Game continues
	for(int i = 0; i < 3; i++){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			if(board[i][0] == 'X') return 1;
			if(board[i][0] == 'O') return 2;
		}
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			if(board[0][i] == 'X') return 1;
			if(board[0][i] == 'O') return 2;
		}
	}
	if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])){
		if(board[1][1] == 'X') return 1;
		if(board[1][1] == 'O') return 2;
	}
	bool tieTest = true;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(board[i][j] == ' ') tieTest = false;
	if(tieTest) return 0;
	return 3;
}

bool validateInput(const string & myFirstString, const string & mySecondString, int rangeStart, int rangeEnd){
	if(!ExtensionMethods::IsIntOrNot(myFirstString) || !ExtensionMethods::IsIntOrNot(mySecondString)){
		cout << "Input must be a number!\n";
		return false;
	}
	int myFirstInt = stoi(myFirstString);
	int mySecondInt = stoi(mySecondString);
	if(!ExtensionMethods::IsInRange(myFirstInt, rangeStart, rangeEnd) || !ExtensionMethods::IsInRange(mySecondInt, rangeStart, rangeEnd)){
		cout << "Input needs to be either 0, 1 or 2!\n";
		return false;
	}
	if(board[myFirstInt][mySecondInt] != ' '){
		cout << "You can not place on an already taken position\n";
		return false;
	}
	return true;
}

void playerXMove(){
	bool validInput = false;
	while(!validInput)	{
		cout << "Input column: ";
		cin >> column;
		cout << "\nInput row: ";
		cin >> row;
		if(!validateInput(column, row, 0, 2)) continue;
		validInput = true;
		c = stoi(column);
		r = stoi(row);
	}
	board[c][r] = 'X';
}

void playerOMove(){
	bool validInput = false;
	while(!validInput){
		cout << "Input column: ";
		cin >> column;
		cout << "\nInput row: ";
		cin >> row;
		if(!validateInput(column, row, 0, 2)) continue;
		validInput = true;
		c = stoi(column);
		r = stoi(row);
	}
	board[c][r] = 'O';
}
bool continuePlaying(){
	if(checkBoard() == 2){
		cout << "Player O won the game.\nCongratulations!!!\n\n";
		return false;
	}
	if(checkBoard() == 1){
		cout << "Player X won the game.\nCongratulations!!!\n\n";
		return false;
	}
	if(checkBoard() == 0){
		cout << "Shoot!\nIt's a tie.\n\n";
		return false;
	}
return true;
}

int main()
{
	memset(board, ' ', x * y);
    cout << "Welcome to tic tac toe!\nPlease input a name for player X: ";
    cin >> playerX;
    cout << "\nPlease input a name for player O: ";
    cin >> playerO;
    cout << "\nLet the game begin :)\n";
	printBoard();
	cout << "Please select a column and row to place your marker (e.g Column: 2, Row: 2 for upper right corner)\n";
	while(true)	{
		cout << playerX << "'s turn.\n";
		playerXMove();
		printBoard();
		if(!continuePlaying()) break;
		cout << playerO << "'s turn.\n";
		playerOMove();
		printBoard();
		if(!continuePlaying()) break;
	}
	return 0;
}