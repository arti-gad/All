#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <crypt.h>
#include <iomanip>
#include <fstream>
#include <mutex>
using namespace std;

void findPass(string pass, const string& hash);

int main(int argc, char* argv[])
{
    thread th_1(findPass,"123456789","$1$29fvMdvx$LL.QZs7G3S4Q5ea6.idf11");
    thread th_2(findPass,"123456789","$1$37Xhu8sp$jz8AjdBHcqvegV9.PLptt/");
    thread th_3(findPass,"123456789","$1$Es9HY7VR$4/WpkGDwKh.wbANw9qZZB0");
    thread th_4(findPass,"123456789","$1$8zbHAF40$VA3.qax9.4qiFZPrvbSA9.");
    thread th_5(findPass,"123456789","$1$Bq9uCg8i$5mJ9mGuEzv6TFf4RdCj5u0");
    thread th_6(findPass,"123456789","$1$Ok4ymcZA$1jL784kXhgSzhxR2LPw1J/");
    thread th_7(findPass,"123456789","$1$Po6qfV6m$e17w/5oU2s3jXE8LvXkMB/");
    thread th_8(findPass,"123456789","$1$c2O9StK1$Kqkydq/gxolY/dX90Y6Rw/");
    th_1.join();
    th_2.join();
    th_3.join();
    th_4.join();
    th_5.join();
    th_6.join();
    th_7.join();
    th_8.join();
    return 0;
}

void findPass(string pass, const string& hash)
{
    static mutex mtx;
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    do {
        string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            lock_guard<mutex> lock(mtx);
            cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
            break;
        }
    } while ( next_permutation( pass.begin(), pass.end() ) );
    delete pCryptData;
}