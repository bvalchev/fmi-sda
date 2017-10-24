
/**
* Homework 1 Part 1 SDA
* Author: Boyan Valchev 62051
*/
#include <iostream>
#include <assert.h>
using namespace std;

long fib(int n) {
	if (n == 1 || n == 0)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

long fib_better(int n) {
	unsigned long long *array = new unsigned long long[n+1];
	array[0] = 1;
	array[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		array[i] = fib_better(i - 1) + fib_better(i - 2);
	}
	return array[n];
	delete[] array;
}
int main()
{
	int x;
	cin >> x;
	assert(x>0);
	cout << fib(x) <<" "<< fib_better(x)<<endl;
	system("pause");
    return 0;
}

