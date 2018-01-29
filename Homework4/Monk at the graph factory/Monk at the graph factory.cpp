#include<iostream>
#include<fstream>
#include"Header.h"
using namespace std;
static int counter = 0;
static int sizeOfArray = 0;
bool isTree(int n, int* a, int size) {
	//sum/2 = n-1
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += a[i];
	}
	return sum / 2 == n - 1;
}
int findNumOfVertexes(int a, IntGraph &g)
{
	g.IterStart();
	elem_link<IntList> *p = g.Iter();
	while (p)
	{
		a++;
		p = p->link;
	}
	return a;
}
void findDegrees(int *a, IntGraph &g)
{
	g.IterStart();
	elem_link<IntList> *p = g.Iter();
	while (p)
	{
		p->inf.IterStart();
		elem_link<int> *q = p->inf.Iter();
		if (q->link)q = q->link;
		while (q)
		{
			a[sizeOfArray] = q->inf;
			sizeOfArray++;
			counter++;
			q = q->link;
		}
		p = p->link;
	}
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
	
	ifstream file;
	file.open("input.txt");
	if (!file)
		cerr << "File not found" << endl;
	else
	{
		int p, q;
		while (file) {
			file >> p;
			file >> q;
			if(!checkIfVertexExists(p,g))
				AddTop(p,g);
			if(!checkIfVertexExists(q,g))
				AddTop(q,g);
			AddRib(p,q,g);
		}
		g.print();
	}
	int *a;
	findDegrees(a,g);
	int numberOfVertexes=0;
	findNumOfVertexes(numberOfVertexes, g);
	cout << isTree(numberOfVertexes, a,sizeOfArray) << endl;
	system("pause");
	return 0;
}