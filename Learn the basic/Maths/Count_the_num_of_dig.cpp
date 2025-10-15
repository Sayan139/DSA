#include <bits/stdc++.h>
using namespace std;
int sol1(int n){
    int n = 12345;
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    cout << count;
}
int sol2(int n){
    int count = (n == 0) ? 1 : (int)log10(n) + 1;
    return count;
}