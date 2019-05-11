#ifndef SORT_H
#define SORT_H
using namespace std;

template <typename T> void massivprint(T *mass, int b);
template <typename T> void mergesort(T *mass, unsigned size);
template <typename T> void swap(T *pa, T *pb);
template <typename T> void mergelist(T *mass, unsigned length1, unsigned length2);
template <typename T> void rightshiftcycle(T *mass, unsigned left, unsigned right);
template <typename T> void rightshift(T *mass, unsigned left, unsigned right);
#endif
