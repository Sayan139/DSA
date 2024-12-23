#include <iostream>
#include <cmath>
using namespace std;

int reverse(int n) {
    int rev = 0;
    int sign = (n > 0) ? 1 : -1;
    n = abs(n);
    
    while (n != 0) {
        int lt = n % 10;  // Get the last digit
        rev = (rev * 10) + lt;  // Build the reversed number
        n /= 10;  // Remove the last digit
    }
    
    long long result = rev * sign;  // Restore the sign
    
    // Check for overflow
    if (result < -(1LL << 31) || result > (1LL << 31) - 1) {
        return 0;
    }
    
    return result;
}

int main() {
    int n = -123;
    cout << "Reverse is: " << reverse(n) << endl;
    return 0;
}
