#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter two integer numbers:" << endl;
    cin >> m >> n;
    while(n > 0)
    {
        int r = m % n;
        m = n;
        n = r
    }
    cout << "The gcd is :" << m << endl;
    return 0;
}
