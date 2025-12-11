#include <fstream>
#include <stack>

int main()
{
	std::ifstream in("input.txt");
	int n;
	in >> n;

	int** matr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			in >> matr[i][j];
		}
	}
	in.close();

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}

	std::stack<int> s;
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			s.push(i);
			while (!s.empty())
			{
				if (arr[s.top()] != 0)
				{
					s.pop();
					continue;
				}
				int a = s.top();
				s.pop();
				arr[a] = count;
				count++;
				bool ind = false;
				for (int j = n - 1; j >= 0; j--)
				{
					if (matr[a][j] == 1)
					{
						ind = true;
						if (arr[j] == 0) s.push(j);
					}
				}
			}
		}
	}


	std::ofstream out("output.txt");
	for (int i = 0; i < n; i++)
	{
		out << arr[i] << ' ';
	}
	out.close();
}