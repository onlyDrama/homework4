#include <iostream>
unsigned int print_random(int m, int i, int c)
{
	static unsigned int s = 0;
	return s = (m * s + i) % c;
}