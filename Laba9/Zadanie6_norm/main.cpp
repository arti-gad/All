#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void bubblesort(vector<string>& mass, unsigned size);
void find_surname(vector<string>& mass, unsigned size);
void find_name(vector<string>& mass, int size);
int space(string s, unsigned begin = 0);

int main(int argc, char **argv)
{
    unsigned i = 0;
    ifstream f("/root/Laba9/Zadanie6/data_v1");
    vector<string> s;
    string line;
    while (getline(f, line)) {
        if (line != "" || line != " " || line != "\n")
            s.push_back(line);
    }
    cout << "Список всех ФИО:" << endl;
    for (i = 0; i < s.size(); i++)
        cout << s[i] << endl;
    cout << endl;
    bubblesort(s, s.size());
    cout << "Отсортированнй список всех ФИО:" << endl;
    for (i = 0; i < s.size(); i++)
        cout << s[i] << endl;
    cout << endl;
    cout << "Однофамильцы:" << endl;
    find_surname(s, s.size());
    cout << endl;
    find_name(s, s.size());
    f.close();
    return 0;
}

void bubblesort(vector<string>& mass, unsigned size)
{
    unsigned i,j;
    bool swapped;
    for(i = 0; i < size-1; i++) {
        swapped = false;
        for(j = 0; j < size-i-1; j++) {
            if (mass[j] > mass[j + 1]) {
                string Temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = Temp;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void find_surname(vector<string>& mass, unsigned size)
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

int space(string s, unsigned begin)
{
    int i = 0;
    if (begin > 0) {
        begin++;
        i++;
    }
    while (s[begin] != ' ') {
        i++;
        begin++;
    }
    return i;
}

void find_name(vector<string>& mass, int size)
{
    string name1, name2;
    int probel1, probel2;
    int i = 0, j = 0, max = -1, min = size + 1;
    int name_count[size];
    for (i = 0; i < size; i++)
        name_count[i] = 0;
    for (i = 0; i < size; i++) {
        probel1 = space(mass[i]);
        probel2 = space(mass[i], probel1);
        name1 = mass[i].substr(probel1, probel2);
        for (j = 0; j < size; j++) {
            probel1 = space(mass[j]);
            probel2 = space(mass[j], probel1);
            name2 = mass[j].substr(probel1, probel2);
            if ((mass[i] != mass[j]) && (name1 == name2))
                name_count[i]++;
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
