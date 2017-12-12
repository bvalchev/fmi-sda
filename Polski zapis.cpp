// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int Operate(int a, int b, char c) {
	switch (c) {
	case '+': 
	    return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a*b;
		break;
	case '/':
		return a / b;
		break;
	}
}

int main()
{
	
	string expression;
	int n;

	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++)
	{
		stack<int> numbers;
		stack<char> operations;
		getline(cin, expression);
		int counter = expression.size() - 1;
		while (counter>=0)
		{
			if (expression[counter] == ' ')
				counter--;
			else {
				if (expression[counter] == '+' || expression[counter] == '-' || expression[counter] == '*' || expression[counter] == '/')
				{
					operations.push(expression[counter]);
				}
				else {
					/*int length = 0;
					int temp = counter;
					while (expression[temp] != ' ')
					{
						length++;
						temp++;
					}
					char start = expression[counter];*/
					numbers.push((int)(expression[counter]-'0'));
				}
				counter--;
			}
		}
		while (numbers.size()>1) {
			int first = numbers.top();
			numbers.pop();
			int second = numbers.top();
			numbers.pop();
			char operation = operations.top();
			operations.pop();
			numbers.push(Operate(first, second, operation));
		}
		cout << numbers.top() << endl;
   }

	
	system("pause");
    return 0;
}
