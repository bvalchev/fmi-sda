//Queue with 2 stacks
#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
template<typename T>
class SpecialQueue {
private:
	stack<T> toPush;
	stack<T> toPop;
public:

	void enqueue(T x) {
		//toPush.push(x);
		while (!toPop.empty()) {
			toPush.push(toPop.top());
			toPop.pop();
		}
		toPop.push(x);
		while (!toPush.empty()) {
			toPop.push(toPush.top());
			toPush.pop();
		}
	}
	void dequeue() {
		toPop.pop();
		/*while (!toPush.empty()) {
			toPop.push(toPush.top());
			toPush.pop();
		}
		T t = toPop.top();
		toPop.pop();
		while (!toPop.empty()) {
			toPush.push(toPop.top());
			toPop.pop();
		}*/
	}
	T printTop() {
		return toPop.top();
	}
};


int main()
{
	SpecialQueue<int> a;
	vector<int> toPrint;
	int counter = -1;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		switch (x)
		{
		case 1: {
			int p;
			cin >> p;
			a.enqueue(p);
			break;
		}
		case 2: {
			a.dequeue();
			break;
		}
		case 3: {
			toPrint.push_back(a.printTop());
			break;
		}
		default:
			break;
		}
	}
	for (int l = 0; l < toPrint.size(); l++) {
		cout << toPrint[l] << endl;
	}
	system("pause");
	return 0;
}
