#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("/root/Laba6/Zadanie3/data_v1.bin", ios::binary);
    ofstream f2("/root/Laba6/Zadanie3/data_v2.bin", ios::binary);
    f.seekg(0, ios::end);
	const int fsize = f.tellg();
	f.seekg(0, ios::beg);
	double *buf = new double[fsize/8];
	float *buf2 = new float[fsize/8];
	f.read((char*)buf, fsize);
    int i = 0;
    
    for (i = 0; i < fsize/8; i++)
	cout << (double)buf[i] << endl;
    cout << endl;
	for (i = 0; i < fsize/8; i++)
	{
		buf2[i] = 1/(buf[i]);
        cout << buf2[i]<< hex << endl;
	}
    
	f2.write((char*)buf2, (fsize/8)*4);
    f.close();
    f2.close();
    delete[] buf;
    delete[] buf2;
	return 0;
}