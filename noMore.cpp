#include <fstream>

int pow(int n, int pow)
{
	if (pow == 0) return 1;
	else if (pow == 1) return n;

	int base = n;
	int res = 1;
	while (pow > 1)
	{
		if (pow % 2)
		{
			pow--;
			res *= base;
		}
		pow = pow >> 1;
		base *= base;
	}

	return res * base;
}

int spacers(int n, int m)
{
	if (m == 0 || n == m)
	{
		return 1;
	}
	m = (m <= n - m) ? m : n - m;
	int res = 1;
	int res1 = 1;
	for (int i = 1; i <= m; i++)
	{
		res = res * (n - m + i);
		res1 = res1 * i;
	}
	return res / res1;
}



int main()
{
	int k, n;
	std::ifstream in("input.txt");
	in >> k >> n;
	in.close();

	int maxNumberOfComponents = (n + 1) / 2;

	int res = 0;
	for (int i = 1; i <= maxNumberOfComponents; i++)
	{
		for (int j = i; j <= n - i + 1; j++)
		{
			res += pow(k, j) * spacers(j - 1, i - 1);
		}
	}

	std::ofstream out("output.txt");
	out << res;
	out.close();
}