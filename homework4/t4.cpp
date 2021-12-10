#include <iostream>
void flag(int n , int m)
{
	int* a;
	
	//a = (int*) std::malloc(n * m * sizeof(int));
	a = new int(n*m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			//std::cin >> *(a + i * m + j);
			std::cout << *(a + i * m + j);
		}
}