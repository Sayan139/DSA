#include <iostream>
using namespace std;
/*
optimal sol : 
An Armstrong number, also known as a narcissistic number or plenary number, is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
Number of digits: 3, 153 = 13+53+33
tc : O(log(10)) sc : O(1)
*/
int sol(int n){
    if(n<=0) return 0;
    int num_dig = (int)log10(abs(n))+1;
    int sum = 0;
    while(n != 0){
        int temp = n % 10;
        sum += pow(temp,num_dig);
        n/=10;
    }return sum;
}