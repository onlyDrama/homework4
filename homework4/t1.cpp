#include <fstream>
#include <iostream>
void addNums_to_file(int n, int* const arr)
{
	std::ofstream fout("D:\\file1\\t.txt");
	if (!fout.is_open())
	{
		std::cout << 404;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fout << arr[i] << std::endl;
		}
	}
	fout.close();

}

void getSum_from_file()
{
	std::ifstream fin("D:\\file1\\t.txt");
	if (fin.is_open())
	{
		int a, sum = 0;

		while (fin >> a)
		{
			sum += a;
		}
		std::cout << "sum=" << sum << "\n";
	}
	
	fin.close();


}