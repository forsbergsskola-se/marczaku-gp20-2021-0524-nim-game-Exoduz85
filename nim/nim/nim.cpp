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

int main()
{
    cout << "Hi and welcome to the game of Nim!\nDo you want to play against an AI (1) or another player (2)?\n";
    while (!validInput)
    {
        cin >> userChoice;
        switch (userChoice)
        {
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
    if (twoPlayers) {
        cout << "Please input the second players name: " << endl;
        string str = "";
        cin >> str;
        playerTwo.setName(str);
    }
    switch (twoPlayers)
    {
    case true:
        // two player game
        while (true)
        {
            // check if number of sticks left are blah blah left etc here.
            // return if game has ended!
            if (sticks < 1) return; // return the winner here too.
            for (int i = 0; i < sticks; i++)
            {
                cout << sticksString;
                if (i == sticks - 1) cout << endl;
            };
            string whosTurn = playerTwoTurn ? playerTwo.getName() : playerOne.getName();
            cout << whosTurn + "'s turn.\n";
            cout << "How many sticks would you like to take? (1-3)" << endl;
            string input = "";
            cin >> input;

            if (StringToIntChecker::IsIntOrNot(input)) {
                int numberRemoved = stoi(input);
                cout << "You removed " << numberRemoved << " from the stack of " << sticks << ".\n";
                sticks -= numberRemoved;
                cout << "There now remains " << sticks << " in the stack.\n";
                playerTwoTurn = !playerTwoTurn;
                continue;
            }
            else {
                cout << "You must input a value between 1 and 3!" << endl;
                continue;
            }
        }
        break;
    case false:
        // ai v player game
        break;
    default:
        // something went wrong, should not end up here!!!
        cout << "Please restart the game, you should not have ended up here..!" << endl;
        return 1;
    }
    return 0;
}