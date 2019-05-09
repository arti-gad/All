#include <iostream>
#include <iomanip>
using namespace std;
 
void table_ymoz(int cc);
 
int main()
{
    int cc;
    cout << "Введите основание таблицы усмножения: ";
    cin >> cc;
    table_ymoz(cc);
    return 0;
}

void table_ymoz(int cc)
{
    int i = 0, j = 0;

  if (cc == 10 || cc == 8 || cc == 16)
   {
    cout << "ТАБЛИЦА УМНОЖЕНИЯ ДЛЯ СИСТЕМЫ С ОСНОВАНИЕМ " << cc << ":"<< endl;
    for(i = 1; i <= 10; i++)
    {
        for(j = 2; j <= 9; j++) 
        {
            switch(cc) 
            {
                case 8:  cout << oct << setw(5) << j << setw(1) << " * " << setw(2) << left << i << setw(2) << right << "=" << setw(4) << j*i; break;
                case 10: cout << dec << setw(5) << j << setw(1) << " * " << setw(2) << left << i << setw(2) << right << "=" << setw(3) << j*i; break;
                case 16: cout << hex << setw(5) << j << setw(1) << " * " << setw(2) << left << i << setw(2) << right << "=" << setw(3) << j*i; break;
            }
        }
    cout << endl;
    }
   }
    else  cout << "Ошибка. Данное основание не поддерживается!!!"<< endl;
}