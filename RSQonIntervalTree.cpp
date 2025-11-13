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

long long FindSum(std::vector<int>& tree, int inf, int sup, int index, int l, int r)
{
	if (inf == l && sup == r)
	{
		return tree[index];
	}
	if (r <= (inf + sup) / 2)
	{
		return FindSum(tree, inf, (inf + sup) / 2, 2 * index + 1, l, r);
	}
	if (l >= (inf + sup) / 2)
	{
		return FindSum(tree, (inf + sup) / 2, sup, 2 * index + 2, l, r);
	}
	return FindSum(tree, inf, (inf + sup) / 2, 2 * index + 1, l, (inf + sup) / 2) + FindSum(tree, (inf + sup) / 2, sup, 2 * index + 2, (inf + sup) / 2, r);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

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
			std::cout << FindSum(tree, 0, n, 0, a, b) << '\n';
		}
		else if (request == "Add")
		{
			int a, b;
			std::cin >> a >> b;
			Add(tree, 0, n, 0, a, b);
		}
	}
}