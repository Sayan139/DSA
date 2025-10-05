#include <bits/stdc++.h>
using namespace std;
/*
We use the Euclidean algorithm, which relies on this property:
GCD(a, b) = GCD(b, a % b) until one becomes 0.
The non-zero number at the end is the GCD.
*/
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return (a == 0) ? b : a;
}