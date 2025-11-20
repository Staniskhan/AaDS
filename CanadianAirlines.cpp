#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct city
{
	std::string name;
	char connection;
	int length;
	std::vector<city*> prevCities;
	city* maxAdress;
	city* next;
	city* prev;
};

int main()
{
	int n, m;
	std::ifstream in("in.txt");
	in >> n >> m;

	city* head;

	//заполнение городов
	head = new city();
	in >> head->name;
	head->connection = 'y';
	head->length = 0;
	city* curr = head;
	head->prev = NULL;
	for (short i = 1; i < n; i++)
	{
		curr->next = new city();
		curr->next->prev = curr;

		in >> curr->next->name;
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


	//просчет путей и длины максимального пути
	curr = head->next;
	while(curr != NULL)
	{
		curr->length = -1;
		for (short j = 0; j < curr->prevCities.size(); j++)
		{
			if (curr->prevCities[j]->connection == 'y')
			{
				if (curr->prevCities[j]->length > curr->length)
				{
					curr->connection = 'y';
					curr->length = curr->prevCities[j]->length;
					curr->maxAdress = curr->prevCities[j];
				}
			}
		}
		if (curr->length != -1)
		{
			curr->length++;
		}
		curr = curr->next;
	}

	

	if (tail->connection == 'n')
	{
		std::ofstream out("out.txt");
		out << "No solution";
		return 0;
	}


	int mem = tail->length;

	//удаление пройденных городов
	curr = tail->maxAdress;
	for (short i = 0; i < tail->prevCities.size(); i++)
	{
		if (tail->prevCities[i]->name == tail->maxAdress->name && tail->prevCities[i] != head)
		{
			tail->prevCities.erase(tail->prevCities.begin() + i);
		}
	}
	while (curr != head)
	{
		for (short i = 0; i < curr->prevCities.size(); i++)
		{
			//if (curr->prevCities[i]->name == curr->maxAdress->name)
			//{
			//	curr->prevCities.erase(curr->prevCities.begin() + i);
			//}
			curr->prevCities.erase(curr->prevCities.begin() + i);
		}
		curr->connection = 'n';
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		curr = curr->maxAdress;
	}

	curr = head->next;
	head->connection = 'y';
	head->length = 0;
	head->prev = NULL;
	while (curr != NULL)
	{
		curr->length = -1;
		curr->connection = 'n';
		for (short j = 0; j < curr->prevCities.size(); j++)
		{
			if (curr->prevCities[j]->connection == 'y')
			{
				if (curr->prevCities[j]->length > curr->length)
				{
					curr->connection = 'y';
					curr->length = curr->prevCities[j]->length;
					curr->maxAdress = curr->prevCities[j];
				}
			}
		}
		if (curr->length != -1)
		{
			curr->length++;
		}
		curr = curr->next;
	}

	if (tail->connection == 'n')
	{
		std::ofstream out("out.txt");
		out << "No solution";
		return 0;
	}

	mem += tail->length;

	std::ofstream out("out.txt");
	out << mem;
	out.close();
}