#include <iostream>
#include <string>
using namespace std;

template <typename T1, int ArrayLenght> class Array
{
	T1 massiv[ArrayLenght] = {}; // как бы и есть конструтор по умолчанию
public:
	Array() {};
	Array(const T1 ini)
	{
		for (int i = 0; i < ArrayLenght; i++)
			massiv[i] = ini;
	}
	Array(const T1 *mass, int size)
	{
        if (size == ArrayLenght)
        {
            for (int i = 0; i < size; i++)
            massiv[i] = mass[i];
        }
        else
            cout << "Ошибка!!! Массивы не одного размера" << endl;
    }
	T1 &operator[] (int index);
	T1 operator[](int index) const;
};

template <typename T1, int ArrayLenght> T1 &Array<T1, ArrayLenght>::operator[] (int index)
{
    if (index < 0 || index > ArrayLenght)
	{
		cout << "Ошибка! Выход за границу массива" << endl;
		exit(1);
	}
	return massiv[index];
}

template <typename T1, int ArrayLenght> T1 Array<T1, ArrayLenght>::operator[] (int index) const
{
    if (index < 0 || index > ArrayLenght)
	{
		cout << "Ошибка! Выход за границу массива" << endl;
		exit(1);
	}
	return massiv[index];
}

int main(int argc, char **argv)
{
	int mass[5] = { 1, 2, 3, 4, 5 };
	Array<int, 5> b(mass, 5);
	Array<int, 5> a(6);
	const Array<int, 3> c;
	cout << a[1] << endl;
	cout << b[3] << endl;
	b[3] = 10;
	cout << b[3] << endl;
	b[3] = c[1];
	cout << b[3] << endl;
    Array<string, 3> d("abc");
    cout << d[2] << endl;
    cout << c[2] << endl;
	return 0;
}
