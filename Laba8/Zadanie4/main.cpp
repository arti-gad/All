#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <crypt.h>
#include <iomanip>
#include <fstream>
#include <mutex>
using namespace std;

bool thread_end = false;
void findPass(string pass, string pass2, const string& hash);

int main(int argc, char* argv[])
{
    thread th_1(findPass,"123456789", "231456789","$1$h7Skr0Vb$ipc8FG2QEWL88R6MIsJ/10");
    thread th_2(findPass,"231456789", "341256789", "$1$h7Skr0Vb$ipc8FG2QEWL88R6MIsJ/10");
    thread th_3(findPass,"341256789", "451236789", "$1$h7Skr0Vb$ipc8FG2QEWL88R6MIsJ/10");
    thread th_4(findPass,"451236789", "561234789", "$1$h7Skr0Vb$ipc8FG2QEWL88R6MIsJ/10");
    thread th_5(findPass,"561234789", "671234589", "$1$h7Skr0Vb$ipc8FG2QEWL88R6MIsJ/10");
    thread th_6(findPass,"671234589", "781234569", "$1$h7Skr0Vb$ipc8FG2QEWL88R6MIsJ/10");
    thread th_7(findPass,"781234569", "891234567", "$1$h7Skr0Vb$ipc8FG2QEWL88R6MIsJ/10");
    thread th_8(findPass,"891234567", "987654321", "$1$h7Skr0Vb$ipc8FG2QEWL88R6MIsJ/10");
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
void findPass(string pass1, string pass2, const string& hash)
{
    static mutex mtx;
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    do {
        if (thread_end == true) return;
        string newHash(crypt_r(pass1.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            thread_end = true;
            lock_guard<mutex> lock(mtx);
            cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass1<<endl;
            break;
        }
        if (pass1 == pass2) break;
    } while ( next_permutation( pass1.begin(), pass1.end() ) );
    delete pCryptData;
}