#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in;
	in.open("input.txt");

	int n = 0;
	in >> n;

	int* N = new int[n];
	int* M = new int[n];
	for (int i = 0; i < n; i++)
	{
		in >> N[i] >> M[i];
	}
	in.close();

	int** memory = new int*[n];
	for (int i = 0; i < n; i++)
	{
		memory[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		memory[i][i] = 0;
	}

	for (int i = 0; i < n - 1; i++)
	{
		memory[i][i + 1] = N[i] * M[i] * M[i + 1];
	}

	for (int k = 2; k < n; k++)
	{
		for (int i = 0; i < n - k; i++)
		{
			int sum = -1;
			for (int j = i; j < i + k; j++)
			{
				if (memory[i][j] + memory[j + 1][i + k] + N[i] * M[j] * M[i + k] < sum || sum < 0)
				{
					sum = memory[i][j] + memory[j + 1][i + k] + N[i] * M[j] * M[i + k];
				}
			}
			memory[i][i + k] = sum;
		}
	}
	ofstream out;
	out.open("output.txt");
	out << memory[0][n - 1];
}