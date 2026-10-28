#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

void Create(double* a, const int size, const double Low, const double High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() * (High - Low) / RAND_MAX;
}

void Print(double* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(8) << fixed << setprecision(2) << a[i];
	cout << endl;
}

int CountInRange(double* a, const int size, const double A, const double B)
{
	int k = 0;
	for (int i = 0; i < size; i++)
		if (a[i] >= A && a[i] <= B)
			k++;
	return k;
}

int IndexOfMax(double* a, const int size)
{
	int imax = 0;
	for (int i = 1; i < size; i++)
		if (a[i] > a[imax])
			imax = i;
	return imax;
}

double SumAfterMax(double* a, const int size, const int k)
{
	double S = 0;
	for (int i = k + 1; i < size; i++)
		S += a[i];
	return S;
}

void Sort(double* a, const int size)
{
	for (int i = 0; i < size - 2; i += 2)
	{
		int imax = i;

		for (int j = i + 2; j < size; j += 2)

			if (fabs(a[j]) > fabs(a[imax]))
				imax = j;
		double tmp = a[i];
		a[i] = a[imax];
		a[imax] = tmp;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int n;
	double A, B;
	cout << "n = "; cin >> n;
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;

	double* a = new double[n];

	double Low = -10;
	double High = 10;

	Create(a, n, Low, High);
	Print(a, n);

	cout << "count in [A;B] = " << CountInRange(a, n, A, B) << endl;
	cout << "sum after max = " << SumAfterMax(a, n, IndexOfMax(a, n)) << endl;

	Sort(a, n);
	Print(a, n);

	delete[] a;

	return 0;
}