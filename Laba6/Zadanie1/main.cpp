#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{
	int chislo[10], i;
    for (i = 0; i < 10; i++)
    {
        cin >> chislo[i];
    }
    for (i = 0; i < 10; i++)
    {
        cout << setw(7) << oct << chislo[i] << setw(7);
        cout << setw(7) << dec << chislo[i] << setw(7);
        cout << setw(7) << hex << chislo[i] << endl;
    }
	return 0;
}