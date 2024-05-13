#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

struct List {
	Node* Head;
	int size;
	Node* NewNode(const int& value) {
		Node* tmp = new Node;
		tmp->key = value;
		tmp->left = tmp->right = NULL;
		return tmp;
	}
	void Insert(const int& value) {
		if (Head == NULL) 
			Head = NewNode(value);
		else {
			Node* tmp = Head;
			while (true) {
				if (value < tmp->key) {
					if (tmp->left == NULL) {
						tmp->left = NewNode(value);
						break;
					}
					tmp = tmp->left;
				}
				else if (value > tmp->key) {
					if (tmp->right == NULL) {
						tmp->right = NewNode(value);
						break;
					}
					tmp = tmp->right;
				}
				else return;
			}
		}
		size++;
	}
	int Height(Node* tmp) {
		if (!tmp) 
			return 0;
		return max(Height(tmp->left), Height(tmp->right)) + 1;
	}
	int Min() {
		Node* tmp = Head;
		while (tmp->left) 
			tmp = tmp->left;
		return tmp->key;
	}
	int Max2() {
		Node* tmp = Head;
		if (!tmp->right) {
			tmp = tmp->left;
			while (tmp->right) 
				tmp = tmp->right;
			return tmp->key;
		}
		else {
			while (tmp->right) 
				tmp = tmp->right;
			if (tmp->left) {
				tmp = tmp->left;
				while (tmp->right) 
					tmp = tmp->right;
				return tmp->key;
			}
			else {
				Node* t = Head;
				while (t->right != tmp) 
					t = t->right;
				return t->key;
			}
		}
	}
	void Print(Node* tmp) {
		if (tmp->left) 
			Print(tmp->left);
		cout << tmp->key << " ";
		if (tmp->right) 
			Print(tmp->right);
	}
	void Print1(Node* tmp) {
		if (tmp->left) 
			Print1(tmp->left);
		if (tmp->right) 
			Print1(tmp->right);
		cout << tmp->key << " ";
	}
	void PrintLeafs(Node* tmp) {
		if (tmp->left) 
			PrintLeafs(tmp->left);
		if (!tmp->left && !tmp->right) 
			cout << tmp->key << " ";
		if (tmp->right) 
			PrintLeafs(tmp->right);
	}
	bool Check(Node* tmp) {
		if (!tmp) return true;
		bool flag = true;
		if (abs(Height(tmp->left) - Height(tmp->right)) > 1)
			flag = false;
		return Check(tmp->left) && Check(tmp->right) && flag;
	}
};

List a;

int main() {
	int n = 1;
	while (n != 0) {
		cin >> n;
		if (n != 0) 
			a.Insert(n);
	}
	cout << "Height: " << a.Height(a.Head) << endl;
	cout << "Min.value: " << a.Min() << endl;
	if (a.size == 1) 
		cout << "0" << endl;
	else 
		cout << "Second max.value: " << a.Max2() << endl;

	cout << "Sorted tree by value: ";
	a.Print(a.Head);
	cout << endl;

	cout << "Tree from buttom to up: ";
	a.Print1(a.Head);
	cout << endl;

	cout << "Leafs of the tree: ";
	a.PrintLeafs(a.Head);
	cout << endl;

	cout << "Is this tree balanced? - ";
	if (a.Check(a.Head)) 
		cout << "YES";
	else 
		cout << "NO";
	return 0;
}
