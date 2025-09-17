#include <bits/stdc++.h>
using namespace std;
// bruite force:
/*here we need to divide the n / 10 each time until it becomes 0 this reduces 
one dig each time from the last of the num and to count it we increment the count variable 
in each iteration
tc : O(log10(n)) sc : O(1)*/
int countdig(int n){
    int count = 0;
    while(n!=0){
        count++;
        n/=10;
    }return count;
}
// optimal
/*
here we are going to use the formula of log10(n)+1 and the +1 is due to handle cases of
0.95 or 0.99 which int value occur 0 so thats why +1(by the help of precedence)
tc : O(1) sc : O(1)
*/
int count_dig(int n){
    if(n == 0) return 0;
    return (int)(log10(abs(n)))+1;
}