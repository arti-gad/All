#include <iostream>
using namespace std;
// раскомментируй в зависимости от твеой группы
//#define PI1
//#define PT1
#define PT2
// вместо нуля поставь последние три цифры из номера зачетки
#define NUM 201
#define SIZE (NUM*100)
int main()
{
#if NUM==0
#error NUM not properly defined
#endif
#ifdef PI1
    typedef char T;
#elif defined PT1
    typedef int T;
#elif defined PT2
    typedef double T;
#else
#error Group not selected
#endif
    T * pT = new T [SIZE];
    T * pT2 = new T [100];
    pT[SIZE-1] = 65 + SIZE % 26;
    pT2[10] = 65 + NUM /10.0;
    cout<<pT[SIZE-1]<<endl; //Ошибка: не высводожденная память массва pT
    cout<<pT2[10]<<endl; //Ошибка: использование массива после его выкида из памяти
    delete[] pT2;
    delete[] pT;
    return 0;
}
