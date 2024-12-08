#include <iostream>
using namespace std;
int countnum(int n){
    if(n==0) return 0;
    int count =0;
    while(n!=0){//here what we are doing is we are dividing the num by 10 and incrementing the value of count on each iteration 
        count++;
        n/=10;
    }
    return count;
}// this is the method yoou can solve the problem on how to find the num of digits the given num have
int main(){
    int n;
    cout << "enter the value of the number: ";
    cin >> n;
    cout << "The number of digits the num have: " << countnum(n) << endl;
}