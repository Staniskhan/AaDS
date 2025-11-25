#include <fstream>

struct Node
{
	int key;
	Node* next;
};

struct List
{
	Node* head;
	int length;
};

int main()
{
	std::ifstream in("input.txt");
	int n, m;
	in >> n >> m;

	List* arr = new List[n];

	for (int i = 0; i < n; i++)
	{
		arr[i].head = NULL;
		arr[i].length = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		in >> a >> b;
		
		arr[a - 1].length++;
		arr[b - 1].length++;

		Node* curr1 = new Node();
		curr1->key = b;
		curr1->next = arr[a - 1].head;
		arr[a - 1].head = curr1;

		Node* curr2 = new Node();
		curr2->key = a;
		curr2->next = arr[b - 1].head;
		arr[b - 1].head = curr2;
	}

	in.close();

	std::ofstream out("output.txt");

	for (int i = 0; i < n; i++)
	{
		out << arr[i].length;
		Node* curr = arr[i].head;
		for (int j = 0; j < arr[i].length; j++)
		{
			out << ' ' << curr->key;
			curr = curr->next;
		}
		out << '\n';
	}

	out.close();
}