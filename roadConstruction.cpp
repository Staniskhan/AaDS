#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, q;
	std::ifstream in;
	in.open("input.txt");

	in >> n >> q;

	std::vector<int> arr(n);
	int counter = n;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	std::ofstream out;
	out.open("output.txt");

	for (int i = 0; i < q; i++)
	{
		int a, b;
		in >> a >> b;

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

		out << counter << std::endl;
	}
	in.close();
	out.close();
}