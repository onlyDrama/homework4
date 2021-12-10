
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include "t1.h"
#include "t2.h"
#include "t3.h"
#include "t4.h"
#include "t6.h"
#include "fake_random_t7.h"
#include "t8.h"

#define graphic(x) (sin(x)) //график который будет строится

using namespace std;
using namespace Roman;

void fillArr(int n, int* const arr);
void print_gr();
unsigned int PRNG();


int main()
{
	setlocale(LC_ALL, "ru");
	int w = 1;
	while (w)
	{
		cin >> w;
		if (w == 1) {
			int n;
			cout << "Enter amount of elements ";
			cin >> n;
			cout << endl;
			int* arr = new int[n];

			fillArr(n, arr);
			addNums_to_file(n, arr);
			getSum_from_file();
			cout << endl;
			delete[] arr;
		}
		if(w == 2)
		{
			cout << "Enter x ";
			int x;
			cin >> x;
			cout << signX(x);
			cout << endl;
		}
		if (w == 3)
		{
			int x, var = 10;
			cout << "Choose th tesk 1, 2, 3\n";
			while (var)
			{
				cin >> var;
				if (var == 1) {
					cout << "Choose the way 1 - common or 2 - Heron 's Formula\n";
					cin >> x;
					if (x == 1)
					{
						double a, h;
						cout << "Enter a, h \n";
						cin >> a >> h;
						cout << "\n";
						cout << "S of Triangle ";
						cout << getS_of_triangle(a, h);
						cout << "\n";
					}
					if (x == 2)
					{
						double a, b, c;
						cout << "Enter a, b, c \n";
						cin >> a >> b >> c;
						cout << "\n";
						cout << "S of Triangle ";
						cout << getS_of_triangle(a, b, c);
						cout << "\n";
					}
				}
				if (var == 2)
				{
					double a, b;
					cout << "Enter a and b \n";
					cin >> a >> b;
					cout << "\nS of square";
					cout<<getS_of_square(a, b);
					cout << "\n";
				}
				if (var == 3)
				{
					double r;
					cout << "Enter r ";
					cin >> r;
					cout << "\nS of circle ";
					cout<<getS_of_circle(r);
					cout << "\n";
				}
			}
		}
		if (w == 4)
		{
			cout << "Былую славу 1912 года\n";

		}
		if (w == 5)
		{
			print_gr();
		}
		if (w == 6)
		{
			string number;
			cin >> number;
			try
			{
				cout << number << " = " << Roman::ToInt(number) << "\n";
			}
			catch (exception& e)
			{
				cerr << e.what();
				cout << "\nERROR\n";
			}
		}
		if (w == 7)
		{
			int count_of_el, m, i, c;
			cin >> count_of_el >> m >> i >> c;
			
			for (int j = 0; j < count_of_el; j++)
			{
				cout << PRNG() << " ";
				
			}
			cout << endl;
			for (int j = 0; j < count_of_el; j++)
			{
				cout << print_random(m, i, c) << " ";
			}
		}
		if (w == 8)
		{
			
			matrix();
			cout << "Больше всего денег выручил продавец " << gain(1) << endl;
			cout << "Меньше всего денег выручил продавец " << gain(0) << endl;
			cout << endl;
			cout << "Наибольшие комиссионные получил продавец " << comm(1) << endl;
			cout << "Наименьшие комиссионные получил продавец " << comm(0) << endl;
			cout << endl;
			cout << "Общая сумма вырученных денег: " << msumm() << endl;
			cout << "Общая сумма комиссионных: " << csumm() << endl;
			cout << "Через руки продавцов прошло: " << msumm() + csumm() << endl;
		}
	}

	return 0;
}


void fillArr(int n, int* const arr)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}


void print_gr()
{
	float x;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(241, 249, 8));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 0, 85, NULL);
	LineTo(hDC, 200, 85);
	MoveToEx(hDC, 100, 0, NULL);
	LineTo(hDC, 100, 170);
	for (x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - center
	{
		MoveToEx(hDC, 10 * x + 100, -10 * graphic(x) + 85, NULL);//10 - scale
		LineTo(hDC, 10 * x + 100, -10 * graphic(x) + 85);
	}
	std::cout << "\n\n\n\n\n\n";
}


unsigned int PRNG()
{
	// Наше стартовое число - 4 541
	static unsigned int seed = 4541;

	// Берем стартовое число и, с его помощью, генерируем новое значение.
	// Из-за использования очень больших чисел (и переполнения) угадать следующее число исходя из предыдущего - очень сложно
	seed = (8253729 * seed + 2396403);

	// Берем стартовое число и возвращаем значение в диапазоне от 0 до 32767
	return seed % 32768;
}