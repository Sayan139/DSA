#include <iostream>
#include <string>
using namespace std;

// Recursive function to print a string n times
void printrecursion(int n, const string& s) {
    if (n == 0) {
        return;
    }
    cout << s << " ";
    printrecursion(n - 1, s);
}

int main() {
    int n;
    string s;

    // Taking input for number of times to print and the string to print
    cout << "Enter the number of times you want to print: ";
    cin >> n;
    cout << "Enter what you want to print: ";
    cin >> s;

    // Calling the recursive function
    printrecursion(n, s);
    cout << endl;

    return 0;
}
