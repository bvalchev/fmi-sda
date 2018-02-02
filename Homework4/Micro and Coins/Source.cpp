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
bool findMaxCoins(int a, IntGraph &g, IntList &l, int counter, int max, int numVertexes)
{
	l.ToEnd(a);
	counter++;
	if (counter>max)
	{
		max = counter;
	}
	if (max == numVertexes)
		return true;
	elem_link<int> * q = Point(a, g);
	q = q->link;
	while (q)
	{
		if (!l.member(q->inf) && findMaxCoins(q->inf, g, l, counter, max, numVertexes))
			return true;
		q = q->link;
	}

	DeleteLast(l);
	counter--;
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
int main()
{
	IntGraph g;
	IntList l;
	int counter = 0, max = 0;
	int t, n, m;
	cin >> t >> m >> n;
	for (int k = 0; k < t; k++)
	{
		for (int i = 0; i < n; i++)
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
		if (findMaxCoins(1, g, l, counter, max, m))
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	system("pause");
	return 0;
}