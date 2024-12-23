#include <iostream>
using namespace std;

// Recursive function to compute the sum of the first n natural numbers
int sumofn(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumofn(n - 1);
}

// Recursive function to compute the sum of cubes of the first n numbers
int sumOfSeries(int n) {
    if (n == 1) {
        return 1;
    }
    return (n * n * n) + sumOfSeries(n - 1);
}

int main() {
    int n;
    cout << "Enter the value of the number n: ";
    cin >> n;
    
    cout << "The sum of the first " << n << " numbers is: " << sumofn(n) << endl;
    cout << "The sum of the series 1^3 + 2^3 + ... + n^3 is: " << sumOfSeries(n) << endl;

    return 0;
}
