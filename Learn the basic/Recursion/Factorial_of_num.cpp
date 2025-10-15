#include <bits/stdc++.h>
using namespace std;
int sol2(int n){
    if (n == 0 || n == 1) return 1;
    return n * sol2(n - 1);
}