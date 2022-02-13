#include <iostream>
#include"list.h"
#include"Queu.h"

int main()
{
	queue<double> a;

	for (size_t i = 0; i < 5; ++i)
	{
		a.push_back(i);
	}
	size_t size = a.get_size();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << a.front();
		a.pop_front();
	}

	a.pop_front();
	return 0;
}