#include <iostream>
#include "modAlphaCipher.h"
using namespace std;

void check(const string& Text, const string& key)
{
 string cipherText;
 string decryptedText;
 modAlphaCipher cipher(key);
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
 check("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ","ВАСЯ");
 check("СОБАКАВЫШЛАПОГУЛЯТЬ","ШАРИК");
 check("ЁЖИКВЫШЕЛПОБЕГАТЬ","ЁМАЕ");
 return 0;
}
