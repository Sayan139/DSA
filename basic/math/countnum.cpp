#include <iostream>
using namespace std;
int countnum(int n){
    if(n==0) return 0;
    int count =0;
    while(n!=0){
        count++;
        n/=10;
    }
    return count;
}
int main(){
    int n;
    cout << "enter the value of the number: ";
    cin >> n;
    cout << "The number of digits the num have: " << countnum(n) << endl;
}