#include <iostream>
#include <iomanip>
#define N 10
using namespace std;

template <typename T> void massivprint(T *mass, int b);
template <typename T> void mergesort(T *mass, unsigned size);
template <typename T> void swap(T *pa, T *pb);
template <typename T> void mergelist(T *mass, unsigned length1, unsigned length2);
template <typename T> void rightshiftcycle(T *mass, unsigned left, unsigned right);
template <typename T> void rightshift(T *mass, unsigned left, unsigned right);

int main(int argc, char **argv)
{
	// int массив
	int massiv[N] = { 74, 56, 81, 19, 63, 9, 237, 34, 7, 47 };
	massivprint(massiv, N);
	mergesort(massiv, N);
	massivprint(massiv, N);
	cout << endl;
	// double массив
	double massiv1[N] = { 56.3554, 78.345354, 2.82222, 19.3425, 65.0, 9.34522, 456.89422, 56.78922, 8.4, 47.45 };
	massivprint(massiv1, N);
	mergesort(massiv1, N);
	massivprint(massiv1, N);
	cout << endl;
	// float массив
	float massiv2[11] = {344.0967, 65.76, 66.345, 8.645, 7.6, 344.658, 45.876, 1.2345, 78.353, 98.04, 44.44};
	massivprint(massiv2, 11);
	mergesort(massiv2, 11);
	massivprint(massiv2, 11);
	cout << endl;
	// char массив
	char massiv3[N] = {'w','z', 'u', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
	massivprint(massiv3, N);
	mergesort(massiv3, N);
	massivprint(massiv3, N);
	cout << endl;
	return 0;
}

template <typename T> void massivprint(T *mass, int b)
{
	for (int i = 0; i < b; i++)
	{
		cout << "  " << mass[i];
	}
	cout << endl;
}

template <typename T> void swap(T *pa, T *pb)
{
	T temp = *pa;
	*pa = *pb;
	*pb = temp;
}

template <typename T> void mergesort(T *mass, unsigned size)
{
	if (size <= 1)
		return;
	else if (size == 2)
	{
		if (mass[0] > mass[1])
		{
			swap(mass, mass + 1);
			return;
		}
	}
	else
	{
		int length1 = (size - 1) / 2 + 1;
		int length2 = size - length1;
		mergesort(mass, length1);
		mergesort(mass + length1, length2);
		mergelist(mass, length1, length2);
	}
}

template <typename T> void mergelist(T *mass, unsigned length1, unsigned length2)
{
	unsigned i1 = 0, i2 = length1;
	while (i1 < i2 && i2 < (length1 + length2))
	{
		if (mass[i1] <= mass[i2])
			i1++;
		else
		{
			rightshiftcycle(mass, i1, i2);
			i1++;
			i2++;
		}
	}
}

template <typename T> void rightshiftcycle(T *mass, unsigned left, unsigned right)
{
	T d = mass[right];
	rightshift(mass, left, right);
	mass[left] = d;
}

template <typename T> void rightshift(T *mass, unsigned left, unsigned right)
{
	for (unsigned i = right; i > left; i--)
		mass[i] = mass[i - 1];
}