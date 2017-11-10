//Linked Queue implementation
#include <iostream>
using namespace std;
template<typename T>
struct node {
	node<T>* next;
	T data;
};
template<typename T>
class Queue {
private:
	node<T>* head;
	node<T>* tail;
	void copy(Queue<T> const& q) {
		for (node<T>* p = q.head; p != NULL; p = p->next)
			push(p->data);
	}
	void eraseQueue() {
		node<T>* p = head;
		while (p) {
			p = p->next;
			pop();
		}
	}
public:
	Queue() {
		head = nullptr;
		tail = nullptr;
	}
	Queue(Queue<T> const& other) {
		copy(other);
	}
	Queue& operator = (Queue<T> const& other) {
		if (this != &other) {
			eraseQueue();
			copy(other);
		}
		return *this;
	}
	~Queue() {
		eraseQueue();
	}
	bool isEmpty() {
		return (head==nullptr && tail==nullptr);
	}
	void push(T const& x) {
		node<T>* p = new node<T>;
		p->data = x;
		p->next = nullptr;
		if (isEmpty()) {
			head = tail = p;
		}
		else {
			tail->next = p;
			tail = p;
		}
	}
	int pop() {
		if (isEmpty()) {
			cerr << "The queue is empty" << endl;
			return 0;
		}
		node<T>* p = head;
		head = head->next;
		T x = p->data;
		delete p;
		return x;
	}
	void print() {
		node<T>* p = head;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};
int main() {
	Queue<int> a;
	a.push(3);
	a.push(4);
	a.push(5);
	a.print();
	Queue<int> b = a;
	b.print();
	Queue<int> c(a);
	c.print();
	a.pop();
	a.print();
	system("pause");
	return 0;
}
