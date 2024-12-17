#include <iostream>
using namespace std;
void printrecursion(int n,string s){
    if(n==0) return ;
    cout << s << " ";
    printrecursion(n-1,s);
}
int main(){
    int n ;
    string s;
    cout << "enter the number of times you want to print : ";
    cin >> n;
    cout << "enter what you want to print : ";
    cin >> n;
    printrecursion(n,s);
}