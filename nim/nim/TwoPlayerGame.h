#pragma once
#include <iostream>
#include "Player.h"
#include "StringToIntChecker.h"
using namespace std;

bool playerTwoTurn = false;
int sticks = 24;
string sticksString = "|";
Player playerOne;
Player playerTwo;

class TwoPlayerGame{
public:
	void playGame() const
	{
		cout << "Please input one player name: " << endl;
		string str;
		cin >> str;
		playerOne.setName(str);
		cout << "Please input the second players name: " << endl;
		cin >> str;
		playerTwo.setName(str);
		
		while(true){
			for(int i = 0; i < sticks; i++){
				cout << sticksString;
				if(i == sticks - 1) cout << endl;
			}
			string whosTurn = playerTwoTurn ? playerTwo.getName() : playerOne.getName();
			cout << whosTurn + "'s turn.\n";
			cout << "How many sticks would you like to take? (1-3)" << endl;
			string input;
			cin >> input;

			if(StringToIntChecker::IsIntOrNot(input)){
				const int numberToRemove = stoi(input);
				if(numberToRemove > 3 || numberToRemove < 1){
					cout << "You must input a value between 1 and 3!" << endl;
					continue;
				}
				cout << "You removed " << numberToRemove << " from the stack of " << sticks << ".\n";
				sticks -= numberToRemove;
				if(sticks < 1){
					cout << whosTurn + " drew the last sticks from the stack and wins!" << endl;
					cout << "Do you want to play again? ( [1] yes, [2] no )" << endl;
					string input = "";
					cin >> input;
					if(StringToIntChecker::IsIntOrNot(input)){
						int userchoice = stoi(input);
						switch(userchoice){
							case 1:
								cout << "Stack is now filled with 24 sticks again. \nLet the game begin!\n\n";
								sticks = 24;
								continue;
							case 2:
								break;
						}
					}
					break;
				}
				cout << "There now remains " << sticks << " in the stack.\n";
				playerTwoTurn = !playerTwoTurn;
			} else{
				cout << "You must input a value between 1 and 3!" << endl;
			}
		}
	}
};