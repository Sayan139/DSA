#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }
    return (a==0) ? b:a;
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
