#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	int i = 0, j = 0, count = 0;
	double sum = 0.0;
	ifstream f("/root/Laba6/Zadanie3/data_v1.txt");
	f.seekg(0, ios::end);
	int fsize = f.tellg();
	f.seekg(0, ios::beg);
	char *buf = new char [fsize];
	char *save = new char[100];
	f.read(buf, fsize);
	for (i = 0; i < fsize; i++)
	{
		if (buf[i] == '\n' || buf[i] == ' ' || buf[i] == '\t' || i == (fsize-1))
		{
			++count;
			save[j] = '\0';
			sum += atof(save);
			delete[] save;
			save = new char[100];
			j = 0;
		}
		else
		{
			save[j] = buf[i];
			++j;
		}
	}
	cout << sum/count << endl;
	delete[] buf;
	delete[] save;
	f.close();
	return 0;
}