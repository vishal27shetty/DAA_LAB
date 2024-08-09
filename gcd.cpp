#include <iostream>
#include <chrono> // For time measurement
using namespace std;

// Euclid's Algorithm by Recursion
int gcdEuclidRecursive(int m, int n) {
    if (n == 0)
        return m;
    return gcdEuclidRecursive(n, m % n);
}

// Middle School Procedure (Brute Force Approach)
int gcdMiddleSchool(int m, int n) {
    int gcd = 1;
    for (int i = 1; i <= min(m, n); ++i) {
        if (m % i == 0 && n % i == 0)
            gcd = i;
    }
    return gcd;
}

// Consecutive Integer Checking Method
int gcdConsecutiveInteger(int m, int n) {
    int t = min(m, n);
    while (t > 0) {
        if (m % t == 0 && n % t == 0)
            return t;
        t--;
    }
    return 1; // GCD is 1 if no other divisor is found
}

int main() {
    int m, n;
    cout << "Enter two integer numbers:" << endl;
    cin >> m >> n;

    // Measure time for Euclid's Algorithm by Recursion
    auto start = chrono::high_resolution_clock::now();
    int resultEuclid = gcdEuclidRecursive(m, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeEuclid = end - start;

    // Measure time for Middle School Procedure (Brute Force Approach)
    start = chrono::high_resolution_clock::now();
    int resultMiddleSchool = gcdMiddleSchool(m, n);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeMiddleSchool = end - start;

    // Measure time for Consecutive Integer Checking Method
    start = chrono::high_resolution_clock::now();
    int resultConsecutive = gcdConsecutiveInteger(m, n);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> timeConsecutive = end - start;

    // Output results
    cout << "Results:\n";
    cout << "GCD (Euclid's Algorithm by Recursion): " << resultEuclid << " | Time taken: " << timeEuclid.count() << " seconds" << endl;
    cout << "GCD (Middle School Procedure): " << resultMiddleSchool << " | Time taken: " << timeMiddleSchool.count() << " seconds" << endl;
    cout << "GCD (Consecutive Integer Checking): " << resultConsecutive << " | Time taken: " << timeConsecutive.count() << " seconds" << endl;

    return 0;
}
