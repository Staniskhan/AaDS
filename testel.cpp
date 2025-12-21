#include <iostream>

size_t pow(int x, int n)
{
	size_t res = 1;
	while (n > 0)
	{
		res *= x;
		n--;
	}
	return res;
}

int main()
{
	int x, n;
	std::cin >> x >> n;
	std::cout << pow(x, n);
}