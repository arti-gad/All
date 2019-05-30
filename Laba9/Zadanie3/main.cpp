#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

int RandomGenerator()
{
    static mt19937 rnd((uint64_t)&rnd);
    uniform_int_distribution<int> d(-1000000000, 1000000000);
    return d(rnd);
}

int main()
{
    random_device rd;
    vector<int> v;
    mt19937 rnd(-1000000000);
    steady_clock::time_point tp1 = steady_clock::now();
    for (int i=0; i < 10000000; i++)
        v.push_back(rnd());
    steady_clock::time_point tp2 = steady_clock::now();
    duration<double> d = tp2 - tp1;
    cout << "Время для первого ветора: " << d.count() << " c." << endl;
    vector<int> v1(10000000);
    tp1 = steady_clock::now();
    generate(v1.begin(),v1.end(),RandomGenerator);
    tp2 = steady_clock::now();
    d = tp2 - tp1;
    cout << "Время для второго ветора: " << d.count() << " c." << endl;
    tp1 = steady_clock::now();
    vector<int> v2(v1);
    tp2 = steady_clock::now();
    cout << "Время для третьего ветора: " << d.count() << " c." << endl;
}
