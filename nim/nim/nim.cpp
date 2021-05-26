#include <iostream>
#include "Player.h"
#include "AI.h"
using namespace std;

Player player;
AI ai;
int sticks = 24;
string sticksString = "|";
int pickedSticks = 0;

int main()
{

    for (int i = 0; i < 10; i++)
    {
        cout << ai.makeMove() << endl;
        
    } 
    return 0;

    cout << "Hi and welcome to the game of Nim!\nPlease write your name.\n";
    string str = "";
    cin >> str;
    player.setName(str);
    cout << "Let the game begin " + player.getName() << endl;
    for (;;) {
        for (int i = 0; i < sticks; i++)
        {
            cout << sticksString;
            if (i == sticks - 1) cout << endl;
        };

        cout << "How many sticks would you like to take? (1-3)" << endl;
        string input = "";
        cin >> input;
        try
        {
            pickedSticks = stoi(input);
        }
        catch (const std::exception&)
        {
            cout << "You must input a value between 1 and 3!" << endl;
        }
        
        sticks -= pickedSticks;
        
        cout << "You took " << pickedSticks << " sticks from the stack!" << endl << "Now " << sticks << " sticks remains in the stack!" << endl;
    }
    return 0;
}