#include <iostream>
using namespace std;

int gcd(int m,int n)
{
    while(m!=n)
    {
        if(m>n)
            m=m-n;
        else
            n=n-m;
    }
    return m;
}
int main() {
    int m,n;
    cout << "Enter two integer numbers:" << endl;
    cin >> m >> n;
    int result = gcd(m,n);
    cout << "The gcd is :" << result << endl;
    return 0;
}
