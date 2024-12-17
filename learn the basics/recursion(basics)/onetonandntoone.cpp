#include <iostream>
using namespace std;
void print1ton(int n){
    if(n==0)return;
    print1ton(n-1);
    cout << n << " ";
}
void printnto1(int n){
    if(n==0) return;
    cout << n << " ";
    printnto1(n-1);
}
int main(){
    int n;
    cout << "how much you want to print : ";
    cin >> n;
    cout << "n to 1: " << endl;
    printnto1(n);
    cout << endl;
    cout << "1 to n: " << endl;
    print1ton(n);
    cout << endl;
}