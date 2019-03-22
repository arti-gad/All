#include <iostream>
#define MAX 1000

using namespace std;

void normirovka(double a[], int len);

int main(int argc, char **argv)
{
    int n = 10;
    double a[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    normirovka(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    return 0;
}

void normirovka(double a[], int len)
{
    double max = a[0], min = a[0];
    for (int i = 0; i < len; i++) 
    {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    for (int j = 0; j <len; j++)
        a[j] = (a[j] - min)/(max - min);
}