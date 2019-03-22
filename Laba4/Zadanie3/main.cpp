#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string d = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http://security.debian.org/ stretch/updates main contrib non-free\ndeb-src http://security.debian.org/ stretch/updates main contrib non-free\ndeb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free";
	int all = 0, chisla = 0, letter = 0, other = 0;
	for (int i = 0; i < d.length(); i++)
	{
		if (d[i] == ' ' || d[i] == '\n')
			continue;
		++all;
		if (d[i] >= '0' && d[i] <= '9')
			++chisla;
		else if ((d[i] >= 'a' && d[i] <= 'z') || (d[i] >= 'A' && d[i] <= 'Z'))
			++letter;
		else
			++other;
	}
	cout << "Всего: " << all << endl;
	cout << "Чисел: " << chisla << endl;
	cout << "Букв: " << letter << endl;
	cout << "Других символов: " << other << endl;
	return 0;
}