#pragma once
#include "Player.h"
#include "AI.h"
#include <iostream>
using namespace std;

Player vsPlayer;
AI ai;
bool aiTurn = false;

class VsAiGame{
public:
	void playGame() const
	{
		cout << "Please input one player name: " << endl;
		string input;
		cin >> input;
		vsPlayer.setName(input);
		while(true){
			string whosTurn = aiTurn ? "A.I" : vsPlayer.getName();
			if(sticks < 1){
				cout << whosTurn << " drew the last sticks from the stack and wins!" << endl;
				if(whosTurn == "A.I") ai.score++;
				else vsPlayer.setScore(1);
				cout << "Current scores: " << vsPlayer.getName() << ": " << vsPlayer.getScore() << ".";
				cout << "\t\tA.I: " << ai.score << ".\n";
				cout << "Do you want to play again? ( [1] yes, [2] no )" << endl;
				cin >> input;
				if(StringToIntChecker::IsIntOrNot(input)){
					const int userChoice = stoi(input);
					switch(userChoice){
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
			for(int i = 0; i < sticks; i++){
				cout << sticksString;
				if(i == sticks - 1) cout << endl;
			}
			cout << whosTurn << "'s turn.\n\n";
			if(aiTurn){
				const int aiTake = ai.takeSticks();
				cout << "AI took " << aiTake << " sticks from the stack of " << sticks << endl;
				sticks -= aiTake;
				if(sticks < 1) continue;
				cout << "There now remains " << sticks << " in the stack!\n";
				aiTurn = !aiTurn;
				continue;
			}
			cout << "How many sticks would you like to take? (1-3)" << endl;
			cin >> input;
			if(StringToIntChecker::IsIntOrNot(input)){
				const int numberToRemove = stoi(input);
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
			}
			cout << "You must input a value between 1 and 3!" << endl;
		}
	}
};