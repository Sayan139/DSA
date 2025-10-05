#include <bits/stdc++.h>
using namespace std;
/*
Brute Force:
We only need to check till √n because if n is composite, one factor will always be ≤ √n.
🕒 TC: O(√n) 💾 SC: O(1)
*/
bool sol1(int n){
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
/*
Optimal Solution (6k ± 1 optimization):
All primes > 3 are of the form 6k ± 1.
So we skip multiples of 2 and 3 and check only i = 5, 11, 17, … (i += 6).
🕒 TC: O(√n / 3) 💾 SC: O(1)
*/
bool sol2(int n)
{
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}