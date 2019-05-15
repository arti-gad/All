#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <crypt.h>
#include <iomanip>
#include <fstream>
using namespace std;

void findPass(string pass, const string& hash);

int main(int argc, char* argv[])
{
    int i = 0, j = 0, kol_vo = 0;
    ifstream f("/root/Laba8/Zadanie1/hashs");
	f.seekg(0, ios::end);
	int fsize = f.tellg();
	f.seekg(0, ios::beg);
	char *buf = new char [fsize];
	char *save = new char[60];
	f.read(buf, fsize);
	for (i = 0; i < fsize; i++)
	{
		if (buf[i] == '\n')
		{
            kol_vo++;
			save[j] = '\0';
            findPass("123456789", save);
			delete[] save;
			save = new char[60];
			j = 0;
		}
		else
		{
            if (kol_vo == 8) break;
			save[j] = buf[i];
			++j;
		}
	}
    cout << kol_vo;
    return 0;
}

void findPass(string pass, const string& hash)
{
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');

    string hashHead = hash.substr(0,pos);
    do {
        string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
            break;
        }
    } while ( next_permutation( pass.begin(), pass.end() ) );
    delete pCryptData;
}