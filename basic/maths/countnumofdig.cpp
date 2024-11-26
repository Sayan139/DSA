#include <iostream>
using namespace std;
int countdig(int n){
    if(n==0) return 0;
    int count = 0;
    while(n!=0){
        count++;
        n/=10;
    }
    return count;
}
int main(){
    int n;
    cout << "enter the value of number: ";
    cin >> n;
    cout << "the num of digits : " << countdig(n);
}