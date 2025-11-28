#include <iostream>
#include <fstream>
#include <ctime>

int main()
{
	clock_t tStart = clock();
	for (unsigned long long i = 0; i < 1000000; i++)
	{
		i++;
		std::cout << i << '\n';
	}
	double time_spent = (double)(clock() - tStart) / CLOCKS_PER_SEC; // Вычисление потраченного времени

	std::cout << "Время выполнения: " << time_spent << " секунд" << std::endl;
}