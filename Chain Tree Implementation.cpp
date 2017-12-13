#include<iostream>
using namespace std;
#define INITAL_CAPACITY 30
template<typename P>
void swap(P *p1, P *p2)
{
	P *temp = p1;
	p1 = p2;
	p2 = temp;
}
template<typename T>
class Tree
{
private:
	T *values;
	int *leftHeirs;
	int *rightHeirs;
	int RootIndex;
	int Size,Capacity;
	void resize(int capacity)
	{
		T *temp = new T[2 * capacity];
		int *tempLeft = new int[2 * capacity];
		int *tempRight = new int[2 * capacity];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = values[i];
			tempLeft[i] = leftHeirs[i];
			tempRight[i] = rightHeirs[i];
		}
		swap<int>(tempLeft, leftHeirs);
		swap<int>(tempRight, rightHeirs);
		swap<T>(temp, values);
		delete[] temp;
		delete[] tempLeft;
		delete[] tempRight;
		Capacity = 2 * capacity;
	}
	void CopyTree(Tree<T> const& other)
	{
		values = new T[other.Capacity];
		rightHeirs = new int[other.Capacity];
		leftHeirs = new int[other.Capacity];
		Size = other.Size;
		Capacity = other.Capacity;
		RootIndex = other.RootIndex;
		for (int i = 0; i < other.Size; i++)
		{
			values[i] = other.values[i];
			rightHeirs[i] = other.rightHeirs[i];
			leftHeirs[i] = other.leftHeirs[i];
		}
	}
	void DeleteTree()
	{
		delete[] values;
		delete[] rightHeirs;
		delete[] leftHeirs;
	}
	void pr(int Index)
	{
		if (leftHeirs[Index] != -1)
		{
			pr(leftHeirs[Index]);
		}
		cout << values[Index] << " ";
		if (rightHeirs[Index] != -1)
		{
			pr(rightHeirs[Index]);
		}
	}
public:
	Tree()
	{
		values = new T[INITAL_CAPACITY];
		leftHeirs = new int[INITAL_CAPACITY];
		rightHeirs = new int[INITAL_CAPACITY];
		Size = 0;
		Capacity = INITAL_CAPACITY;
		RootIndex = 0;
	}
	Tree(Tree<T> const& other)
	{
		CopyTree(other);
	}
	Tree<T>& operator = (Tree<T> const& other)
	{
		if (this != &other)
		{
			DeleteTree();
			CopyTree(other);
		}
		return *this;
	}
	~Tree()
	{
		DeleteTree();
	}
	bool empty()
	{
		return Size == 0;
	}
	T getRoot()
	{
		return values[RootIndex];
	}
    //Printing leftTree-root-rightTree
	void print()
	{
		pr(RootIndex);
	}
	//If a certain vertex does not have a child, the index in the corresponding array will be -1
	void Create()
	{
		T x;
		char c;
		int temp = Size;
		if(Size==0)
		{ 
		cout << "Root: ";
		cin >> x;
		RootIndex = 0;
		values[RootIndex] = x;
		}
		else
		{
			if (Size - 1 > Capacity)
				resize(Capacity);
			cout << "Vertex: ";
			cin >> x;
			values[Size] = x;
		}
		Size++;
		
		cout << "left Tree of: " << x << " y/n? ";
		cin >> c;
		if (c == 'y')
		{
			leftHeirs[Size - 1] = Size ;
			Create();
		}
		else if (c == 'n')
			leftHeirs[Size - 1] = -1;
		
		cout << "right Tree of: " << x << " y/n? ";
		cin >> c;
		if (c == 'y')
		{
			rightHeirs[temp] = Size;
			Create();
		}
		else if (c == 'n')
		{
			rightHeirs[temp] = -1;
		}
	}
	void printArrays()
	{
		for (int i = 0; i < Size; i++)
		{
			cout << values[i] << " ";
		}
		cout << endl;
		for (int k = 0; k < Size; k++)
		{
			cout << leftHeirs[k] << " ";
		}
		cout << endl;
		for (int p = 0; p < Size; p++)
		{
			cout << rightHeirs[p] << " ";
		}
		cout << endl;
	}
};
int main()
{
	Tree<int> a;
	a.Create();
	cout << a.empty() << " " << a.getRoot() << endl;
	a.printArrays();
	cout << endl;
	a.print();
    system("pause");
	return 0;
}
