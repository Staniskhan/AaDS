#include <fstream>

int main()
{
	std::ifstream in("input.txt");
	int n;
	in >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			in >> a;
			if (a)
			{
				arr[j] = i + 1;
			}
		}
	}

	in.close();

	std::ofstream out("output.txt");

	for (int i = 0; i < n; i++)
	{
		out << arr[i] << ' ';
	}

	out.close();
}