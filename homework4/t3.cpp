#include <cmath>
double getS_of_triangle(double a, double h)
{
	double s = 0.5 * a * h;
	return s;
}
long double getS_of_triangle(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	long double s = sqrt(p*(p - a)*(p - b)*(p - c));
	if (s >= 0)
		return s;
	else
		return 404;
}
double getS_of_square(double a, double b)
{
	double s = a * b;
	return s;
}
double getS_of_circle(double r)
{
	double p = 3.14;
	double s = p * pow(r, 2);
	return s;
}