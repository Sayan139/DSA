#include <iostream>
using namespace std;

// Function to calculate the GCD of two numbers
int gcd(int n1, int n2) {
    while (n1 > 0 && n2 > 0) {
        if (n1 > n2) {
            n1 = n1 % n2;
        } else {
            n2 = n2 % n1;
        }
    }
    return (n1 == 0) ? n2 : n1;
}

// Function to calculate the LCM of two numbers
int lcm(int n1, int n2) {
    return (n1 * n2) / gcd(n1, n2);
}

int main() {
    int n1, n2;
    cout << "Enter the value of the first number (n1): ";
    cin >> n1;
    cout << "Enter the value of the second number (n2): ";
    cin >> n2;

    int gcd_result = gcd(n1, n2);
    int lcm_result = lcm(n1, n2);

    cout << "The GCD of " << n1 << " and " << n2 << " is: " << gcd_result << endl;
    cout << "The LCM of " << n1 << " and " << n2 << " is: " << lcm_result << endl;

    return 0;
}