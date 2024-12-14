#include <iostream>
using namespace std;

// Function to reverse a number
int reverseNum(int n) {
    if (n == 0)
        return 0;

    int rev = 0;
    int temp = n; // Temporary variable to process the number
    while (temp != 0) {
        int lastDigit = temp % 10;      // Extract the last digit
        rev = (rev * 10) + lastDigit;  // Build the reversed number
        temp /= 10;                    // Remove the last digit
    }
    return rev;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << "The reversed number " << n << " is: " << reverseNum(n) << endl;

    return 0;
}
