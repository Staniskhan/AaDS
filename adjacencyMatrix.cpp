#include <fstream>

int main()
{
	int n, m;
	std::ifstream in("input.txt");
	in >> n >> m;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		in >> a >> b;
		arr[a - 1][b - 1] = 1;
		arr[b - 1][a - 1] = 1;
	}

	in.close();

	std::ofstream out("output.txt");
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			out << arr[i][j] << ' ';
		}
		out << '\n';
	}

	out.close();
}