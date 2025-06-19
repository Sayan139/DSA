#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int org = n;
    int sum = 0;
    int n_dig = log10(n)+1;
    while(n!=0){
        int lt = n%10;
        sum += pow(lt,n_dig);
        n/=10;
    }cout <<  ((sum == org) ? "true" : "false");
}