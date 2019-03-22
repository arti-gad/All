#include <iostream>
using namespace std;

class String
{
    char * value;
    int len;
public:
    String():value(new char[1]{}),len(0){}; 
    String(const String& s)
    {
        len=s.len; 
        value = new char[len+1];
        for (int i=0; i<=len; i++)
            value[i]=s.value[i];        
    };
    ~String()
    {
         delete[] value;
    };

  friend ostream& operator<<(ostream& outputStream, const String & s);
};

 ostream& operator<<(ostream& outputStream, const String & s)
    {
        return outputStream << s.value;
    }  

int main(int argc, char **argv) // Программа для работы с классом String
{
    String s;
    String s1{};
    String s2 = s;
	return 0;
}
