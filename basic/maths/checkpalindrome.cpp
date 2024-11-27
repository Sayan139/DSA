#include <iostream>
using namespace std;
bool checkpalindrome(int n){
    if(n==0)return false;
    int t = n;
    int rev = 0;
    while(t!=0){
        int lt = t%10;
        rev = (rev*10)+lt;
        t/=10;
    }
    return rev==n;
}
int main(){
    int n;
    cout << "enter the number to check whether its palindrome or not: ";
    cin >> n;
    if(checkpalindrome(n)){
        cout << "the number is palindrome " << endl;
    }else{
        cout << "its not palindrome";
    }
}