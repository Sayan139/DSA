#include <iostream>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int x) {
    if (x < 0)
        return false; 

    int rev = 0;
    int temp = x;
    while (temp != 0) {
        int lastDigit = temp % 10;      
        rev = (rev * 10) + lastDigit;   
        temp /= 10;                     
    }
    return rev == x;
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
