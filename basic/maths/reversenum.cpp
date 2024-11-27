#include <iostream>
using namespace std;
int reverse(int n){
    if(n==0) return 0;
    int rev = 0;
    while(n!=0){
        int lt = n%10;
        rev = (rev*10)+lt;
        n/=10;
    }
    return rev;
}
int main(){
    int n;
    cout << "enter the value of the number: ";
    cin >> n;
    cout << "the reversed value of the number is: " << reverse(n);
}