#include<iostream>
using namespace std;


template<typename T>
class DList {
private:
	//template<typename T>
	struct node {
		T info;
		node* next;
		node* prev;
	};
	node* start;
	node* end;
	node* current;
	void copy(const DList& other) {
		start = NULL;
		end = NULL;
		if (!other.empty()) {
			node* p = other.start;
			while (p) {
				push_back(p->info);
				p = p->next;
			}
		}
	}
	void deleteList() {
		node* p = start;
		while (p) {
			p = p->next;
			pop_front();
		}
	}
public:
	DList() {
		start = NULL;
		end = NULL;
	}
	DList(const DList& other) {
		copy(other);
	}
	DList& operator = (const DList& other) {
		if (this != &other) {
			deleteList();
			copy(other);
		}
		return *this;
	}
	~DList() {
		deleteList();
	}
	bool empty() {
		return end == NULL;
	}
	void push_back(T x) {
		node* p = new node;
		p->info = x;
		p->next = NULL;
		p->prev = end;

		if (empty()) {
			start = p;
		}
		else {
			end->next = p;
		}

		end = p;
	}
	void push_front(T x) {
		node* p = new node;
		p->info = x;
		p->prev = NULL;
		p->next = start;
		if (empty()) {
			end = p;

		}
		else {
			start->prev = p;
		}
		start = p;
	}
	T pop_front() {
		if (!empty()) {
			node* p = start;
			start = start->next;
			T x = p->info;
			if (start != NULL)
				start->prev = NULL;
			delete p;
			return x;
		}
		else {
			cerr << "Empty list!" << endl;
			return 0;
		}
	}
	T pop_back() {
		if (!empty()) {
			node* p = end;
			end = end->prev;
			T x = p->info;
			if (end != NULL)
				end->next = NULL;
			delete p;
			return x;
		}
		else {
			cerr << "Empty list!" << endl;
			return 0;
		}
	}
	void insertAfter(node* element, T x) {
		node* p = new node;
		p->info = x;
		if (empty())
		{
			push_back(x);
		}
		else
		{
			p->next = element->next;
			p->prev = element;
			element->next = p;
		}
	}
	void insertBefore(node* element, T x) {
		node* p = new node;
		p->info = x;
		if (empty())
		{
			push_back(x);
		}
		else
		{
			p->next = element;
			p->prev = element->prev;
			element->prev = p;
		}
	}
	T& deleteBefore(node* element) {
		if (empty()) {
			cerr << "Empty list!" << endl;
			return T();
		}
		else
		{
			if (element->prev) {
				node* p = element->prev;
				p->prev->next = element;
				element->prev = p->prev;
				T x = p->info;
				delete p;
				return x;
			}
			return T();
		}
	}
	T& deleteAfter(node* element) {
		if (empty()) {
			cerr << "Empty list!" << endl;
			return T();
		}
		else
		{
			if (element->next) {
				node* p = element->next;
				element->next = p->next;
				p->next->prev = element;
				T x = p->info;
				delete p;
				return x;
			}
			return T();
		}
	}
	void IterStart(node* p = NULL) {
		if (p)
			current = p;
		else
			current = start;
	}
	node* Iter() {
		node* p = current;
		current = current->next;
		return p;
	}
	void print() {
		node* p = start;
		if (!empty()) {
			while (p) {
				cout << p->info << " ";
				p = p->next;
			}
		}
		cout << endl;
	}

	template <typename TT>
	friend void Reverse(DList<TT>& list);/* {
										 std::cout << "tet" << std::endl;
										 }*/
};

template <typename T>
void Reverse(DList<T>& list) {
	if (!list.empty()) {
		DList<T>::node* p = list.start;
		while (p) {
			DList<T>::node* curr = p;
			p = p->next;
			DList<T>::node* temp = curr->next;
			curr->next = curr->prev;
			curr->prev = temp;
		}
		DList<T>::node* temp1 = list.start;
		list.start = list.end;
		list.end = temp1;

	}
}


int main()
{
	DList<int> a;
	a.push_back(2);
	a.pop_back();
	a.print();
	a.push_back(4);
	a.push_back(3);
	a.push_front(1);
	a.push_back(9);
	a.push_front(10);
	a.print();
	Reverse(a);
	a.print();
	return 0;
}