#include <iostream>

using namespace std;

long long numberToConvert = 0;
long long response = 0;
int numberOfBits = 64;

string convertToBinaryString(long long a){
	string asBinary = "";

	for(int i = 0; i < numberOfBits; i++)
	{
		if(a % 2 == 0) asBinary.append("0");
		else asBinary.append("1");
		a = a / 2;
	}
	cout << asBinary << endl;
	asBinary.append("b0");
	string reversed = string(asBinary.rbegin(), asBinary.rend());
	return reversed;
}

int main()
{
	while (true)
	{
		cout << "Please input a positive number you want to see as binary: ";
		cin >> numberToConvert;
		cout << endl << "You input: " << numberToConvert << ".\n";
		string binaryString = convertToBinaryString(numberToConvert);
		cout << "That is: " << binaryString << " as binary representation." << endl;
		cout << "Want to do another number? [1] yes, [2] no\n";
		cin >> response;
		if(response == 2) break;
	}
	return 0;
}