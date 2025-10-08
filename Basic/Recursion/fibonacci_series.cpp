#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution:
Simple recursive approach based on Fibonacci definition:
F(n) = F(n−1) + F(n−2)
- Clean and straightforward.
- Recalculates subproblems repeatedly, so inefficient for large n.
🕒 TC: O(2^n) 💾 SC: O(n) (recursion stack)
*/
int fib(int n) {
    if(n == 0 || n == 1) return n;
    return fib(n - 1) + fib(n - 2);
}
