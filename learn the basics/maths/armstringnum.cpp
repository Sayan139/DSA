#include <iostream>
#include <cmath>
using namespace std;

bool armstrong(int n) {
    int power = to_string(n).length(); // Count the number of digits
    int sum = 0, temp = n;

    while (temp != 0) {
        int lt = temp % 10; // Get the last digit
        sum += pow(lt, power); // Add the power of the digit
        temp /= 10; // Remove the last digit
    }

    return sum == n; // Check if the sum matches the original number
}

int main() {
    int n = 153;
    cout << (armstrong(n) ? "True" : "False") << endl;

    n = 123;
    cout << (armstrong(n) ? "True" : "False") << endl;

    return 0;
}
