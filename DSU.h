#include <iostream>
#include <vector>

template <class T>
class DSU
{
private:
	struct Node
	{
		T key;
		Node* representative;
		Node* next;
	};
	struct set
	{
		Node* head;
		Node* tail;
	};
	std::vector<set> sets;
	std::vector<Node*> elements;
};