#include<iostream>
using namespace std;
template<typename T>
struct node
{
	node<T> *left, *right;
	T inf;
};
template<typename T>
class BinOrdTree
{
private:
	node<T>* root;
	void DeleteTree(node<T>* &) const;
	void Copy(node<T>* &, node<T>* const&) const;
	void CopyTree(BinOrdTree<T> const&);
	void pr(const node<T> *) const;
	void Add(node<T> *&, T const &) const;
public:
	BinOrdTree();
	~BinOrdTree();
	BinOrdTree(BinOrdTree<T> const&);
	BinOrdTree& operator=(BinOrdTree<T> const&);
	T RootTree() const;
	node<T>* GetRoot() const;
	BinOrdTree<T> LeftTree() const;
	BinOrdTree<T> RightTree() const;
	bool empty()const;
	void print() const;
	void AddNode(T const & x);
	void DeleteNode(T const&);
	void Create3(T, BinOrdTree<T>, BinOrdTree<T>);
	void Create();
	void MinTree(T &, BinOrdTree<T> &) const;
};
template<typename T>
void BinOrdTree<T>::DeleteTree(node<T>*& p) const
{
	if (p)
	{
		DeleteTree(p->left);
		DeleteTree(p->right);
		delete p;
		p = NULL;
	}
}

template<typename T>
void BinOrdTree<T>::Copy(node<T>*& p, node<T>* const & r) const
{
	p = NULL;
	if (r)
	{
		p = new node<T>;
		p->inf = r->inf;
		Copy(p->left, r->left);
		Copy(p->right, r->right);
	}
}

template<typename T>
void BinOrdTree<T>::CopyTree(BinOrdTree<T> const &other)
{
	Copy(root, other.root);
}

template<typename T>
void BinOrdTree<T>::pr(const node<T>* p) const
{
	if (p)
	{
		pr(p->left);
		cout << p->inf << " ";
		pr(p->right);
	}
}

template<typename T>
void BinOrdTree<T>::Add(node<T>*& p, T const & x) const
{
	if (!p)
	{
		p = new node<T>;
		p->inf = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
		if (x > p->inf)
			Add(p->right, x);
		else
			Add(p->left, x);
}

template<typename T>
BinOrdTree<T>::BinOrdTree()
{
	root = NULL;
}

template<typename T>
BinOrdTree<T>::~BinOrdTree()
{
	DeleteTree(root);
}

template<typename T>
BinOrdTree<T>::BinOrdTree(BinOrdTree<T> const &other)
{
	CopyTree(other);
}

template<typename T>
BinOrdTree<T> & BinOrdTree<T>::operator=(BinOrdTree<T> const &)
{
	if (this != &other)
	{
		DeleteTree(root);
		CopyTree(other);
	}
	return *this;
}

template<typename T>
T BinOrdTree<T>::RootTree() const
{
	return root->inf;
}

template<typename T>
node<T>* BinOrdTree<T>::GetRoot() const
{
	return root;
}

template<typename T>
BinOrdTree<T> BinOrdTree<T>::LeftTree() const
{
	BinOrdTree<T> t;
	Copy(t.root, root->left);
	return t;
}

template<typename T>
BinOrdTree<T> BinOrdTree<T>::RightTree() const
{
	BinOrdTree<T> t;
	Copy(t.root, root->right);
	return t;
}

template<typename T>
bool BinOrdTree<T>::empty() const
{
	return root == NULL;
}

template<typename T>
void BinOrdTree<T>::print() const
{
	pr(root);
}

template<typename T>
void BinOrdTree<T>::AddNode(T const & x)
{
	Add(root, x);
}

template<typename T>
void BinOrdTree<T>::Create3(T x, BinOrdTree<T> t1, BinOrdTree<T> t2)
{
	node<T>* p = new node<T>;
	p->inf = x;
	Copy(p->left, t1.root);
	Copy(p->right, t2.root);
}

template<typename T>
void BinOrdTree<T>::Create()
{
	root = NULL;
	T x;
	char c;
	do
	{
		cout << "Enter an element: ";
		cin >> x;
		AddNode(x);
		cout << "More elements y/n? ";
		cin >> c;
	} while (c == 'y');
}

template<typename T>
void BinOrdTree<T>::MinTree(T &x, BinOrdTree<T>& mint) const
{
	T a = RootTree();
	if (!root->left)
	{
		x = a;
		mint = RightTree();
	}
	else
	{
		BinOrdTree<T> t1;
		LeftTree().MinTree(x, t1);
		mint.Create3(a, t1, RightTree());
	}
}

template<typename T>
T findLCA(BinOrdTree<T> t, T x, T y)
{
	node<T>* p = t.GetRoot();
	if (p->inf > x && p->inf > y)
		return findLCA(t.LeftTree(), x, y);
	else if (p->inf < x && p->inf < y)
		return findLCA(t.RightTree(), x, y);
	else return p->inf;
}
int main()
{
	BinOrdTree<int> a;
	a.Create();
	a.print();
	cout << endl;
	cout << findLCA<int>(a, 8, 16)<<endl;
	system("pause");
	return 0;
}

