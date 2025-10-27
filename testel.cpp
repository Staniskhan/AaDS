#include <iostream>
#include <fstream>

int main()
{
	std::ifstream in;
	in.open("input.txt");
	int i;
	int c = 0;
	while (in  >> i)
	{
		c++;
	}
	in.close();
	std::cout << c;
}