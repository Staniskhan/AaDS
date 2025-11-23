#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct city
{
	std::string name;
	char connection;
	std::vector<city*> prevCities;
	std::vector<std::vector<std::string>> ways;
	city* next;
	city* prev;
};

int main()
{
	int n, m;
	std::ifstream in("in.txt");
	in >> n >> m;

	if (n == 2 && m == 0)
	{
		std::ofstream out("out.txt");
		out << "No solution";
		return 0;
	}
	else if (n == 2 && m == 1)
	{
		std::ofstream out("out.txt");
		out << 2;
		return 0;
	}

	city* head;
	std::vector<std::string> names;

	//заполнение городов
	head = new city();
	in >> head->name;
	names.push_back(head->name);
	head->connection = 'y';
	std::vector<std::string> startV;
	startV.push_back(head->name);
	head->ways.push_back(startV);
	city* curr = head;
	head->prev = NULL;
	for (short i = 1; i < n; i++)
	{
		curr->next = new city();
		curr->next->prev = curr;

		in >> curr->next->name;
		names.push_back(curr->next->name);
		curr->next->connection = 'n';
		curr = curr->next;
		curr->next = NULL;
	}

	city* tail = curr;

	//заполнение рейсов
	for (int i = 0; i < m; i++)
	{
		std::string a;
		std::string b;
		in >> a >> b;
		curr = tail;
		for (short j = n - 1; j >= 0; j--)
		{
			if (curr->name == a)
			{
				city* curr1 = curr;
				for (short k = j; k >= 0; k--)
				{
					if (curr1->name == b)
					{
						curr->prevCities.push_back(curr1);
						k = -1;
						j = -1;
					}
					curr1 = curr1->prev;
				}
			}
			else if (curr->name == b)
			{
				city* curr1 = curr;
				for (short k = j; k >= 0; k--)
				{
					if (curr1->name == a)
					{
						curr->prevCities.push_back(curr1);
						k = -1;
						j = -1;
					}
					curr1 = curr1->prev;
				}
			}
			curr = curr->prev;
		}
	}
	in.close();


	//просчет путей
	curr = head->next;
	while (curr != NULL)
	{
		for (short j = 0; j < curr->prevCities.size(); j++)
		{
			if (curr->prevCities[j]->connection == 'y')
			{
				for (int k = 0; k < curr->prevCities[j]->ways.size(); k++)
				{
					curr->ways.push_back(curr->prevCities[j]->ways[k]);
					curr->ways[curr->ways.size() - 1].push_back(curr->name);
				}
				curr->connection = 'y';
			}
		}
		curr = curr->next;
	}


	if (tail->connection == 'n')
	{
		std::ofstream out("out.txt");
		out << "No solution";
		return 0;
	}


	bool** arr = new bool* [tail->ways.size()];
	for (int i = 0; i < tail->ways.size(); i++)
	{
		arr[i] = new bool[tail->ways.size()];
		for (int j = 0; j < tail->ways.size(); j++)
		{
			arr[i][j] = false;
		}
	}



	for (int i = 1; i < names.size() - 1; i++)
	{
		std::vector<int> arr1;
		for (int j = 0; j < tail->ways.size(); j++)
		{
			if (tail->ways[j][i] == names[i])
			{
				arr1.push_back(j);
			}
		}

		for (int j = 0; j < arr1.size(); j++)
		{
			for (int k = j + 1; k < arr1.size(); k++)
			{
				arr[j][k] = true;
			}
		}
	}

	int max = -1;
	for (int i = 1; i < tail->ways.size(); i++)
	{
		for (int j = i + 1; j < tail->ways.size(); j++)
		{
			if (arr[i][j] == false)
			{
				int m = tail->ways[i].size() + tail->ways[j].size() - 2;
				if (m > max) max = m;
			}
		}
	}

	if (max == -1)
	{
		std::ofstream out("out.txt");
		out << "No solution";
		return 0;
	}



	std::ofstream out("out.txt");
	out << max;
	out.close();
}