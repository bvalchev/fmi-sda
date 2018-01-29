#include<iostream>
#include "Header.h"
using namespace std;

void DeleteLast(IntList &L)
{
	L.IterStart();
	int x;
	elem_link<int> *p = L.Iter();
	while (p->link) p = L.Iter();
	L.DeleteElem(p, x);
}
void RemoveRib(int a, int b, IntGraph &g)
{
	elem_link<int>*p = Point(a, g);
	while (p->link->inf != b)
		p = p->link;
	elem_link<int>* q = p->link;
	p->link = p->link->link;
	delete q;
}
bool way(int a, int b, IntGraph &g, IntList &l)
{
	l.ToEnd(a);
	if (a == b)
	{
		return true;
	}
	elem_link<int> * q = Point(a, g);
	q = q->link;
	while (q)
	{
		if (!l.member(q->inf) && way(q->inf, b, g, l))
			return true;
		q = q->link;
	}

	DeleteLast(l);
	return false;
}
bool checkIfVertexExists(int p, IntGraph &g)
{
	g.IterStart();
	elem_link<IntList> *a = g.Iter();
	while (a)
	{
		a->inf.IterStart();
		elem_link<int> *b = a->inf.Iter();
		if (b->inf == p)
			return true;
		a = a->link;
	}
	return false;
}
//we know that there is an unique path between any two houses
bool checkIf0(IntGraph &g, int a, int b)
{
	LList<int> l;
	if (!way(a, 1, g, l))
		return false;
	else
	{
		//l.print();
		l.IterStart();
		elem_link<int> *p = l.Iter();
		while (p)
		{
			if (p->inf == b) return true;
			p = p->link;
		}
	}
	return false;
}
bool checkIf1(IntGraph g, int a, int b)
{

	LList<int> l,m;
	way(a, 1, g, l);
	l.IterStart();
	elem_link<int> *q = l.Iter();
	if (q->link == NULL)
		return true;
	q = q->link;
	RemoveRib(a ,q->inf, g);
	RemoveRib(q->inf, a, g);
	//g.print();
	if (!way(a, b, g, m))
		return false;
	else
	{
		m.IterStart();
		elem_link<int> *p = m.Iter();
		while (p)
		{
			if (p->inf == 1)
				return false;
			p = p->link;
		}
	}
	return true;
}
int main()
{
	
	IntGraph g;
	int n;
	cin >> n;
	for (int k = 0; k < n-1; k++)
	{
		int x, y;
		cin >> x >> y;
		if (!checkIfVertexExists(x, g))
		{
			AddTop(x, g);
		}
		if (!checkIfVertexExists(y, g))
		{
			AddTop(y, g);
		}

		AddRib(x, y, g);
		AddRib(y, x, g);
	}
	int v;
	cin >> v;
	for (int i = 0; i < v; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
		{
			if (checkIf0(g, c, b))
				cout << "True" << endl;
			else cout << "False" << endl;
		}
		else
		{
			if (checkIf1(g, c, b))
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
	}
	system("pause");
	return 0;
}