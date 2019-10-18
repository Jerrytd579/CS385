// Jerry Cheng
// I pledge my honor that I have abided by the Stevens Honor System.

#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

int gcd_iterative(int m, int n) {
    // Iteratively calcuates the gcd of two numbers, m and n

    // If m or n are negative, converts to positive
    if(m < 0 || n < 0) {
        n = abs(n);
        m = abs(m);
    }

    if(n == 0) {
        return m;
    }
    if(m == 0) {
        return n;
    }

    int i = 1;
    int gcd = 0;

    while(i <= m && i <= n) {
        if(m % i == 0 && n % i == 0) {
            gcd = i;
        }
        i++;
    }

    return gcd;
}

int gcd_recursive(int m, int n) {
    if(m < 0 || n < 0) {
        n = abs(n);
        m = abs(m);
    }
    if(n == 0) {
        return m;
    }
    if(m == 0) {
        return n;
    }
    if(m == n) {
        return m;
    }

    return gcd_recursive(n, m % n);
}

int main(int argc, char* const argv[]) {
    int m, n;
    istringstream iss;

    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <integer m> <integer n>"
             << endl;
        return 1;
    }
    iss.str(argv[1]);
    if ( !(iss >> m) ) {
        cerr << "Error: The first argument is not a valid integer."
             << endl;
        return 1;
    }
    iss.clear(); // clear the error code
    iss.str(argv[2]);
    if ( !(iss >> n) ) {
        cerr << "Error: The second argument is not a valid integer."
             << endl;
        return 1;
    }

    cout << "Iterative: gcd(" << m << ", " << n << ") = " << gcd_iterative(m, n) << endl;
    cout << "Recursive: gcd(" << m << ", " << n << ") = " << gcd_recursive(m, n) << endl;
    return 0;
}