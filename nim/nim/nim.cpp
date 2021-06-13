#include <iostream>
#include "TwoPlayerGame.h"
#include "VsAiGame.h"
using namespace std;

static TwoPlayerGame twoPlayerGame;
static VsAiGame vsAiGame;

char userChoice;
bool validInput = false;
bool twoPlayers = false;

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
	switch(twoPlayers){
		case true:
			twoPlayerGame.playGame();
			break;
		case false:
			vsAiGame.playGame();
			break;
	}
	return 0;
}