#include <iostream>
#include "Player.h";
using namespace std;

Player player;
int sticks = 24;
string sticksString = "|";
int picketSticks = 0;

int main()
{
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
            picketSticks = stoi(input);
        }
        catch (const std::exception&)
        {
            cout << "You must input a value between 1 and 3!" << endl;
        }
        
        sticks -= picketSticks;
        
        cout << "You took " << picketSticks << " sticks from the stack!" << endl << "Now " << sticks << " sticks remains in the stack!" << endl;
    }
    return 0;
}