#include <fstream>
#include <queue>

int main()
{
	std::ifstream in("input.txt");
	int n;
	in >> n;

	int* arr = new int[n];
	int** matr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			in >> matr[i][j];
		}
		arr[i] = -1;
	}

	std::queue<int> q;

	int count = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == -1)
		{
			q.push(i);
			while (!q.empty())
			{
				int curr = q.front();
				q.pop();
				if (arr[curr] != -1) continue;
				arr[curr] = count;
				count++;
				for (int j = 0; j < n; j++)
				{
					if (matr[curr][j] == 1 && arr[j] == -1)
					{
						q.push(j);
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