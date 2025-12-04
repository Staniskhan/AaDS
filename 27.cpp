#include <fstream>
#include <vector>

struct Node
{
	int key;
	Node* left;
	Node* right;
};

int findDelMin(Node* node)
{
	if (node->left == NULL && node->right == NULL) return node->key;
	Node* curr = node;
	Node* parent = curr;
	while (curr->left != NULL)
	{
		parent = curr;
		curr = curr->left;
	}
	int ret = curr->key;
	if (curr->right == NULL)
	{
		parent->left = NULL;
		delete curr;
	}
	else
	{
		curr->key = findDelMin(curr->right);
		if (curr->right->key == curr->key)
		{
			delete curr->right;
			curr->right = NULL;
		}
	}
	return ret;
}

void getLeaves(Node* node, std::vector<int>& leaves)
{
	if (node == NULL)
		return;
	if (node->left == NULL && node->right == NULL)
	{
		leaves.push_back(node->key);
		return;
	}
	getLeaves(node->left, leaves);
	getLeaves(node->right, leaves);
}

void preorder(Node* node, std::ofstream& out)
{
	if (node == NULL)
		return;
	out << node->key << "\n";
	preorder(node->left, out);
	preorder(node->right, out);
}

int main() {
	std::ifstream in("tst.in");

	Node* head = new Node;
	in >> head->key;
	head->left = NULL;
	head->right = NULL;
	int k;
	while (in >> k) {
		Node* curr = head;
		while (curr != NULL)
		{
			if (k == curr->key)
			{
				curr = NULL;
			}
			else if (k < curr->key)
			{
				if (curr->left == NULL)
				{
					curr->left = new Node;
					curr->left->key = k;
					curr->left->left = NULL;
					curr->left->right = NULL;
					curr = NULL;
				}
				else
				{
					curr = curr->left;
				}
			}
			else if (k > curr->key)
			{
				if (curr->right == NULL)
				{
					curr->right = new Node;
					curr->right->key = k;
					curr->right->left = NULL;
					curr->right->right = NULL;
					curr = NULL;
				}
				else
				{
					curr = curr->right;
				}
			}
		}
	}
	in.close();

	std::vector<int> leaves;

	getLeaves(head, leaves);

	if (leaves.size() % 2)
	{
		int toDelete = leaves[leaves.size() / 2];
		if (head->left != NULL && toDelete == head->left->key && head->right == NULL)
		{
			std::ofstream out("tst.out");
			out << head->left->key;
			out.close();
		}
		else if (head->right != NULL && toDelete == head->right->key && head->left == NULL)
		{
			std::ofstream out("tst.out");
			out << head->right->key;
			out.close();
		}
		Node* curr = head;
		Node* parent = curr;
		while (curr->key != toDelete)
		{
			parent = curr;
			if (toDelete < curr->key)
			{
				curr = curr->left;
			}
			else if (toDelete > curr->key)
			{
				curr = curr->right;
			}
		}
		if (parent->right == NULL)
		{
			parent->key = curr->key;
			delete curr;
			parent->left = NULL;
		}
		else
		{
			parent->key = findDelMin(parent->right);
			if (parent->right->key == parent->key)
			{
				delete parent->right;
				parent->right = NULL;
			}
		}
	}

	std::ofstream out("tst.out");
	preorder(head, out);
	out.close();
}