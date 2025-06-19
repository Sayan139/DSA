#include <iostream>
#include <cmath>
using namespace std;
bool optimal(int n){
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5; i*i<= n; i+=6){
        if(n%i == 0 || n%(i+2)==0) return false;
    }return true;
}
int main(){
    // bruite force
    // int n;
    // cin >> n;
    // int count = 0;
    // for(int i; i<=n; i++){
    //     if(n%i==0) count++;
    // }
    // cout << ((count == 2) ? "true" : "false");


    // better approach 
    // int n = 0;
    // cin >> n;
    // int cnt = 0;
    // for(int i=1; i<= sqrt(n); i++){
    //     if(n%i==0){
    //         cnt++;
    //         if(i!=n/i) cnt++;
    //     }
    // }cout << ((cnt == 2) ? "true" : "false");


    // optimal approach :
    int n;
    cin >> n;
    if(optimal(n)) cout << "true";
    else cout << "false";
}