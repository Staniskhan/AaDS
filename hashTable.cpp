#include <fstream>

int main()
{
	int m, c, n;
	std::ifstream in("input.txt");

	in >> m >> c >> n;

	int* table = new int[m];
	for (int i = 0; i < m; i++)
	{
		table[i] = -1;
	}

	for (int j = 0; j < n; j++)
	{
		int a;
		in >> a;
		int i = 0;
		bool ind = false;
		while (table[((a % m) + c * i) % m] != -1)
		{
			if (table[((a % m) + c * i) % m] == a)
			{
				ind == true;
				break;
			}
			i++;
		}
		if (!ind) table[((a % m) + c * i) % m] = a;
	}

	in.close();

	std::ofstream out("output.txt");

	for (int i = 0; i < m; i++)
	{
		out << table[i] << ' ';
	}

	out.close();
}