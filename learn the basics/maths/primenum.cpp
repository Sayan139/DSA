#include <iostream>
using namespace std;
bool checkprime(int n){
    if(n<=1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5; i<=sqrt(n); i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
int main(){
    int n;
    cout << "enter the value : ";
    cin >> n;
    if(checkprime(n)){
        cout << "the number is prime";
    }else{
        cout << "the number is not prime ";
    }
}