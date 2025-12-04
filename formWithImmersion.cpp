#include <fstream>
#include <deque>

struct Element
{
	int x;
	int y;
	Element(int _x, int _y) : x(_x), y(_y) {};
};

void mark(int* matr, int n, int m, char* isOpen, std::deque<Element> &q, int* marked, int markVal, int waterLayer)
{
	int x = q.front().x;
	int y = q.front().y;
	q.pop_front();
	if (marked[(x - 1)*(m - 2) + y - 1] != markVal)
	{
		isOpen[(x - 1)*(m - 2) + y - 1] = 1;
		marked[(x - 1)*(m - 2) + y - 1] = markVal;
		if (x - 2 >= 0 && matr[(x - 1)*m + y] <= waterLayer)
		{
			q.push_back(Element(x - 1, y));
		}
		if (x < n - 2 && matr[(x + 1)*m + y] <= waterLayer)
		{
			q.push_back(Element(x + 1, y));
		}
		if (y - 2 >= 0 && matr[x*m + y - 1] <= waterLayer)
		{
			q.push_back(Element(x, y - 1));
		}
		if (y < m - 2 && matr[x*m + y + 1] <= waterLayer)
		{
			q.push_back(Element(x, y + 1));
		}
	}
}

int main()
{
	std::ifstream in("in.txt");
	int n, m;
	in >> n >> m;

	if (n < 3 || m < 3)
	{
		in.close();
		std::ofstream out("out.txt");
		out << 0;
		out.close();
		return 0;
	}

	//matrix for current layer
	//find min in layer for cutting bottom layers
	int min = 10001;
	int* matr = new int[n * m];
	for (int i = 0; i < n * m; i++)
	{
		in >> matr[i];
		if (matr[i] < min) min = matr[i];
	}

	in.close();

	//matrix for marking 'open cavities'
	//if true then it is 'open'
	char* isOpen = new char [(n - 2)*(m - 2)];
	for (int i = 0; i < (n - 2)*(m - 2); i++)
	{
		isOpen[i] = 0;
	}

	int count = 0;

	std::deque<Element> q; // попробовать заменить на массив с индексами

	int* marked = new int [(n - 2)*(m - 2)];
	for (int i = 0; i < (n - 2)*(m - 2); i++)
	{
		marked[i] = 0;
	}

	bool ind = true;
	int markVal = 1;
	int waterLayer = min;
	while (ind)
	{
		for (int i = 1; i < m - 1; i++)
		{
			if (matr[i] <= waterLayer && matr[m + i] <= waterLayer)
			{
				q.push_back(Element(1, i));
			}
			if (matr[(n - 1)*m + i] <= waterLayer && matr[(n - 2)*m + i] <= waterLayer)
			{
				q.push_back(Element(n - 2, i));
			}
		}

		for (int i = 1; i < n - 1; i++)
		{
			if (matr[i*m] <= waterLayer && matr[i*m + 1] <= waterLayer)
			{
				q.push_back(Element(i, 1));
			}
			if (matr[i*m + m - 1] <= waterLayer && matr[i* m + m - 2] <= waterLayer)
			{
				q.push_back(Element(i, m - 2));
			}
		}

		while (!q.empty())
		{
			mark(matr, n, m, isOpen, q, marked, markVal, waterLayer);
		}

		int layerCount = 0;
		int min = 10001;
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (matr[i*m + j] <= waterLayer && !isOpen[(i - 1)*(m - 2) + j - 1]) layerCount++;
				if (matr[i*m + j] < min && matr[i*m + j] > waterLayer) min = matr[i*m + j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (matr[i*m] < min && matr[i*m] > waterLayer) min = matr[i*m];
			if (matr[i*m + m - 1] < min && matr[i*m + m - 1] > waterLayer) min = matr[i*m + m - 1];
		}
		for (int i = 1; i < m - 1; i++)
		{
			if (matr[i] < min && matr[i] > waterLayer) min = matr[i];
			if (matr[(n - 1)*m + i] < min && matr[(n - 1)*m + i] > waterLayer) min = matr[(n - 1)*m + i];
		}

		if (min != 10001)
		{
			count += layerCount * (min - waterLayer);

			markVal++;
			waterLayer = min;
		}
		else ind = false;

	}

	std::ofstream out("out.txt");
	out << count;
	out.close();
	delete[] matr;
	delete[] isOpen;
	delete[] marked;
}