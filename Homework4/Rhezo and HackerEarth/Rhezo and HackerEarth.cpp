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

	DeleteLast(l); // връщане назад
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
bool check(IntGraph &g, int *a, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			IntList l;
			if (!way(a[i], a[j], g, l))
				return false;
		}
	return true;
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
int main()
{
	struct pair
	{
		int a;
		int b;
	};
	IntGraph g;
	
	int m, n, q, x, y, size = 0, v, sizeOfPairsArray = 0;
	cin >> m;
	cin >> n;
	int a[100];
	pair pairs[100];
	for (int k = 0; k < n; k++)
	{
		cin >> x >> y;
		pairs[sizeOfPairsArray].a = x;
		pairs[sizeOfPairsArray].b = y;
		sizeOfPairsArray++;
		if (!checkIfVertexExists(x, g))
		{
			AddTop(x, g);
			a[size] = x;
			size++;
		}
		if (!checkIfVertexExists(y, g))
		{
			AddTop(y, g);
			a[size] = x;
			size++;
		}

		AddRib(x, y, g);
		AddRib(y, x, g);
	}
	cin >> q;
	for (int c = 0; c < q; c++)
	{
		cin >> v;
		v--;
		RemoveRib(pairs[v].a, pairs[v].b, g);
		RemoveRib(pairs[v].b, pairs[v].a, g);
		g.print();
		if (check(g, a, size))
			cout << "Happy" << endl;
		else cout << "Unhappy" << endl;
		AddRib(pairs[v].a, pairs[v].b, g);
		AddRib(pairs[v].b, pairs[v].a, g);
	}
	system("pause");
	return 0;
}