#include<iostream>
#include<queue>
using namespace std;
template<typename T>
struct node
{
	T inf;
	node<T> *left, *right;
};
template<typename T>
class BinTree
{
private:
	node<T>* root;
	void DeleteBinTree(node<T>* &) const;
	void Copy(node<T> * &, node<T>* const&) const;
	void CopyBinTree(BinTree<T> const&);
	void pr(const node<T> *) const;
	void CreateBinTree(node<T> * &) const;
	void help(node<T>* p);
public:
	BinTree();
	~BinTree();
	BinTree(BinTree<T> const&);
	BinTree& operator=(BinTree<T> const&);
	T RootBinTree() const;
	BinTree<T> LeftBinTree() const;
	BinTree<T> RightBinTree() const;
	node<T>* GetRoot();
	bool empty() const;
	void print() const;
	void Create();
	void Create3(T, BinTree<T>, BinTree<T>);
	int findMaxHeight(node<T>*);
	void levelOrderTransversal(node<T>*);
	bool checkIfSearchTree(node<T>*);
};
template<typename T>
BinTree<T>::BinTree()
{
	root = NULL;
}
template<typename T>
BinTree<T>::BinTree(BinTree<T> const& other)
{
	CopyBinTree(other);
}
template<typename T>
BinTree<T>& BinTree<T>::operator = (BinTree<T> const& other)
{
	if (this != &other)
	{
		DeleteBinTree(root);
		CopyBinTree(other);
	}
	return *this;
}
template<typename T>
T BinTree<T>::RootBinTree() const
{
	return root->inf;
}
template<typename T>
BinTree<T> BinTree<T>::LeftBinTree() const
{
	BinTree<T> t;
	Copy(t.root, root->left);
	return t;
}
template<typename T>
BinTree<T> BinTree<T>::RightBinTree() const
{
	BinTree<T> t;
	Copy(t.root, root->right);
	return t;
}
template<typename T>
node<T>* BinTree<T>::GetRoot()
{
	return root;
}
template<typename T>
bool BinTree<T>::empty() const
{
	return root == NULL;
}
template<typename T>
void BinTree<T>::print() const
{
	pr(root);
}
template<typename T>
void BinTree<T>::Create()
{
	CreateBinTree(root);
}
template<typename T>
void BinTree<T>::Create3(T x, BinTree<T> left, BinTree<T> right)
{
	node<T>* root = new node<T>;
	root->inf = x;
	Copy(root->left, left.root);
	Copy(root->right, right.root);
}
template<typename T>
int BinTree<T>::findMaxHeight(node<T>* p)
{
	int leftHeight = 1;
	int rightHeight = 1;

	if (p->left != NULL) {
		leftHeight = 1 + findMaxHeight(p->left);
	}
	if (p->right != NULL) {
		rightHeight = 1 + findMaxHeight(p->right);
	}

	return leftHeight > rightHeight ? leftHeight : rightHeight;
}
template<typename T>
void BinTree<T>::help(node<T>* p)
{
	if (p->left)
		cout << p->left->inf << " ";
	if (p->right)
		cout << p->right->inf << " ";
}
template<typename T>
void BinTree<T>::levelOrderTransversal(node<T>* root)
{
	queue<node<T>*> q;

	if (!root) {
		return;
	}
	q.push(root);
	cout << root->inf << " ";
	while (!q.empty())
	{
		const node<T>* temp_node = q.front();
		q.pop();

		if (temp_node->left) {
			q.push(temp_node->left);
			cout << temp_node->left->inf << " ";
		}
		if (temp_node->right) {
			q.push(temp_node->right);
			cout << temp_node->right->inf << " ";
		}
		
	}
}
template<typename T>
bool BinTree<T>::checkIfSearchTree(node<T>* p)
{
	if (p)
	{
		if (p->left)
			if (p->left->inf > p->inf)
				return false;
		if (p->right)
			if (p->right->inf < p->inf)
				return false;
		checkIfSearchTree(p->left);
		checkIfSearchTree(p->right);
	}
	else
		return true;
}
template<typename T>
BinTree<T>::~BinTree()
{
	DeleteBinTree(root);
}
template<typename T>
void BinTree<T>::DeleteBinTree(node<T>* &p) const
{
	if (p)
	{
		DeleteBinTree(p->left);
		DeleteBinTree(p->right);
		delete p;
		p = NULL;
	}
}

template<typename T>
void BinTree<T>::Copy(node<T>* &pos, node<T>* const & r) const
{
	pos = NULL;
	if (r)
	{
		pos = new node<T>;
		pos->inf = r->inf;
		Copy(pos->left, r->left);
		Copy(pos->right, r->right);
	}
}

template<typename T>
void BinTree<T>::CopyBinTree(BinTree<T> const &)
{
	Copy(root, other.root);
}

template<typename T>
void BinTree<T>::pr(const node<T>* p) const
{
	if (p)
	{
		pr(p->left);
		cout << p->inf << " ";
		pr(p->right);
	}
}

template<typename T>
void BinTree<T>::CreateBinTree(node<T>*& p) const
{
	T x;
	cout << "Root: ";
	cin >> x;
	p = new node<T>;
	p->inf = x;
	p->left = NULL;
	p->right = NULL;
	char c;
	cout << "Left BinTree from " << x << " y/n ? ";
	cin >> c;
	if (c == 'y')
		CreateBinTree(p->left);
	cout << "Right BinTree from " << x << " y/n ? ";
	cin >> c;
	if (c == 'y')
		CreateBinTree(p->right);
}

int main()
{
	BinTree<int> a;
	a.Create();
	a.print();
	cout << a.findMaxHeight(a.GetRoot()) << endl;
	a.levelOrderTransversal(a.GetRoot());
	cout << endl;
	cout << a.checkIfSearchTree(a.GetRoot());
	system("pause");
	return 0;
}
