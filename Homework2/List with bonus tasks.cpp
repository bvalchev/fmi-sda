#include<iostream>
using namespace std;
template<typename T>
struct node {
	T info;
	node* next;
};
template<typename T>
class List {
private:
	node<T>* start;
	node<T>* end;
	node<T>* current;
	void copy(const List<T>& other) {
		start = NULL;
		end = NULL;
		if (other.start != nullptr) {
			node<T>* p = other.start;
			while (p) {
				push_back(p->info);
				p = p->next;
			}
		}

	};
	void erase() {
		node<T>* p = start;
		while (p) {
			p = p->next;
			pop_front();
		}
	};
	void swap(node<T>* a, node<T>* b) {
		T temp= a->info;
		a->info = b->info;
		b->info = temp;
	}
public:
	List() {
		start = nullptr;
		end = nullptr;
	}
	List(const List<T>& other) {
		copy(other);
	}
	List operator = (const List<T>& other) {
		if (this != &other) {
			erase();
			copy(other);
		}
		return *this;
	}
	~List() {
		erase();
	}
	void IterStart(node<T>* p = NULL) {
		if (p) current = p;
		else
		{
			current = start;
		}
	}
	node<T>* Iter() {
		node<T>* p = current;
		current = current->next;
		return p;
	}
	void push_back(T x) {
		node<T>* p = new node<T>;
		p->info = x;
		p->next = nullptr;
		if (!start) {
			start = p;
		}
		else {
			end->next = p;
		}
		end = p;
	}
	void push_front(T x) {
		node<T>* p = new node<T>;
		p->info = x;
		p->next = start;
		if (!start) {
			end = p;
		}
		start = p;
	}
	T pop_front() {
		if (start) {
			node<T>* p = start;
			start = p->next;
			T x = p->info;
			delete p;
			return x;
		}
		else {
			cerr << "Empty list!" << endl;
		}
	}
	T pop_back() {
		if (start) {
			node<T>* p = end;
			node<T>* k = start;
			while (k->next != end) {
				k = k->next;
			}
			end = k;
			end->next = nullptr;
			T x = p->info;
			delete p;
			return x;
		}
		else {
			cerr << "Empty list!" << endl;
		}
	}
	void insertAfter(node<T>* element, T x) {
		node<T>* p = new node<T>;
		p->info = x;
		p->next = element->next;
		element->next = p;
	}
	void insertBefore(node<T>* element, T x) {
		T temp = element->info;
		element->info = x;
		insertAfter(element, temp);
	}
	T deleteAfter(node<T>* element) {
		node<T>* p = element->next;
		element->next = element->next->next;
		T x = p->info;
		delete p;
		return x;
	}
	T deleteBefore(node<T>* element) {
		node<T>* p = start;
		while (p->next->next != element) {
			p = p->next;
		}
		T x = p->next->info;
		deleteAfter(p);
		return x;
	}
	void delEl(node<T>* element) {
		node<T>* p = start;
		while (p->next != element) {
			p = p->next;
		}
		deleteAfter(p);
	}
	bool empty() {
		return start == NULL;
	}
	void Print() {
		node<T>* p = start;
		while (p) {
			cout << p->info << " ";
			p = p->next;
		}
		cout << endl;
	}
};

void DeleteDuplicates(List<int>& a) {
	a.IterStart();
	node<int>* p = a.Iter();
	int g = p->info;
	while (p->next) {
		if (g == p->next->info)
		{
			node<int>* temp = p->next;
			a.delEl(temp);
		}
		else {
			p = p->next;
			g = p->info;
			
		}
	}
}
List<int> mergeSortedLists(List<int> a, List<int> b) {
	a.IterStart();
	b.IterStart();
	node<int>* currA = a.Iter();
	node<int>* currB = b.Iter();
	List<int> result;
	while (!a.empty() || !b.empty()) {
		if (!a.empty() && !b.empty()) {
			if (currA->info < currB->info) {
				currA = currA->next;
				result.push_back(a.pop_front());
			}
			else {
				currB = currB->next;
				result.push_back(b.pop_front());
			}
		}
		else if (!a.empty() && b.empty()) {
			currA = currA->next;
			result.push_back(a.pop_front());
		}
		else {
			currB = currB->next;
			result.push_back(b.pop_front());
		}
	}
	//result.Print();
	return result;
}

int main()
{
	List<int> p;
	p.push_back(1);
	p.push_back(1);
	p.push_back(2);
	p.push_back(3);
	p.push_back(4);
	p.push_back(4);
	p.push_back(5);
	p.push_back(6);
	p.push_back(7);
	p.push_back(7);
	//p.push_back(8);
	p.Print();
	List<int> c;
	c.push_back(0);
	c.push_back(3);
	c.push_back(3);
	c.push_back(4);
	c.push_back(7);
	c.push_back(9);
	c.push_back(10);
	c.Print();
	List<int> something(c);
	something.Print();
	List<int> a, b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	b.push_back(1);
	b.push_back(3);
	a.Print();
	b.Print();
	mergeSortedLists(a,b).Print();
	//pesho.Print();
	//DeleteDuplicates(p);
	//p.Print();
	return 0;
}
