#include <iostream>
using namespace std;

template <typename T1, typename T2> class DoubleBox
{
    T1 data1;
    T2 data2;
public:
    DoubleBox(): data1(0), data2(0){};
    DoubleBox(const T1 value1, const T2 value2):data1(value1), data2(value2) {};
    T1 get1() const;
    T2 get2() const;
    void get() const;
    void set(const T1 value1, const T2 value2);
};

template <typename T1, typename T2> void DoubleBox<T1, T2>::get() const
{
	cout << data1 << endl << data2 << endl;
}

template <typename T1, typename T2> T1 DoubleBox<T1, T2>::get1() const
{
    return data1;
}

template <typename T1, typename T2> T2 DoubleBox<T1, T2>::get2() const
{
    return data2;
}

template <typename T1, typename T2> void DoubleBox<T1, T2>::set(const T1 value1, const T2 value2)
{
    data1 = value1;
    data2 = value2;
}

int main(int argc, char **argv)
{
    DoubleBox<int, double> a(5, 6.2342);
    cout << a.get1() << endl;
    cout << a.get2() << endl;
    a.set(10, 12.23423);
    cout << a.get1() << endl;
    cout << a.get2() << endl;
    a.get();
	return 0;
}
