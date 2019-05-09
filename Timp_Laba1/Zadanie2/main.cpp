#include <iostream>
#include "swapcipher.h"
using namespace std;

void check(const string& Text, const int key)
{
 string cipherText;
 string decryptedText;
 SwapCipher cipher(key);
 cipherText = cipher.encrypt(Text);
 decryptedText = cipher.decrypt(cipherText);
 cout<<"key="<<key<<endl;
 cout<<Text<<endl;
 cout<<cipherText<<endl;
 cout<<decryptedText<<endl;
 if (Text == decryptedText)
 cout<<"Ok\n";
 else
 cout<<"Err\n";
}
int main(int argc, char **argv)   //BO UML\ UMBRELLO \Upgrade
{
 check("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ",4);
 check("СОБАКАВЫШЛАПОГУЛЯТЬ",5);
 check("ЁЖИКВЫШЕЛПОБЕГАТЬ",3); // ЁЖИ КВЫ ШЕЛ ПОБ ЕГА ТЬ
 return 0;
}
