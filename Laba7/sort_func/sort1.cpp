using namespace std;
template <typename T> void massivprint(T *mass, int b)
{
	for (int i = 0; i < b; i++)
	{
		cout << "  " << mass[i];
	}
	cout << endl;
}

template <typename T> void swap(T *pa, T *pb)
{
	T temp = *pa;
	*pa = *pb;
	*pb = temp;
}

template <typename T> void mergesort(T *mass, unsigned size)
{
	if (size <= 1)
		return;
	else if (size == 2)
	{
		if (mass[0] > mass[1])
		{
			swap(mass, mass + 1);
			return;
		}
	}
	else
	{
		int length1 = (size - 1) / 2 + 1;
		int length2 = size - length1;
		mergesort(mass, length1);
		mergesort(mass + length1, length2);
		mergelist(mass, length1, length2);
	}
}

template <typename T> void mergelist(T *mass, unsigned length1, unsigned length2)
{
	unsigned i1 = 0, i2 = length1;
	while (i1 < i2 && i2 < (length1 + length2))
	{
		if (mass[i1] <= mass[i2])
			i1++;
		else
		{
			rightshiftcycle(mass, i1, i2);
			i1++;
			i2++;
		}
	}
}

template <typename T> void rightshiftcycle(T *mass, unsigned left, unsigned right)
{
	T d = mass[right];
	rightshift(mass, left, right);
	mass[left] = d;
}

template <typename T> void rightshift(T *mass, unsigned left, unsigned right)
{
	for (unsigned i = right; i > left; i--)
		mass[i] = mass[i - 1];
}