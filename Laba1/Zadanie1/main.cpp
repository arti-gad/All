#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    char* path = new char[PATH_MAX];
    const char* id[] = { "Фамилия\t\t", "Имя\t\t", "Отчество\t", "Группа\t\t" };
    realpath(argv[0], path);
    cout << "Путь к исполняемому файлу: ";
    cout << path << endl;
    delete[] path;
    for(int i = 1; i < argc; ++i) 
    {
        if(i - 1 < 4) cout << id[i - 1];
        cout << string(argv[i]) << endl;
    }
    cout << "Количество аргументов программы: " << argc << endl;
    return 0;
}