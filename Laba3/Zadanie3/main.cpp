#include <iostream>
#define MAX 1000

using namespace std;

double* normirovka(double *a, int len);

int main(int argc, char **argv)
{
    int n = 3;
    double *a = new double[MAX];
    double *b;
    cout << "Введите массив для нормировки значений(вводить по 1 значению в строке):\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cout << &a[i] << endl;
    }
    
    b = normirovka(a, n);
    cout <<"a= " << a << endl;
    cout <<"b= " << b << endl;
    cout << "Нормированный массив:\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << endl;
        cout << &b[i] << endl; // адреса у при выводе будут разные, что соответствует заданию: нормированный значения помещались в новый массив.
    }
    delete [] a;
    return 0;
}

double* normirovka(double* a, int len) // функция возвращает указатель на массив double, что тоже соответствует заданию.
{
    double *c = new double[MAX];
    double max = a[0], min = a[0];
    for (int i = 0; i < len; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    for (int j = 0; j < len; j++)
        c[j] = (a[j] - min) / (max - min);
    cout <<"c= " << c << endl;
    return c;
}