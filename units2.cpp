#include <iostream>
using namespace std;

int fact_mod(int n)
{
	if (n == 0) return 1;
	return (fact_mod(n - 1) * (n % 1000000007)) % 1000000007;
}

int pow_mod(int n, int pow)
{
	if (pow == 0) return 1;
	else if (pow == 1) return n % 1000000007;

	long long base = n;
	long long res = 1;
	base = base % 1000000007;
	while (pow > 1)
	{
		if (pow % 2)
		{
			pow--;
			res = (res * base) % 1000000007;
		}
		pow = pow >> 1;
		base = (base * base) % 1000000007;
	}

	return int((res * base) % 1000000007);
}

int binom_mod(int n, int k)
{
	if (k == 0 || k == n) return 1;

	long long res = 1;
	for (int i = 1; i <= k; i++) {
		res = res * (n - k + i) % 1000000007;
		res = res * pow_mod(i, 1000000007 - 2) % 1000000007;
	}
	return int(res);
}

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;

	if (k == 0 || n == k)
	{
		cout << 1;
		return 0;
	}

	if (k > (n / 2))
	{
		k = n - k;
	}

	int ans = binom_mod(n, k);

	cout << ans;
}