#include <iostream>
#include <ctime>
using namespace std;

void get_time(tm * ptm);

int main(int argc, char **argv)
{

    time_t t = time(NULL);
    tm * ptm;
    ptm = localtime(&t);
    get_time(ptm);
    return 0;
}

void get_time(tm * ptm)
{
    string s;
    switch (ptm->tm_wday) {
    case 0:
        s += "Воскресенье";
        break;
    case 1:
        s += "Понедельник";
        break;
    case 2:
        s += "Вторник";
        break;
    case 3:
        s += "Среда";
        break;
    case 4:
        s += "Четверг";
        break;
    case 5:
        s += "Пятница";
        break;
    case 6:
        s += "Суббота";
        break;
    }

    switch (ptm->tm_mon) {
    case 0:
        s += " Январь";
        break;
    case 1:
        s += " Февраль";
        break;
    case 2:
        s += " Март";
        break;
    case 3:
        s += " Апрель";
        break;
    case 4:
        s += " Май";
        break;
    case 5:
        s += " Июнь";
        break;
    case 6:
        s += " Июль";
        break;
    case 7:
        s += " Август";
        break;
    case 8:
        s += " Сентябрь";
        break;
    case 9:
        s += " Октябрь";
        break;
    case 10:
        s += " Ноябрь";
        break;
    case 11:
        s += " Декабрь";
        break;
    }
    cout << s << " " << ptm->tm_mday << " " << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec << " " << ptm->tm_year+1900 << endl;
}
