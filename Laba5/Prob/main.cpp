#include <iostream> 
using namespace std;

int main()
{
	char *v = new char[10];
	for (int i = 0; i < 10; i++)
		v[i] = 'a';
	for (int i = 0; i < 10; i++)
		cout << v[i] << endl;
    delete[] v;
	v = new char[11];
	for (int i = 0; i < 11; i++)
		v[i] = 'b';
	for (int i = 0; i < 11; i++)
		cout << v[i] << endl;
    delete[] v;
	return 0;
}