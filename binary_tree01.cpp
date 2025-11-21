//direct left traversal of a binary tree
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream in;
	in.open("input.txt");
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

	PreOrderLeftTravesal(head);
	delete[] head;
}