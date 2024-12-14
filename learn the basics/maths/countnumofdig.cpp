#include <iostream>
#include <cmath>
using namespace std;

// Function to count the number of digits in a number
int countNum(int n) {
    if (n == 0)
        return 0; // Handle the edge case when the value of n is 0
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10; // Integer division ensures no floating-point result
    }
    return count;
}

// Optimal solution to count the number of digits
int countNumOptimal(int n) {
    return (n > 0) ? (floor(log10(n)) + 1) : 1;
}

// Function to count the number of digits in n that divide n evenly
int evenlyDivides(int n) {
    if (n == 0)
        return 0; // Handle the edge case when the value of n is 0
    int count = 0; // Variable to store the count of digits
    int temp = n; // Temporary variable to process the number
    while (temp != 0) {
        int lastDigit = temp % 10; // Extract the last digit of the number
        // Check if the digit is non-zero and divides n evenly
        if (lastDigit != 0 && n % lastDigit == 0) {
            count++; // Increment the count if the condition is met
        }
        temp /= 10; // Remove the last digit from temp
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << "The number of digits in the number " << n << " is: " << countNumOptimal(n) << endl;
    cout << "The number of digits in " << n << " that evenly divide " << n << " is: " << evenlyDivides(n) << endl;

    return 0;
}
