#include <fstream>

int check(int** matr, int** indarr, int fromLine, int fromCol, int n, int m)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (indarr[i - 1][j - 1] == 0 && matr[i][j] <= 0)
			{
				//int ind = 0;
				if (matr[i][j + 1] <= 0 && indarr[i - 1][j] == 1)
				{
					//change indarr
					//return -1
				}
				else if (matr[i][j + 1] <= 0 && indarr[i - 1][j] == 0) // i - 1] does not exist !!!!!!!!!!!!!!!!
				{
					//ind = cr(right)
					//ind 
				}
				if (matr[i + 1][j] <= 0 && indarr[i][j - 1] == 1)
				{
					//change indarr
					//return -1
				}
				else if (matr[i + 1][j] <= 0 && indarr[i][j - 1] == 0)
				{
					//ind = cl(right)
					//ind 
				}

			}
		}
	}
}

int main()
{
	std::ifstream in("in.txt");
	int n, m;
	in >> n >> m;

	int min = 0;;
	int** matr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[n];

		for (int j = 0; j < n; j++)
		{
			in >> matr[i][j];
			if (matr[i][j] < min) min = matr[i][j];
		}
	}

	in.close();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matr[i][j] -= min;
		}
	}


}