#include <iostream>
#include "Player.h"
#include "AI.h"
#include "StringToIntChecker.h"
using namespace std;

Player playerOne;
Player playerTwo;
AI ai;
int sticks = 24;
string sticksString = "|";
int pickedSticks = 0;
char userChoice;
bool validInput = false;
bool twoPlayers = false;
bool playerTwoTurn = false;
bool aiTurn = false;

int main(){
	cout << "Hi and welcome to the game of Nim!\nDo you want to play against an AI (1) or another player (2)?\n";
	while(!validInput){
		cin >> userChoice;
		switch(userChoice){
			case '1':
				validInput = true;
				cout << "Great choice, remember though, the AI is a bit stupid :P" << endl;
				break;
			case '2':
				cout << "Excellent choice, playing together is fun :)" << endl;
				validInput = true;
				twoPlayers = true;
				break;
			default:
				cout << "Not a valid input, please select 1 or 2" << endl;
				break;
		}
	}
	cout << "Please input one player name: " << endl;
	string str = "";
	cin >> str;
	playerOne.setName(str);
	if(twoPlayers){
		cout << "Please input the second players name: " << endl;
		string str = "";
		cin >> str;
		playerTwo.setName(str);
	}
	switch(twoPlayers){
		case true:{
			// two player game
			while(true){
				for(int i = 0; i < sticks; i++){
					cout << sticksString;
					if(i == sticks - 1) cout << endl;
				};
				string whosTurn = playerTwoTurn ? playerTwo.getName() : playerOne.getName();
				cout << whosTurn + "'s turn.\n";
				cout << "How many sticks would you like to take? (1-3)" << endl;
				string input = "";
				cin >> input;

				if(StringToIntChecker::IsIntOrNot(input)){
					int numberToRemove = stoi(input);
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
									return 0;
							}
						}
						return 0;
					}
					cout << "There now remains " << sticks << " in the stack.\n";
					playerTwoTurn = !playerTwoTurn;
					continue;
				} else{
					cout << "You must input a value between 1 and 3!" << endl;
					continue;
				}
			}
			break;
		}
		case false:{
			// ai v player game
			while(true){
				string whosTurn = aiTurn ? "A.I" : playerOne.getName();
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
								return 0;
						}
					}
					return 0;
				}

				for(int i = 0; i < sticks; i++){
					cout << sticksString;
					if(i == sticks - 1) cout << endl;
				};

				cout << whosTurn + "'s turn.\n\n";

				if(aiTurn){
					int aiTake = ai.takeSticks();
					cout << "AI took " << aiTake << " sticks from the stack of " << sticks << endl;
					sticks -= aiTake;
					if(sticks < 1) continue;
					cout << "There now remains " << sticks << " in the stack!\n";
					aiTurn = !aiTurn;
					continue;
				}
				if(!aiTurn){
					cout << "How many sticks would you like to take? (1-3)" << endl;
					string input = "";
					cin >> input;
					if(StringToIntChecker::IsIntOrNot(input)){
						int numberToRemove = stoi(input);
						if(numberToRemove > 3 || numberToRemove < 1){
							cout << "You must input a value between 1 and 3!" << endl;
							continue;
						}
						cout << "You removed " << numberToRemove << " from the stack of " << sticks << ".\n";
						sticks -= numberToRemove;
						if(sticks < 1) continue;
						cout << "There now remains " << sticks << " in the stack.\n";
						aiTurn = !aiTurn;
						continue;
					} else{
						cout << "You must input a value between 1 and 3!" << endl;
						continue;
					}
				}
				break;
			}
		}
	}
	return 0;
}