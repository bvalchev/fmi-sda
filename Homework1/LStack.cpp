// ConsoleApplication7.cpp : Defines the entry point for the console application.
//


#include<iostream>
#include<vector>
using namespace std;
template<typename T>
struct node {
	T info;
	node* next;
};
template<typename T>
class LStack {
private:
	node<T>* top;
	void Copy(node<T>* toCopy) {
		if (toCopy == nullptr) {
			return;
		}
		Copy(toCopy->next);
		push(toCopy->info);
	}
	void copyStack(const LStack<T>& other) {
		top = nullptr;
		Copy(other.top);

	}
	void erase() {
		while (!empty()) {
			cout << pop() << " deleted" << endl;
		}
	}
public:
	LStack() {
		top = nullptr;
	}
	LStack(const LStack<T>& other) {
		copyStack(other);
	}
	LStack operator =(const LStack<T>& other) {
		if (this != &other) {
			copyStack(other);
		}
		return *this;
	}
	~LStack() {
		erase();
	}
	bool empty() {
		return (top == nullptr);
	}
	void push(T x) {
		node<T>* p = new node<T>;
		p->info = x;
		p->next = top;
		top = p;
	}
	T pop() {
		if (!empty())
		{
			node<T>* p = top;
			top = top->next;
			T value = p->info;
			delete p;
			return value;
		}
		else cerr << "Empty stack!" << endl;
		return 0;
	}
	T topData() {
		if (!empty()) {
			return top->info;
		}
		else {
			cerr << "Empty stack!" << endl;
			return 0;
		}
	}
	void print() {
		node<T>* p = top;
		while (p != nullptr) {
			cout << p->info << " ";
			p = p->next;
		}
		cout << endl;
	}
	T getMax() {
		if (empty()) {
			cerr << "Stack empty!" << endl;
			return 0;
		}
		T max;
		node<T>* p = top;
		max = top->info;
		while (p != nullptr) {
			if (max < p->info) {
				max = p->info;
			}
			p = p->next;
		}
		return max;
	}
};

int main()
{
	/*LStack<int> a;
	a.push(3);
	a.push(4);
	a.push(5);
	a.print();
	cout << a.topData() << endl;
	cout << a.pop() << endl;
	a.print();
	cout << endl;
	LStack<int> b = a;
	b.print();
	cout << a.getMax()<<endl;
	cout << endl;
	//********************************************************
	*/
	/*
	// Maximum Elelment
	LStack<int> c;
	vector<int> outputs;
	int n, queryNum, max;
	cin >> n;
	for (int i = 0; i < n; i++) {
	cin >> queryNum;
	switch (queryNum) {
	case 1: {
	int x;
	cin >> x;
	c.push(x);
	break;
	}
	case 2: {
	c.pop();
	break;
	}
	case 3: {
	while (!c.empty()) {
	outputs.push_back(c.getMax());
	}
	break;
	}
	}
	}
	for (int i = 0; i < outputs.size(); i++) {
	cout << outputs[i] << " ";
	}
	*/


	//****************************************************************
	// GAME OF STACKS
	int g;
	cin >> g;
	for (int a0 = 0; a0 < g; a0++) {
		int n;
		int m;
		int x;
		cin >> n >> m >> x;
		vector<int> a(n);
		for (int a_i = 0; a_i < n; a_i++) {
			cin >> a[a_i];
		}
		vector<int> b(m);
		for (int b_i = 0; b_i < m; b_i++) {
			cin >> b[b_i];
		}
		int counter1 = 0, counter2 = 0;
		LStack<int> first, second;
		while (a.size() > counter1){
		first.push(a[a.size()-counter1-1]);
		counter1++;
		}
		while (b.size() > counter2) {
			second.push(b[b.size()-counter2-1]);
			counter2++;
		}
		int sum = 0, movesCounter = 0;
		while (sum<x) {
			if (!first.empty() && !second.empty()) {
				if (first.topData() > second.topData()) {
					sum += second.pop();
				}
				else {
					sum += first.pop();
				}
				movesCounter++;
			}
			else if (!first.empty() && second.empty()) {
				sum += first.pop();
				movesCounter++;
			}
			else if (first.empty() && !second.empty()) {
				sum += second.pop();
				movesCounter++;
			}
			else {
				cout << movesCounter << endl;
			}
		}
		cout << movesCounter-1 << endl;
	}
		

	cout << endl;
	system("pause");
	return 0;
}
