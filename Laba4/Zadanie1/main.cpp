#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    int x;
    string v1 = "верблюд";
    string v2i4 = "верблюда";
    string v5i9 = "верблюдов";
    while(cin >> x) {
        if (x <= 0 || x > 100) break;
        if (x == 11 || x == 12 || x == 13 || x == 14)  cout << "В караване было " << x << " " << v5i9 << endl;
        else if (x % 10 == 1) cout << "В караване был " << x << " " << v1 << endl;
        else if (x % 10 >= 2 && x % 10 <= 4) cout << "В караване было " << x << " " << v2i4 << endl;
        else if (x % 10 >= 5 && x % 10 <= 9) cout << "В караване было " << x << " " << v5i9 << endl;
        else if (x % 10 == 0) cout << "В караване было " << x << " " << v5i9 << endl;
    }
    return 0;
}
