#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b!=0){
        int temp = b;
        b= a%b;
        a = temp;
    }
    return a;
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int gcdResult = gcd(a, b);
    int lcmResult = lcm(a, b);

    cout << "GCD of " << a << " and " << b << " is: " << gcdResult << endl;
    cout << "LCM of " << a << " and " << b << " is: " << lcmResult << endl;

    return 0;
}
