#include <bits/stdc++.h>
using namespace std;
/*
Armstrong num is a num which is equal to the sum of its own digit raised to the
power of the num of digits
*/
int sol1(int n){
    int org = n;
    int num_dig = (n==0) ? 1:(int)log10(n)+1;
    int sum_dig = 0;
    while(n!=0){
        int temp = n%10;
        sum_dig += pow(temp,num_dig);
        n/=10;
    }return (sum_dig == org);
}