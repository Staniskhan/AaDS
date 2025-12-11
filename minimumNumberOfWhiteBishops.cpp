#include <fstream>

struct Pos
{
	int x;
	int y;
	Pos() : x(0), y(0) {}
	Pos(int x, int y) : x(x), y(y) {}
};

Pos findRepresentative(int** arr, Pos** DSU, Pos p, int n, int m)
{
	if (DSU[p.x][p.y].x == p.x && DSU[p.x][p.y].y == p.y)
	{
		return p;
	}
	return findRepresentative(arr, DSU, Pos(DSU[p.x][p.y].x, DSU[p.x][p.y].y), n, m);
}

void Union(int** arr, Pos** DSU, Pos a, Pos b, int n, int m)
{
	Pos A = findRepresentative(arr, DSU, a, n, m);
	Pos B = findRepresentative(arr, DSU, b, n, m);
	if (A.x != B.x || A.y != B.y)
	{
		DSU[B.x][B.y] = A;
	}
}

void processElement(int** arr, Pos** DSU, int x, int y, int n, int m)
{
	if (arr[x][y] == -1) return;
	if (y - 1 >= 0 && 
		arr[x + 1][y - 1] == 0)
	{
		Union(arr, 
			DSU, 
			findRepresentative(
				arr, 
				DSU, 
				Pos(x, y), 
				n, 
				m), 
			findRepresentative(
				arr, 
				DSU, 
				Pos(x + 1, y - 1), 
				n, 
				m), 
			n, 
			m);
	}
	if (y + 1 < m &&
		arr[x + 1][y + 1] == 0)
	{
		Union(arr,
			DSU,
			findRepresentative(arr, DSU, Pos(x, y), n, m),
			findRepresentative(arr, DSU, Pos(x + 1, y + 1), n, m),
			n,
			m);
	}
}

int main()
{
	std::ifstream in("in.txt");
	int n, m;
	in >> n >> m;
	int** board = new int*[n];
	Pos** DSU = new Pos*[n];
	for (int i = 0; i < n; i++)
	{
		board[i] = new int[m];
		DSU[i] = new Pos[m];
		for (int j = 0; j < m; j++)
		{
			in >> board[i][j];
			DSU[i][j] = Pos(i, j);
		}
	}

	in.close();

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			processElement(board, DSU, i, j, n, m);
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 && DSU[i][j].x == i && DSU[i][j].y == j)
			{
				count++;
			}
		}
	}

	std::ofstream out("out.txt");
	out << count;
	out.close();
}