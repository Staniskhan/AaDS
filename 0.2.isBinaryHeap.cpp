#include <iostream>
#include <fstream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::ifstream in;
	in.open("input.txt");

	int n;
	in >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		in >> arr[i];
	}

	in.close();

	int i = 0;
	bool indicator = true;
	while (2 * i + 2 <= n - 1 && indicator)
	{
		if (arr[2 * i + 1] < arr[i] || arr[2 * i + 2] < arr[i])
		{
			indicator = false;
		}
		i++;
	}
	if (indicator && 2 * i + 1 == n - 1 && arr[2 * i + 1] < arr[i])
	{
		indicator = false;
	}

	std::ofstream out;
	out.open("output.txt");
	switch (indicator)
	{
	case true:
		out << "Yes";
		break;
	case false:
		out << "No";
		break;
	}
	out.close();
}