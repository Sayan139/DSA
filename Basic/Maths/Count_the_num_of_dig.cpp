#include <bits/stdc++.h>
using namespace std;
/*
bruite force : 
Use arithmetic — repeatedly divide the number by 10 until it becomes 0, counting how many times it divides.
Purely numeric and space-efficient.
🕒 TC: O(d) 💾 SC: O(1)
*/
int sol1(int n){
    int n = 12345;
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    cout << count;
}
/*
Use logarithm — number of digits = floor(log10(n)) + 1.
Instant computation, no loops.
🕒 TC: O(1) 💾 SC: O(1)
*/
int sol2(int n){
    int count = (n == 0) ? 1 : (int)log10(n) + 1;
    return count;
}