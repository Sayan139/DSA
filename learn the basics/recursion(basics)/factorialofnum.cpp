#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate factorial of a number
long long factorialofnum(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorialofnum(n - 1);
}

// Function to calculate and store factorials in a list up to n
vector<long long> factoriallist(int n, vector<long long>& arr, long long currnum, int idx) {
    if (currnum * idx > n) {
        return arr;
    }
    currnum *= idx;
    arr.push_back(currnum);
    return factoriallist(n, arr, currnum, idx + 1);
}

int main() {
    int n = 100;
    vector<long long> arr = {1};  // Initializing with 1
    vector<long long> result = factoriallist(n, arr, 1, 2);  // Factorial list calculation

    // Printing the results
    for (long long i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
