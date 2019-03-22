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
	String& operator=(const String& other);
    String operator-() const;
};

ostream& operator<<(ostream& outputStream, const String & s)
{
	return outputStream << s.value;
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		delete[] value;
		len = other.len;
		value = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			value[i] = other.value[i];
		}
	}
	return *this;
}

String String::operator-() const
{
    String ret;
    ret.len = len;
    delete[] ret.value; // в примере не правильно, память выделили, а перед этим не освободили
    ret.value = new char[len+1];
    for (int i=0; i<len; i++) { 
        ret.value[i] = value[len-i-1];
    }
    ret.value[len] = 0;
    return ret;
}

int main(int argc, char **argv) // Программа для работы с классом String
{
	String s = "hello";
	String s1;
	String s2;
	String s3;
    String s4;
	s1 = s;
	cin >> s2;
	s3 = s2;
	cout << s1 << endl;
	cout << s3 << endl;
    s4 = -s3;
    cout << s4 << endl;
	return 0;
}