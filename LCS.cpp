#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int* A = new int[n];
	int* B = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}

	int** memory = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		memory[i] = new int[n + 1];
	}

	for (int i = 0; i < n + 1; i++)
	{
		memory[0][i] = 0;
		memory[i][0] = 0;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				memory[i][j] = memory[i - 1][j - 1] + 1;
			}
			else
			{
				memory[i][j] = (memory[i - 1][j] > memory[i][j - 1]) ? memory[i - 1][j] : memory[i][j - 1];
			}
		}
	}


	int* wayA = new int[memory[n][n]];
	int* wayB = new int[memory[n][n]];
	int a = memory[n][n] - 1;
	int b = a;
	int i = n;
	int j = n;

	while (i > 0 && j > 0)
	{
		if (A[i - 1] == B[j - 1])
		{
			wayA[a] = i - 1;
			a--;
			wayB[b] = j - 1;
			b--;
			i--;
			j--;
		}
		else 
		{
			if (memory[i][j] == memory[i - 1][j])
			{
				i--;
			}
			else if (memory[i][j] == memory[i][j - 1])
			{
				j--;
			}
		}

	}

	cout << memory[n][n] << '\n';
	cout << wayA[0];
	for (i = 1; i < memory[n][n]; i++)
	{
		cout << ' ' << wayA[i];
	}
	cout << '\n' << wayB[0];
	for (i = 1; i < memory[n][n]; i++)
	{
		cout << ' ' << wayB[i];
	}
}