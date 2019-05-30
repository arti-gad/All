#include <iostream>
#include <iomanip>
#include <fstream>
#include <codecvt>
#include <string>
using namespace std;
std::locale loc("ru_RU.UTF-8");
std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;

template <typename T> void bubblesort(T *mass, unsigned size);
void find_surname(string *mass, unsigned size);
void find_name(string *mass, int size);
int space(string s, int begin = 0);

int main(int argc, char **argv)
{
    int size = 0;
    int i = 0, j = 0;
    ifstream f("/root/Laba9/Zadanie6/data_v1");
    f.seekg(0, ios::end);
    int fsize = f.tellg();
    f.seekg(0, ios::beg);
    char *buf = new char [fsize];
    f.read(buf, fsize);
    for(i = 0; i < fsize; i++) {
        if (buf[i] == '\n')
            size++;
    }
    size++;
    //string s[1000];
    string *s = new string[size];
    for (i = 0; i < size - 1; i++) {
        while (buf[j] != '\n') {
            s[i] += buf[j];
            j++;
        }
        j++;
    }
    s[size - 1] = "";
    cout << "Список всех ФИО:" << endl;
    for (i = 0; i < size - 1; i++)
        cout << s[i] << endl;
    cout << endl;
    bubblesort(s, size-1);
    cout << "Отсортированнй список всех ФИО:" << endl;
    for (i = 0; i < size-1; i++)
        cout << s[i] << endl;
    cout << endl;
    cout << "Однофамильцы:" << endl;
    find_surname(s, size-1);
    cout << endl;
    find_name(s, size-1);
    delete[] buf;
    f.close();
    return 0;
}

template <typename T> void bubblesort(T *mass, unsigned size)
{
    unsigned i,j;
    bool swapped;
    for(i = 0; i < size-1; i++) {
        swapped = false;
        for(j = 0; j < size-i-1; j++) {
            if (mass[j] > mass[j + 1]) {
                T Temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = Temp;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void find_surname(string *mass, unsigned size)
{
    string surname1, surname2;
    int probel;
    unsigned i = 0, j = 0;
    for(i = 0; i < size; i++) {
        probel = space(mass[i]);
        surname1 = mass[i].substr(0,probel);
        for(j = i + 1; j < size; j++) {
            probel = space(mass[j]);
            surname2 = mass[j].substr(0,probel);
            if (surname1 == surname2) {
                cout << mass[i] << endl;
                cout << mass[j] << endl;
            }
        }
    }
}

int space(string s, int begin)
{
    int i = 0;
    std::wstring ws = codec.from_bytes(s);
    if (begin > 0) {
        begin++;
        i++;
    }
    while (s[begin] != L' ') {
        i++;
        begin++;
    }
    return i;
}

void find_name(string *mass, int size)
{
    string name1, name2;
    int probel1, probel2;
    int i = 0, j = 0, max = -1, min = size + 1;
    int name_count[4];
    for (i = 0; i < 4; i++)
        name_count[i] = 0;
    for (i = 0; i < size; i++) {
        probel1 = space(mass[i]);
        probel2 = space(mass[i], probel1);
        name1 = mass[i].substr(probel1, probel2);
        for (j = 0; j < size; j++) {
            probel1 = space(mass[j]);
            probel2 = space(mass[j], probel1);
            name2 = mass[j].substr(probel1, probel2);
            if (mass[i] == mass[j])
                continue;
            else if (name1 == name2) {
                name_count[i]++;
            }
        }
    }
    for (i = 0; i < size; i++) {
        if (name_count[i] > max)
            max = name_count[i];
        else if (name_count[i] < min)
            min = name_count[i];
    }
    //max
    name1 = "";
    name2 = "";
    cout << "Самые популярные имена:" << endl;
    for (i = 0; i < size; i++) {
        if (name_count[i] == max) {
            probel1 = space(mass[i]);
            probel2 = space(mass[i], probel1);
            name1 = mass[i].substr(probel1 + 1, probel2);
            if (name1 == name2)
                continue;
            cout << name1 << endl;
            name2 = name1;
        }
    }
    //min
    name1 = "";
    name2 = "";
    cout << "Самые редкие имена:" << endl;
    for (i = 0; i < size; i++) {
        if (name_count[i] == min) {
            probel1 = space(mass[i]);
            probel2 = space(mass[i], probel1);
            name1 = mass[i].substr(probel1 + 1, probel2);
            if (name1 == name2)
                continue;
            cout << name1 << endl;
            name2 = name1;
        }
    }
}
