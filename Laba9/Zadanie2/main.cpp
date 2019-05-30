#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

int RandomGenerator()
{
    static mt19937 rnd((uint64_t)&rnd);
    uniform_int_distribution<int> d(-1000000000, 1000000000);
    return d(rnd);
}

int main()
{
    vector<int> v;
    mt19937 rnd(-1000000000);
    for (int i=0; i < 10000000; i++)
        v.push_back(rnd());
    vector<int> v1(10000000);
    generate(v1.begin(),v1.end(),RandomGenerator);
    vector<int> v2(v1);
    for(auto e:v2)
        cout<<e<<'\t';
    cout<<endl;
}
