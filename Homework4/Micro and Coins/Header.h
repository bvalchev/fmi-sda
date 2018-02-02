#pragma once
#include<iostream>
using namespace std;
template <class T>
struct elem_link {
	T inf;
	elem_link<T> *link;
};template <class T>
class LList
{
private:
	elem_link<T> *start;
	elem_link<T> *end;
	elem_link<T> *current;
	void DeleteList();
	void CopyList(LList<T> const &);
public:
	LList();
	LList(LList<T> const &);
	LList& operator= (LList<T> const &);
	~LList();
	void IterStart(elem_link<T> *p = NULL);
	elem_link<T>* Iter();
	void ToEnd(T const &);
	void InsertAfter(elem_link<T>*, T const &);
	void InsertBefore(elem_link<T>*, T const &);
	bool DeleteAfter(elem_link<T>*, T &);
	bool DeleteBefore(elem_link<T>*, T &);
	void DeleteElem(elem_link<T>*, T &);
	void print();
	int length();
	void concat(LList<T> const& list);
	bool empty();
	bool member(T a);
};
///
/// Creates an empty list
///
template <class T>
LList<T>::LList()
{
	start = NULL;
	end = NULL;
}
///
/// Destroys a list
///
template <class T>
LList<T>::~LList()
{
	DeleteList();
}
///
/// Copy constructor
///
template <class T>
LList<T>::LList(LList<T> const & list)
{
	CopyList(list);
}
///
/// Copies the contents of one list to another
///
template <class T>
LList<T>& LList<T>::operator=(LList<T> const & list)
{
	if (this != &list)
	{
		DeleteList();
		CopyList(list);
	}
	return *this;
}
///
/// Removes all elements of a list
///
template <class T>
void LList<T>::DeleteList()
{
	elem_link<T> *p;
	while (start) {
		p = start;
		start = start->link;
		delete p;
	}
	end = NULL;
}
///
/// Copies all elements of a list
///
template <class T>
void LList<T>::CopyList(LList<T> const & list)
{
	start = end = NULL;
	if (list.start) {
		elem_link<T> *p = list.start;
		while (p) {
			ToEnd(p->inf);
			p = p->link;
		}
	}
}
template <class T>
void LList<T>::IterStart(elem_link<T> *p)
{
	if (p) current = p;
	else current = start;
}
template <class T>
elem_link<T>* LList<T>::Iter()
{
	elem_link<T> *p = current;
	if (current) current = current->link;
	return p;
}
template <class T>
void LList<T>::ToEnd(T const & x)
{
	current = end;
	end = new elem_link<T>;
	end->inf = x;
	end->link = NULL;
	if (current) current->link = end;
	else start = end;
}
template <class T>
void LList<T>::InsertAfter(elem_link<T> *p, T const & x)
{
	elem_link<T> *q = new elem_link<T>;
	q->inf = x;
	q->link = p->link;

	if (p == end) end = q;

	p->link = q;
}
template <class T>
void LList<T>::InsertBefore(elem_link<T> *p, T const & x)
{
	elem_link<T> *q = new elem_link<T>;
	*q = *p;

	if (p == end) end = q;
	p->inf = x;
	p->link = q;
}
template <class T>
bool LList<T>::DeleteAfter(elem_link<T> *p, T & x)
{
	if (p->link) {
		elem_link<T> *q = p->link;
		x = q->inf;
		p->link = q->link;

		if (q == end) end = p;
		delete q;
		return 1;
	}

	return 0;
}
template <class T>
void LList<T>::DeleteElem(elem_link<T> *p, T & x)
{
	if (p == start) {
		x = p->inf;
		if (start == end) {
			start = end = NULL;
		}
		else start = start->link;
		delete p;
	}
	else {
		elem_link<T> *q = start;
		while (q->link != p) q = q->link;
		DeleteAfter(q, x);
	}
}
template <class T>
bool LList<T>::DeleteBefore(elem_link<T> *p, T & x)
{
	if (p != start) {
		elem_link<T> *q = start;
		while (q->link != p) q = q->link;
		DeleteElem(q, x);
		return 1;
	}
	return 0;
}
template <class T>
void LList<T>::print()
{
	elem_link<T>* p = start;
	while (p) {
		cout << p->inf << " ";
		p = p->link;
	}
	cout << endl;
}
template <class T>
int LList<T>::length()
{
	int n = 0;
	IterStart();
	elem_link<T> *p = Iter();
	while (p) {
		n++;
		p = Iter();
	}
	return n;
}
template <class T>
void LList<T>::concat(LList<T> const & list)
{
	elem_link<T> *p = list.start;
	while (p) {
		ToEnd(p->inf);
		p = p->link;
	}
}
template <class T>
bool LList<T>::empty()
{
	return start == NULL;
}

template<class T>
bool LList<T>::member(T a)
{
	elem_link<T> *p = start;
	while (p)
	{
		if (p->inf == a)
			return true;
		p = p->link;
	}
	return false;
}

typedef LList<int> IntList;
typedef LList<IntList> IntGraph;elem_link<int>* Point(int a, IntGraph &g)
{
	g.IterStart();
	elem_link<IntList>*p;
	elem_link<int> *q;
	do
	{
		p = g.Iter();
		p->inf.IterStart();
		q = p->inf.Iter();
	} while (q->inf != a);
	return q;
}
void AddTop(int a, IntGraph &g)
{
	IntList l;
	l.ToEnd(a);
	g.ToEnd(l);
}
void AddRib(int a, int b, IntGraph &g)
{
	elem_link<int> * q = Point(a, g), *p;
	while (q->link) q = q->link;
	p = new elem_link<int>;
	p->inf = b;
	p->link = NULL;
	q->link = p;
}
void create_graph(IntGraph &g)
{
	char c;
	do
	{
		cout << "top_of_graph: ";
		int x; cin >> x;
		AddTop(x, g);
		cout << "Top y/n? "; cin >> c;
	} while (c == 'y');
	cout << "Ribs:\n";
	do
	{
		cout << "start top: ";
		int x; cin >> x;
		cout << "end top: ";
		int y; cin >> y;
		AddRib(x, y, g);
		cout << "next: y/n? "; cin >> c;
	} while (c == 'y');
}
void LList<IntList>::print()
{
	IterStart();
	elem_link<IntList> *p = Iter();
	while (p)
	{
		p->inf.print();
		p = p->link;
	}
	cout << endl;
}
