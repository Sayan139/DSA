#include <iostream>
using namespace std;
int main(){
    // bruite force
    // int n1;
    // int n2;
    // cin >> n1;
    // cin >> n2;
    // int gcd = 0;
    // for(int i=1; i<min(n1,n2); i++){
    //     if(n1%i == 0 && n2%i == 0) gcd = max(gcd,i);
    // }
    // cout << gcd;
    

    // better solution 
    // int n1;
    // int n2;
    // cin >> n1;
    // cin >> n2;
    // int gcd = 0;
    // for(int i=min(n1,n2); i>0; i--){
    //     if(n1%i==0 && n2%i==0){
    //         gcd = i;
    //         break;
    //     }
    // }
    // cout << gcd;


    // optimal sol
    int n1;
    int n2;
    cin >> n1;
    cin >> n2;
    while (n1>0 && n2>0){
        if(n1 > n2) n1 = n1%n2;
        else n2 = n2%n1;
    }
    if(n1 == 0) cout << n2;
    else cout << n1;
}