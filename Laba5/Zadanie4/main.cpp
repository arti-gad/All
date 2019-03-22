#include <iostream>
using namespace std;

class String
{
	char * value;
	int len;
public:
	String() :value(new char[1]{}), len(0) {};
	String(const String& s)
	{
		len = s.len;
		value = new char[len + 1];
		for (int i = 0; i <= len; i++)
			value[i] = s.value[i];
	};
	String(const char * s)
	{
		len = 0;
		while (s[len] != '\0') ++len;
		value = new char[len + 1];
		for (int i = 0; i <= len; i++)
			value[i] = s[i];
	};
	~String()
	{
		delete[] value;
	};

	friend ostream& operator<<(ostream& outputStream, const String & s);
    friend istream &operator >> (istream &is, String &obj) 
    {
		int ios_size = 0, i = 0;
		char v[2048];
		while (is.peek() != '\n') 
			v[ios_size++] = (char)is.get();
		v[ios_size] = '\0';
		is.ignore();
		delete[] obj.value;
		obj.value = new char[ios_size + 1];
		for (i = 0; i <= ios_size; i++)
			obj.value[i] = v[i];
		obj.len = ios_size;
		return is;
    }
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
	String s3("hello");
	String s4 = "Hello";
    String s5;
	cout << s2;
	cout << s3 << " " << s4 << endl;
    cin >> s5;
    cout << s5 << endl;
    cin >> s4;
    cout << s4 << endl;
	return 0;
}