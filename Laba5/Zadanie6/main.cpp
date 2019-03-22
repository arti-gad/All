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
	friend String operator+(const String&, const String&);
    //String operator+(const String& s);
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
    delete[] ret.value;
	ret.value = new char[len + 1];
	for (int i = 0; i < len; i++) {
		ret.value[i] = value[len - i - 1];
	}
	ret.value[len] = 0;
	return ret;
}

String operator+(const String& lhs, const String& rhs) //Почему для 2-х параметров не используется String::operator+ ???
{
	int i = 0, j = 0;
	String ts;
	ts.len = lhs.len + rhs.len;
	delete[] ts.value;
	ts.value = new char[ts.len + 1];
	for (i = 0; i < lhs.len; i++)
		ts.value[i] = lhs.value[i];
	for (j = 0; i <= ts.len; i++, j++)
		ts.value[i] = rhs.value[j];
	return ts;
}

/*String String::operator+(const String& s) // Оба оператора + работают, так в чем же отличие, и какой лучше использовать???
{
	int i = 0;
	String res;
	delete[] res.value;
	res.value = new char[this->len + s.len + 1];
	for (i = 0; i < this->len; i++)
		res.value[i] = this->value[i];
	res.len = i;
	for (i = 0; i < s.len; i++)
		res.value[res.len++] = s.value[i];
        res.value[res.len] = '\0';
	return res;
}*/

int main(int argc, char **argv) // Программа для работы с классом String
{
	String s;
	String s1;
	String s2;
    cin >> s;
    cin >> s1;
	s2 = s + s1;
	cout << s2 << endl;
	return 0;
}