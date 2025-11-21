#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

struct node
{
	int key;
	node* left;
	node* right;
	node() : key(NULL), left(NULL), right(NULL) {};
	node(int _key) : key(_key), left(NULL), right(NULL) {};
};

void PreOrderLeftTravesal(node* head)
{
	stack<node*> st;
	st.push(head);
	int last = 0;

	ofstream out;
	out.open("output.txt");
	while (!st.empty())
	{
		node* curr = st.top();
		st.pop();

		out << curr->key << '\n';

		if (curr->right != NULL)
		{
			st.push(curr->right);
		}
		if (curr->left != NULL)
		{
			st.push(curr->left);
		}
	}
	out.close();
}

node* findMin(node* head)
{
	node* curr = head;
	while (curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr;
}

node* findNode(node* head, int del)
{
	node* curr = head;
	while (curr != NULL)
	{
		if (del == curr->key)
		{
			return curr;
		}
		else if (del > curr->key)
		{
			curr = curr->right;
		}
		else if (del < curr->key)
		{
			curr = curr->left;
		}
	}
	return NULL;
}

void deleteNode(node* head, node* del)
{
	if (del->left == NULL && del->right == NULL)
	{
		if (del == head)
		{
			delete[] head;
			head = NULL;
			return;
		}
		else
		{
			node* curr = head;
			while (curr->left != del && curr->right != del)
			{
				if (del->key > curr->key)
				{
					curr = curr->right;
				}
				else if (del->key < curr->key)
				{
					curr = curr->left;
				}
			}
			if (curr->left == del)
			{
				delete[] curr->left;
				curr->left = NULL;
			}
			else if (curr->right == del)
			{
				delete[] curr->right;
				curr->right = NULL;
			}
		}
	}
	else if (del->left == NULL && del->right != NULL)
	{
		del->key = del->right->key;
		del->left = del->right->left;
		node* mem = del->right->right;
		delete[] del->right;
		del->right = mem;
	}
	else if (del->left != NULL && del->right == NULL)
	{
		del->key = del->left->key;
		del->right = del->left->right;
		node* mem = del->left->left;
		delete[] del->left;
		del->left = mem;
	}
	else if (del->left != NULL && del->right != NULL)
	{
		node* minInRight = findMin(del->right);
		int _key = minInRight->key;
		deleteNode(head, minInRight);
		del->key = _key;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream in;
	in.open("input.txt");
	int del;
	in >> del;
	node* head = new node;
	in >> head->key;
	node* curr;
	int key;
	bool induk;
	while (in >> key)
	{
		curr = head;
		induk = true;
		while (induk)
		{
			if (key > curr->key)
			{
				if (curr->right == NULL)
				{
					curr->right = new node(key);
					induk = false;
				}
				else
				{
					curr = curr->right;
				}
			}
			else if (key < curr->key)
			{
				if (curr->left == NULL)
				{
					curr->left = new node(key);
					induk = false;
				}
				else
				{
					curr = curr->left;
				}
			}
			else if (key == curr->key)
			{
				induk = false;
			}
		}
	}
	in.close();
	
	deleteNode(head, findNode(head, del));
	PreOrderLeftTravesal(head);
	delete[] head;
}