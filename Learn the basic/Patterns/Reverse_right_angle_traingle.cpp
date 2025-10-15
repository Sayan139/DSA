#include <bits/stdc++.h>
using namespace std;
void pattern(int n){
    for(int i=n; i>=0; i--){
        for(int j=0; j<=i; j++){
            cout << "* ";
        }cout << endl;
    }
}
int main(){
    pattern(5);
}