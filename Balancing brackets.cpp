// Balancing brackets.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include"stackarray.h"
#include<string>
using namespace std;
char openparennthesis('('),
     opencurlybraces('{'),
     opensquarebracket('['),
	 closeparennthesis(')'),
	 closecurlybraces('}'),
	 closesquarebracket(']');
bool isbalance(string&);
int main()
{
    string input;
    getline(cin, input, '\n');
	if (isbalance(input))
		cout << "balanced\n";
	else
		cout << "unbalanced\n";
}
bool isbalance(string& input)
{
	stackarray<char> object;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == opencurlybraces || input[i] == openparennthesis || input[i] == opensquarebracket)
		{
			object.push(input[i]);
		}
		else if (input[i] == closeparennthesis)
		   {
			if (object.empty())
				return false;
			else if (object.top() == openparennthesis)
				object.pop();
			else
				return false;
		   }
		else if (input[i] == closecurlybraces)
		{
			if (object.empty())
				return false;
			else if (object.top() == opencurlybraces)
				object.pop();
			else
				return false;
		}
		else if (input[i] == closesquarebracket)
		{
			if (object.empty())
				return false;
			else if (object.top() == opensquarebracket)
				object.pop();
			else
				return false;
		}
		else
		{
			return false;
		}
	}
	return object.empty();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
