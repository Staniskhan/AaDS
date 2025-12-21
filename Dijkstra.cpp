#include <fstream>
#include <vector>
typedef unsigned long long ll;

struct toNValue
{
	int to;
	int value;
	toNValue(int t, int v) : to(t), value(v) {};
};

struct idNVal
{
	int id; 
	int val;
};

class PRQ // min_heap
{
public:
	int size;
	int* arr;
	int* id;
	int last;
	void popUp(int x)
	{
		if (arr[x] < arr[(x - 1) / 2])
		{
			std::swap(arr[x], arr[(x - 1) / 2]);
			std::swap(id[x], id[(x - 1) / 2]);
		}
	}
	void sink(int x)
	{
		int ch;
		if (2 * x + 1 > last)
		{
			return;
		}
		if (2 * x + 2 > last)
		{
			ch = 1;
		}
		else
		{
			ch = (arr[2 * x + 1] < arr[2 * x + 2]) ? 1 : 2;
		}
		
		std::swap(arr[x], arr[2 * x + ch]);
		std::swap(id[x], id[2 * x + ch]);
	}
	int minChild(int x)
	{
		if (2 * x + 1 > last)
		{
			return -1;
		}
		if (2 * x + 2 > last)
		{
			return 2 * x + 1;
		}
		return (arr[2 * x + 1] < arr[2 * x + 2]) ? 2 * x + 1 : 2 * x + 2;
	}
public:
	PRQ(int s) : size(s), arr(new int[s]), id(new int [s]), last(-1) {};
	void add(int _id, int x)
	{
		arr[++last] = x;
		id[last] = _id;
		int pos = last;
		while (pos > 0 && arr[pos] < arr[(pos - 1) / 2])
		{
			popUp(pos);
			pos = (pos - 1) / 2;
		}
	}
	void add(idNVal str)
	{
		arr[++last] = str.val;
		id[last] = str.id;
		int pos = last;
		while (pos > 0 && arr[pos] < arr[(pos - 1) / 2])
		{
			popUp(pos);
			pos = (pos - 1) / 2;
		}
	}
	idNVal get()
	{
		idNVal ret;
		ret.val = arr[0];
		ret.id = id[0];
		int pos = 0;
		arr[0] = arr[last];
		id[0] = id[last];
		arr[last] = -1;
		id[last] = -1;
		last--;
		while (pos <= last && minChild(pos) > 0 && arr[pos] > arr[minChild(pos)])
		{
			pos = minChild(pos);
			sink(pos);
		}
		return ret;
	}
	int getSize()
	{
		return last + 1;
	}
};

int main()
{
	std::fstream in("input.txt");
	int n, m;
	in >> n >> m;

	std::vector<std::vector<toNValue>> adjLists(n);
	int* processed = new int[n];
	ll* dist = new ll[n];
	PRQ prq(2*m);

	for (int i = 0; i < m; i++)
	{
		int a, b, val;
		in >> a >> b >> val;
		adjLists[a - 1].push_back(toNValue(b - 1, val));
		adjLists[b - 1].push_back(toNValue(a - 1, val));
	}
	in.close();

	for (int i = 0; i < n; i++)
	{
		processed[i] = 0;
		dist[i] = INT_MAX;
	}
	dist[0] = 0;

	prq.add(0, 0);

	while (prq.getSize() > 0)
	{
		idNVal curr = prq.get();
		if (processed[curr.id] == 0)
		{
			processed[curr.id] = 1;
			for (int i = 0; i < adjLists[curr.id].size(); i++)
			{
				dist[adjLists[curr.id][i].to] = (dist[adjLists[curr.id][i].to] < (dist[curr.id] + adjLists[curr.id][i].value)) ? dist[adjLists[curr.id][i].to] : (dist[curr.id] + adjLists[curr.id][i].value);
				prq.add(adjLists[curr.id][i].to, dist[adjLists[curr.id][i].to]);
			}
		}
	}

	std::ofstream out("output.txt");
	out << dist[n - 1];
	out.close();
}