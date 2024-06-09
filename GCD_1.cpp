#include <iostream>
using namespace std;

int gcd(int m,int n)
{
    if(n==0)
        return m;
    else
        return gcd(n,m%n);
}
int main() {
    int m,n;
    cout << "Enter two integer numbers:" << endl;
    cin >> m >> n;
    int result = gcd(m,n);
    cout << "The gcd is :" << result << endl;
    return 0;
}
