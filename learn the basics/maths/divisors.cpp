#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;
vector <int> divisors(int n){
    vector <int> divisors;
    int sqrtn = sqrt(n);
    for(int i=1; i<=sqrtn; i++){
        if(n%i==0){
            divisors.push_back(i);
            if(i!=n/i){
                divisors.push_back(n/i);
            }
        }
    }
    return divisors;
}
//Given a positive integer n, 
//The task is to find the value of Σi from 1 to n F(i) where function 
//F(i) for the number i is defined as the sum of all divisors of i.
int sumofdivisorstilln(int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i * (n/i);
    }
    return sum;
}
int main(){
    int n;
    cout << "enter the number : ";
    cin >> n;
    vector <int> div = divisors(n);
    cout << "[";
    for(int i=0; i<div.size(); i++){
        cout << div[i];
        if(i<div.size()-1){
            cout << ",";
        }
    }
    cout << "]" << endl;
    return 0;
}