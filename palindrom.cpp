#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream in;
	in.open("input.txt");
	string str = "";
	in >> str;
	in.close();
	int n = str.length();

	int** memory = new int* [n];
	for (int i = 0; i < n; i++)
	{
		memory[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		memory[i][i] = 1;
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			memory[i][i + 1] = 2;
		}
		else
		{
			memory[i][i + 1] = 1;
		}
	}

	for (int k = 2; k < n; k++)
	{
		for (int i = 0; i < n - k; i++)
		{
			if (str[i] == str[i + k])
			{
				memory[i][i + k] = memory[i + 1][i + k - 1] + 2;
			}
			else
			{
				memory[i][i + k] = (memory[i][i + k - 1] > memory[i + 1][i + k]) ? memory[i][i + k - 1] : memory[i + 1][i + k];
			}
		}
	}

	int i = 0, j = n - 1;
	string ans = "";
	while (i < j)
	{
		if (str[i] == str[j])
		{
			ans += str[i];
			i++;
			j--;
		}
		else if (memory[i][j] == memory[i][j - 1])
		{
			j--;
		}
		else if (memory[i][j] == memory[i + 1][j])
		{
			i++;
		}
	}
	string ansrev = "";
	for (int x = ans.length() - 1; x >= 0; x--)
	{
		ansrev += ans[x];
	}
	if (i == j) ans += str[i];
	ans += ansrev;

	ofstream out;
	out.open("output.txt");

	out << memory[0][n - 1] << '\n' << ans;

	out.close();
}