#include <iostream>
using namespace std;
int fibonacci(int n){
    if(n<=1) return n;
    int last = fibonacci(n-1);
    int s_last = fibonacci(n-2);
    return last + s_last;
}
int main(){
    int n;
    cout << "Enter number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
}