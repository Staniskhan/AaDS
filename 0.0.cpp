// The sum of keys in binary search tree

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main()
{
	ifstream in;
	in.open("input.txt");
	if (!in.is_open())
	{
		cout << "File did not open properly. Try again.";
		return 1;
	}

	int current;
	long long answer = 0;
	set<int> arr;
	while (in >> current)
	{
		arr.insert(current);
	}
	in.close();

	for (int i : arr)
	{
		answer += i;
	}

	cout << answer << '\n';
	ofstream out;
	out.open("output.txt");
	out << answer;
	out.close();
}