#include <bits/stdc++.h>
using namespace std;
/*
Use math — take the last digit (%10), add it to reversed (rev*10 + digit), and remove it (/10).
Fully numeric, simple, and space-efficient.
🕒 TC: O(d) 💾 SC: O(1)
*/
int sol1(int n){
    int rev = 0;
    while (n > 0) {
        int digit = n % 10;
        if((rev > INT_MAX/10) && (rev == INT_MAX/10 || digit > 7)) return 0;
        if((rev < INT_MIN/10) && (rev == INT_MIN/10 || digit < -8)) return 0;
        rev = rev * 10 + digit;
        n /= 10;
    }
    cout << rev;
}