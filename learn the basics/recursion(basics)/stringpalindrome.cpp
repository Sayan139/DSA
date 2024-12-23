#include <iostream>
#include <string>
#include <cctype> // for isalnum() and tolower()
using namespace std;

// Recursive function to check if a string is a simple palindrome
bool ispalindrome(int i, const string& s) {
    if (i >= s.size()) {
        return true;
    }
    if (s[i] != s[s.size() - i - 1]) {
        return false;
    }
    return ispalindrome(i + 1, s);
}

// Recursive function to check if a string is a complex palindrome (ignores non-alphanumeric characters)
bool iscomplexpalindrome1(int start, int end, const string& s) {
    if (start >= end) {
        return true;
    }
    if (!isalnum(s[start])) {
        return iscomplexpalindrome1(start + 1, end, s);
    }
    if (!isalnum(s[end])) {
        return iscomplexpalindrome1(start, end - 1, s);
    }
    if (tolower(s[start]) != tolower(s[end])) {
        return false;
    }
    return iscomplexpalindrome1(start + 1, end - 1, s);
}

// Optimal approach to check if a string is a complex palindrome (ignores non-alphanumeric characters)
bool isPalindromeoptimal(const string& s) {
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
        if (!isalnum(s[start])) {
            start++;
        } else if (!isalnum(s[end])) {
            end--;
        } else {
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal, Panama";

    // Simple palindrome check
    if (ispalindrome(0, s)) {
        cout << "The string is a palindrome (simple check)." << endl;
    } else {
        cout << "The string is not a palindrome (simple check)." << endl;
    }

    // Complex palindrome check (ignores non-alphanumeric characters)
    if (iscomplexpalindrome1(0, s.size() - 1, s)) {
        cout << "The string is a complex palindrome (recursive check)." << endl;
    } else {
        cout << "The string is not a complex palindrome (recursive check)." << endl;
    }

    // Optimal complex palindrome check
    if (isPalindromeoptimal(s)) {
        cout << "The string is a complex palindrome (optimal check)." << endl;
    } else {
        cout << "The string is not a complex palindrome (optimal check)." << endl;
    }

    return 0;
}
