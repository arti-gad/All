#include <iostream>
#include "swapcipher.h"
using namespace std;

void check(const string& Text, const int key)
{
 try {
        string cipherText;
        string decryptedText;
        SwapCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        decryptedText = cipher.decrypt(cipherText);
        cout<<"key="<<key<<endl;
        cout<<Text<<endl;
        cout<<cipherText<<endl;
        cout<<decryptedText<<endl;
    } 
    catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main(int argc, char **argv)   //BO UML\ UMBRELLO \Upgrade
{
 check("ВасекВЫШЕЛПОГУЛЯТЬ", -245);
 check("ВаськаВЫШЕЛПОГУЛЯТЬ", 23);
 check("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ", 0);
 check("123",5);
 check("ЁЖИКВЫШЕЛПОБЕГАТЬ",3); 
 return 0;
}
