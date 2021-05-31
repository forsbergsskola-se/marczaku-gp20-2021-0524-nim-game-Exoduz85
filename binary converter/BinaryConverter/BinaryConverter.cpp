#include <iostream>
using namespace std;

long long numberToConvert = 0;
long long response = 0;
int numberOfBits = 64;

string convertToBinaryString(long long n){
	string asBinary;

	for(int i = 0; i < numberOfBits; i++)
	{
		if(n % 2 == 0) asBinary.append("0");
		else asBinary.append("1");
		n = n / 2;
	}
	string reversed = string(asBinary.rbegin(), asBinary.rend());
	reversed.insert(0, "0b");
	return reversed;
}

string convertWithBinaryOperator(long long n)
{
	string asBinary;

	for(int i = numberOfBits - 1; i >= 0; i--){
		long long k = n >> i;
		if(k & 1)
			asBinary.append("1");
		else
			asBinary.append("0");
	}
	asBinary.insert(0, "0b");
	return asBinary;
}

int main()
{
	while (true)
	{
		cout << "Please input a positive number you want to see as binary: ";
		cin >> numberToConvert;
		cout << endl << "You input: " << numberToConvert << ".\n";
		string binaryString = convertToBinaryString(numberToConvert);
		string binaryStringWithOperator = convertWithBinaryOperator(numberToConvert);
		cout << "Is: " << binaryString << " as binary representation with n % 2." << endl;
		cout << "Is: " << binaryStringWithOperator << " as binary representation with >> operator" << endl;
		cout << "Want to do another number? [1] yes, [2] no\n";
		cin >> response;
		if(response == 2) break;
	}
	return 0;
}