#include <iostream>
#include <fstream>
using namespace std;

struct top
{
	int key;
	bool isRight;
	int parent;
	int minVal;
	int maxVal;
};

int main()
{
	ifstream in;
	in.open("bst.in");

	int n = 0;
	in >> n;

	top* tree = new top[n];

	top root;
	in >> root.key;
	root.maxVal = NULL;
	root.minVal = NULL;
	tree[0] = root;

	ofstream out;
	out.open("bst.out");

	for (int i = 1; i < n; i++)
	{
		top curr;
		in >> curr.key;
		in >> curr.parent;
		char RL;
		in >> RL;
		if (RL == 'R')
		{
			curr.isRight = true;
		}
		else
		{
			curr.isRight = false;
		}



		if (curr.isRight)
		{
			curr.minVal = tree[curr.parent - 1].key;
			curr.maxVal = tree[curr.parent - 1].maxVal;

			if (curr.maxVal == NULL)
			{
				if (curr.key >= curr.minVal)
				{
					tree[i] = curr;
				}
				else
				{
					out << "NO";
					out.close();
					return 0;
				}
			}
			else
			{
				if (curr.key >= curr.minVal && curr.key < curr.maxVal)
				{
					tree[i] = curr;
				}
				else
				{
					out << "NO";
					out.close();
					return 0;
				}
			}
		}
		else
		{
			curr.minVal = tree[curr.parent - 1].minVal;
			curr.maxVal = tree[curr.parent - 1].key;

			if (curr.minVal == NULL)
			{
				if (curr.key < curr.maxVal)
				{
					tree[i] = curr;
				}
				else
				{
					out << "NO";
					out.close();
					return 0;
				}
			}
			else
			{
				if (curr.key < curr.maxVal && curr.key > curr.minVal)
				{
					tree[i] = curr;
				}
				else
				{
					out << "NO";
					out.close();
					return 0;
				}
			}
		}
	}

	out << "YES";
	out.close();
}