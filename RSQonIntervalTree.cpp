#include <iostream>
#include <vector>
#include <string>

void buildIntervalTree(std::vector<int>& arr, std::vector<int>& tree, int inf, int sup, int index)
{
	if (sup - inf == 1)
	{
		tree[index] = arr[inf];
	}
	else
	{
		buildIntervalTree(arr, tree, inf, (inf + sup) / 2, 2 * index + 1);
		buildIntervalTree(arr, tree, (inf + sup) / 2, sup, 2 * index + 2);
		tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
	}
}

void Add(std::vector<int>& tree, int inf, int sup, int index, int i, int x)
{
	if (sup - inf == 1)
	{
		tree[index] += x;
	}
	else if (i < (inf + sup) / 2)
	{
		Add(tree, inf, (sup + inf) / 2, 2 * index + 1, i, x);
		tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
	}
	else if (i >= (inf + sup) / 2)
	{
		Add(tree, (sup + inf) / 2, sup, 2 * index + 2, i, x);
		tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
	}
}

int FindSum(std::vector<int> tree, int inf, int sup, int index, int l, int r)
{
	if (sup - inf == 1)
	{
		return tree[index];
	}
	else if (l >= inf && l < (inf + sup) / 2 && r > (inf + sup) / 2 && r <= sup)
	{
		return FindSum(tree, inf, (inf + sup) / 2, 2 * index + 1, l, r) + FindSum(tree, (inf + sup) / 2, sup, 2 * index + 2, l, r);
	}
	else if (l >= inf && r <= (sup + inf) / 2)
	{
		return FindSum(tree, inf, (inf + sup) / 2, 2 * index + 1, l, r);
	}
	else if (l >= (sup + inf) / 2 && r <= sup)
	{
		return FindSum(tree, (inf + sup) / 2, sup, 2 * index + 2, l, r);
	}
	else if (l >= inf && l < (inf + sup) / 2 && r > sup)
	{
		return FindSum(tree, inf, (inf + sup) / 2, 2 * index + 1, l, r) + tree[2 * index + 2];
	}
	else if (l >= (inf + sup) / 2 && l < sup && r > sup)
	{
		return FindSum(tree, (inf + sup) / 2, sup, 2 * index + 2, l, r);
	}
	else if (r <= sup && r > (inf + sup) / 2 && l < inf)
	{
		return FindSum(tree, (inf + sup) / 2, sup, 2 * index + 2, l, r) + tree[2 * index + 1];
	}
	else if (r <= (inf + sup) / 2 && r > inf && l < inf)
	{
		return FindSum(tree, inf, (inf + sup) / 2, 2 * index + 1, l, r);
	}	
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	std::vector<int> tree(4 * n);

	buildIntervalTree(arr, tree, 0, n, 0);

	int q;
	std::cin >> q;
	
	for (int i = 0; i < q; i++)
	{
		std::string request;
		std::cin >> request;
		if (request == "FindSum")
		{
			int a, b;
			std::cin >> a >> b;
			std::cout << FindSum(tree, 0, n, 0, a, b);
		}
		else if (request == "Add")
		{
			int a, b;
			std::cin >> a >> b;
			Add(tree, 0, n, 0, a, b);
		}
	}
}