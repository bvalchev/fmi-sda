#include "Header.h"
#include<iostream>
using namespace std;
int numCities(IntGraph &g)
{
	LList<int> a;
	int counter = 0;
	g.IterStart();
	elem_link<IntList>* p = g.Iter();
	while (p)
	{
		p->inf.IterStart();
		elem_link<int>* q = p->inf.Iter();
		while (q)
		{
			if (!a.member(q->inf))
			{
				a.ToEnd(q->inf);
				counter++;
			}
			q = q->link;
		}
		p = p->link;
	}
	return counter;
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
	int t, n, x, y;
	cin >> t;
	cin >> n;
	for (int i = 0; i < t; i++)
		for (int m = 0; m < n; m++)
		{
			cin >> x >> y;
			if (!checkIfVertexExists(x, g))
				AddTop(x, g);
			if (!checkIfVertexExists(y, g))
				AddTop(y, g);

			AddRib(x, y, g);
		}
	cout << numCities(g) << endl;
	system("pause");
	return 0;
}