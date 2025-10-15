#include <bits/stdc++.h>
using namespace std;
void pattern(int n){
    for(int i=n; i>=0; i--){
        for(int j=0; j<=i; j++){
            cout << "  ";
        }
        for(int j=n; j>=i; j--){
            cout << "* ";
        }
        for(int j=n-1; j>=i; j--){
            cout << "* ";
        }
        cout << endl;
    }
    for(int i=n-1; i>=0; i--){
        for(int j=n; j>=i; j--){
            cout << "  ";
        }
        for(int j=0; j<=i; j++){
            cout << "* ";
        }
        for(int j=1; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
int main(){
    pattern(5);
}