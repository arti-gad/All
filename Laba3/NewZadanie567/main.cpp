#include <iostream>
#define MAX 1000
using namespace std;

int bar(const char * s);
char* zashifrovka(const char * s, int key);
char* rasshifrovka(const char * s, int key);

int main(int argc, char **argv)
{
	char *str = new char[MAX];
	cin >> str;
	//char str[] = "ILOVEPROGRAMMIROVANIE"; //ILOVEPROGRAMMIROVANIE  HELLOWORLD
	char *ciphertext; // "матрица" Сциталла
	char *deciphertext;
	int strings = 0, symbols = 0, columns = 0; // кол-во строк
	cout << "Исходное сообщение для шифрования: " << endl;
	cout << str << endl;
	cout << "Введите ключ Скиталла: ";
	cin >> strings;
	symbols = bar(str);
	columns = ((symbols - 1) / strings) + 1; // вычислили кол-во столбцов
	if (((columns * strings) - symbols) == columns) // если получается одна лишняя строка 
	{
		--strings;
		columns = ((symbols - 1) / strings) + 1; // вычислили новое кол-во столбцов
	}
	for (int i = 0; i < symbols; i++)
		if (str[i] < 'A' || str[i] > 'Z')
		{
			cout << "Ошибка: не прописная буква\n";
			return 0;
		}
	if (strings <= 0 || strings >= (symbols / 2))
	{
		cout << "Ошибка: Неверный ключ. Ключ должен быть числом положительным и не превышающим половины длины текста\n";
		return 0;
	}
    ciphertext = zashifrovka(str, strings);
	deciphertext = rasshifrovka(ciphertext, columns);
	delete[] ciphertext;
	delete[] deciphertext;
    delete[] str;
	return 0;
}

int bar(const char * s)
{
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

char* zashifrovka(const char * s, int key)
{
	int i = 0, index = 0, columns = 0, symbols = 0, j = 0;
	char *ciphertext1 = new char[MAX];
	char *ciphertext2 = new char[MAX];
	symbols = bar(s);
	columns = ((symbols - 1) / key) + 1; // вычислили кол-во столбцов
	for (i = 0; i < symbols; i++) {
		index = key * (i % columns) + (i / columns);
		ciphertext1[index] = s[i];
	}
	ciphertext1[key*columns] = '\0';
	for (i = 0, j = 0; i < key*columns; i++)
		if (ciphertext1[i] < 'A' || ciphertext1[i] > 'Z')
			continue;
		else
			ciphertext2[j++] = ciphertext1[i];

	ciphertext2[j] = '\0';
	for (i = 0; i < symbols; i++)
		cout << ciphertext2[i];
	cout << endl;
    delete[] ciphertext1;
	return ciphertext2;
}

char* rasshifrovka(const char * s, int key)
{
	int i = 0, index, strings, symbols, j = 0;
	char *ciphertext1 = new char[MAX];
	symbols = bar(s);
	strings = ((symbols - 1) / key) + 1; // вычислили кол-во строк
	for (i = 0; i < key*strings; i++) {
		index = key * (i % strings) + (i / strings);
		if (index >= symbols)
			continue;
		else
			ciphertext1[index] = s[j++];
	}
	ciphertext1[j] = '\0';
	for (i = 0; i < symbols; i++)
		cout << ciphertext1[i];
	cout << endl;
	return ciphertext1;
}