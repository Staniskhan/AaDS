#include <iostream>
#include <fstream>
#include <vector>

struct road
{
	int a;
	int b;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::ifstream in("input.txt");

	int n, m, q;
	in >> n >> m >> q;

	std::vector<int> arr(n);
	int counter = n;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	std::vector<road> roads(m);

	for (int i = 0; i < m; i++)
	{
		in >> roads[i].a >> roads[i].b;
	}

	std::vector<int> destructionOrder(q);
	std::vector<bool> destructed(m);

	for (int i = 0; i < m; i++)
	{
		destructed[i] = false;
	}

	for (int i = 0; i < q; i++)
	{
		in >> destructionOrder[i];
		destructed[destructionOrder[i] - 1] = true;
	}

	in.close();

	int j = 0;
	for (int i = 0; i < m - q; i++)
	{
		while (destructed[j]) j++;

		int a, b;
		a = roads[j].a;
		b = roads[j].b;

		while (a != arr[a - 1])
		{
			a = arr[a - 1];
		}

		while (b != arr[b - 1])
		{
			b = arr[b - 1];
		}

		if (a < b)
		{
			arr[a - 1] = b;
			counter--;
		}
		else if (a > b)
		{
			arr[b - 1] = a;
			counter--;
		}

		j++;
	}

	int c1 = 0;
	while (counter > 1)
	{
		int x = destructionOrder.back();
		destructionOrder.pop_back();

		int a = roads[x - 1].a;
		int b = roads[x - 1].b;

		while (a != arr[a - 1])
		{
			a = arr[a - 1];
		}

		while (b != arr[b - 1])
		{
			b = arr[b - 1];
		}

		if (a < b)
		{
			arr[a - 1] = b;
			counter--;
		}
		else if (a > b)
		{
			arr[b - 1] = a;
			counter--;
		}

		c1++;
	}

	std::ofstream out("output.txt");
	for (int i = 0; i < q - c1; i++)
	{
		out << 1;
	}

	for (int i = 0; i < c1; i++)
	{
		out << 0;
	}

	out.close();
}