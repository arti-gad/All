#include <iostream>
#include <locale>
using namespace std;

wstring encrypt(const wstring text, const int key);
wstring decrypt(const wstring text, const int key);

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring wshifr = L"языки программирования
    
    
    "; //Букву Ё данный алгоритм не обрабатывает
    wstring wshifr2 = L"", wdeshifr = L"", wdeshifr1 = L"";
    int key;
    wcout << L"Введите ключ:";
    cin >> key;
    for (wchar_t & wc: wshifr) {
        if ((wc >= L'а' && wc <= L'я') || (wc >= L'А' && wc <= L'Я')) {
            wc = toupper(wc,loc);
            wshifr2 += wc;
        }
    }
    for (int i = 0; i < wshifr2.length(); i++)
        if (wshifr2[i] >= L'А' && wshifr2[i] <= L'Я')
            continue;
        else
        {
            wcout << L"ОШИБКА\n";
            return 0; 
        }
    if (wshifr2 == L"") 
        {
            wcout << L"ОШИБКА\n";
            return 0; 
        }
    wcout << wshifr2 << endl;
    wdeshifr = encrypt(wshifr2, key); //Шифровка
    wcout << wdeshifr << endl;
    wdeshifr1 = decrypt(wdeshifr, key); // Дешифоровка
    wcout << wdeshifr1 << endl;
    return 0;
}

wstring encrypt(const wstring text, const int key)
{
    int key1, i;
    wstring text1 = text;
    wstring str;
    if (key > 32) key1 = key % 32;
    else key1 = key;
    for (wchar_t & wc: text1) {
        if ((wc + key1) > L'Я')
            str += wc + key1 - 32;
        else
            str += wc + key1;
    }
    return str;
}

wstring decrypt(const wstring text, const int key)
{
    int key1, i;
    wstring text1 = text;
    wstring str;
    wstring error = L"ОШИБКА";
    for (i = 0; i < text1.length(); i++)
        if (text1[i] >= L'А' && text1[i] <= L'Я')
            continue;
        else
            return error;
    if (key > 32) key1 = key % 32;
    else key1 = key;
    for (wchar_t & wc: text1) {
        if ((wc - key1) < L'А')
            str += wc - key1 + 32;
        else
            str += wc - key1;
    }
    return str;
}
