#include <iostream>
#include <string>
using namespace std;

// Brute force approach to check if a number is a palindrome
bool palindromebruite(int n) {
    if (n < 0) {
        return false;
    }
    int rev = 0, temp = n;
    while (temp != 0) {
        int lt = temp % 10;  // Get the last digit
        rev = (rev * 10) + lt;  // Build the reversed number
        temp /= 10;  // Remove the last digit
    }
    return rev == n;  // Check if reversed number equals the original
}

// Optimal approach to check if a number is a palindrome using strings
bool plaindromecheckoptimal(int n) {
    string ss = to_string(n);
    string rev_ss = string(ss.rbegin(), ss.rend());
    return ss == rev_ss;
}

int main() {
    int n = -121;
    cout << "Palindrome status: " << (plaindromecheckoptimal(n) ? "True" : "False") << endl;
    return 0;
}
