#include <iostream>
#include <string>
using namespace std;

int main()
{
	int number_of_the_water_lily = 0;

	cin >> number_of_the_water_lily;
	if (number_of_the_water_lily < 3)
	{
		cout << -1;
		return 0;
	}
	else if (number_of_the_water_lily == 3)
	{
		int mosquitoes = 0, sum = 0;
		cin >> sum;
		cin >> mosquitoes;
		cin >> mosquitoes;
		sum += mosquitoes;
		cout << sum << endl << 1 << ' ' << 3;
		return 0;
	}


	int memory[4];
	int* way = new int[number_of_the_water_lily - 2];

	way[0] = 1;
	way[1] = 1;
	cin >> memory[0];
	cin >> memory[1];
	memory[1] = -1;
	cin >> memory[2];
	memory[2] += memory[0];
	cin >> memory[3];
	memory[3] += memory[0];

	for (int i = 4; i < number_of_the_water_lily; i++)
	{
		memory[0] = memory[1];
		memory[1] = memory[2];
		memory[2] = memory[3];
		cin >> memory[3];
		memory[3] += (memory[0] > memory[1]) ? memory[0] : memory[1];
		way[i-2] = (memory[0] > memory[1]) ? (i - 2) : (i - 1);
	}
	
	cout << memory[3] << endl;
	int i = number_of_the_water_lily;
	int *ans = new int[(number_of_the_water_lily - 1) / 2];
	int j = 0;
	while (i > 2)
	{
		ans[j] = i;
		j++;
		i = way[i - 3];
	}
	ans[j] = i;

	cout << ans[j];
	j--;

	for (; j >= 0; j--)
	{
		cout << ' ' << ans[j];
	}
}