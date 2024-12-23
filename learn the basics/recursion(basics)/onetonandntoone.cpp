#include <iostream>
using namespace std;

// Function to print numbers from 1 to n
void print1ton(int n) {
    if (n == 0) {
        return;
    }
    print1ton(n - 1);
    cout << n << " ";
}

// Function to print numbers from n to 1
void printnto1(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    printnto1(n - 1);
}

int main() {
    int n;
    cout << "How much you want to print: ";
    cin >> n;

    cout << "n to 1:" << endl;
    printnto1(n);
    cout << endl;

    cout << "1 to n:" << endl;
    print1ton(n);
    cout << endl;

    return 0;
}
