#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find all divisors of a number
vector<int> divisors(int n) {
    vector<int> divisors_list;
    int sqrtn = sqrt(n);
    for (int i = 1; i <= sqrtn; ++i) {
        if (n % i == 0) {
            divisors_list.push_back(i);
            if (i != n / i) {
                divisors_list.push_back(n / i);
            }
        }
    }
    return divisors_list;
}

// Function to calculate ΣF(i) for i from 1 to n
long long divisorstilln(int n) {
    long long total_sum = 0;
    for (int i = 1; i <= n; ++i) {
        total_sum += i * (n / i);
    }
    return total_sum;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long result = divisorstilln(n);
    cout << "The sum of ΣF(i) from 1 to " << n << " is: " << result << endl;

    return 0;
}
