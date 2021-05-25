#include <iostream>
#include "Player.h";
using namespace std;

Player player;


int main()
{
    cout << "Hi and welcome to the game of Nim!\nPlease write your name.\n";
    string str = "";
    cin >> str;
    player.setName(str);
    cout << "Let the game begin " + player.getName();
    
}