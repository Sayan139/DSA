#include <iostream>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int x) {
    if (x < 0)
        return false; // Negative numbers are not palindromes

    int rev = 0;
    int temp = x; // Temporary variable to process the number
    while (temp != 0) {
        int lastDigit = temp % 10;       // Extract the last digit
        rev = (rev * 10) + lastDigit;   // Build the reversed number
        temp /= 10;                     // Remove the last digit
    }
    return rev == x; // Check if the reversed number equals the original
}

int main() {
    int n;
    cout << "Enter the value: ";
    cin >> n;

    if (isPalindrome(n)) {
        cout << "It's a palindrome" << endl;
    } else {
        cout << "It's not a palindrome" << endl;
    }

    return 0;
}
