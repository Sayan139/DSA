#include <bits/stdc++.h>
using namespace std;
// optimal sol
/*
in this sol you were need to divide the num/10 until it becomes 0 and add it to the rev
variable by the formula rev = rev * 10 + temp
and at the end return the is rev == orginal num if not return false
tc : O(log(10)) sc : O(1)
*/
bool reverse(int n){
    int rev = 0;
    int org = n;
    while(n!=0){
        int temp = n % 10;
        // dont forget to check whether the num is excedding the int min and int max to 
        // avoid over flow
        if((rev > INT_MAX/10) || (rev == INT_MAX/10 && temp > 7)) return 0;
        if((rev < INT_MIN/10) || (rev == INT_MIN/10 && temp < -8)) return 0;
        rev = rev * 10 + temp;
        n /= 10;
    }return (rev == org);
}