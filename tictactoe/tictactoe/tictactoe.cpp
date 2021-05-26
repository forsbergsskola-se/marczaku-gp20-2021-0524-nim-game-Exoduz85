#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> tictactoe = {{'|', '|', '|'}, {'|', '|', '|'}, {'|', '|', '|'}};

int main()
{
    // print content of array
    for(auto row : tictactoe){
        for(auto col : row)
            cout << col << " ";
        cout << "\n";
    }
}