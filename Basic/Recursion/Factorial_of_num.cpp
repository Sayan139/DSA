#include <bits/stdc++.h>
using namespace std;
/*
Brute Force:
Use a simple loop to multiply numbers from 1 to n.
Straightforward and avoids recursion overhead.
🕒 TC: O(n) 💾 SC: O(1)
*/
int sol1(int n){
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
/*
optimal sol : 
Use the mathematical relation n! = n × (n−1)!.
Recursion gives a cleaner approach but uses stack space.
🕒 TC: O(n) 💾 SC: O(n) (due to recursion stack)
*/
int sol2(int n){
    if (n == 0 || n == 1) return 1;
    return n * sol2(n - 1);
}