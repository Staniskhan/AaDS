#include <fstream>

int main()
{
	std::ifstream in("input.txt");

	int n;
	in >> n;

	int* arr = new int [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		in >> a >> b;
		arr[b - 1] = a;
	}

	in.close();

	std::ofstream out("output.txt");

	for (int i = 0; i < n; i++)
	{
		out << arr[i] << ' ';
	}

	out.close();
}