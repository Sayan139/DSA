#include <bits/stdc++.h>
using namespace std;
/*
Use arithmetic — reverse the number using %10 and /10,
then compare the reversed value with the original.
Fully numeric and efficient.
includes safety for integer overflow and works within 32-bit bounds.
🕒 TC: O(d) 💾 SC: O(1)
*/
bool sol1(int n){
    int org = n;
    int rev = 0;
    while (n > 0) {
        int digit = n % 10;
        if((rev > INT_MAX/10) && (rev == INT_MAX/10 || digit > 7)) return 0;
        if((rev < INT_MIN/10) && (rev == INT_MIN/10 || digit < -8)) return 0;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return (rev == org);
}