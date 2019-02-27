#include <iostream>
using namespace std;

double power(double a);

int main(int argc, char **argv)
{
    double x,y;
    cin >> x;
    cin >> y;
    if (x < -0.4 && (power(x) + power(y) < 1))
        cout << "Точка принадлежит области\n";
        else if (x > -0.4 && (power(x) + power(y) > 1))
             cout << "Точка не принадлежит области\n";
        else  cout << "Точка лежит на границе\n";
	return 0;
}

double power(double a)
{
    return a*a;
}