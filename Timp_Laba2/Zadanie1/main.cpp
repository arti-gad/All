#include <iostream>
#include <string>
#include "modAlphaCipher.h"
using namespace std;

void check(const string& Text, const string& key, const bool destructCipherText=false)
{
    try {
        string cipherText;
        string decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            //cipherText.front() = tolower(cipherText.front());
            cipherText = "портим";
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
    check("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ","Вася");
    check("СОБАКАВЫШЛАПОГУЛЯТЬ","");
    check("ЁЖИКВЫШЕЛПОБЕГАТЬ","ЁМАЕ123");
    check("Это проверочный текст который будет работать","СУПЕР");
    check("123","АБВГ");
    check("Этопроверочныйтексткоторыйнебудетработать", "СВЕРХСЕКРЕТНО", true);
    return 0;
}
