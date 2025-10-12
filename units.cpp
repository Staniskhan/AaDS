#include <iostream>
using namespace std;

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;

	if (k == 0 || n == k)
	{
		cout << 1;
		return 0;
	}

	int* memory = new int[k + 1];
	memory[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		memory[i] = 0;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = k; j > 0; j--)
		{
			memory[j] = (memory[j] + memory[j - 1]) % 1000000007;
		}
	}
	
	int ans = (memory[k] + memory[k - 1]) % 1000000007;
	cout << ans;
}