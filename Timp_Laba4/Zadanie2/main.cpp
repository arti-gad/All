/** @file
 * @author Григорьев А.Д.
 * @version 1.0
 * @date 09.06.2019
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 * @brief Главный файл для модуля swapcipher
 */
#include <iostream>
#include "swapcipher.h"
using namespace std;

void check(const string& Text, const int key, const bool destructCipherText=false)
{
 try {
        string cipherText;
        string decryptedText;
        SwapCipher cipher(key);
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
 check("ВасекВЫШЕЛПОГУЛЯТЬ", -245);
 check("ВАСЬКАВЫШЕЛПОГУЛЯТЬ", 5);
 check("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ", 5);
 check("123",5);
 check("ЁЖИКВЫШЕЛПОБЕГАТЬ", 3, true); 
 return 0;
}
