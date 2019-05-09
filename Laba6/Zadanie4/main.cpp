#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("/root/Laba6/Zadanie3/data_v1.txt");
    ofstream f2("/root/Laba6/Zadanie3/data_v2.txt", ios::app); // открываем файл для записи в конец
    f.seekg(0, ios::end);
	int fsize = f.tellg();
	f.seekg(0, ios::beg);
	char *buf = new char [fsize];
    f.read(buf, fsize);
    f2.write((char*)buf, fsize);
    delete[] buf;
	f.close();
    f2.close();
	return 0;
}