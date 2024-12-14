#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n) {
    if (n == 0)
        return 0;
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

bool isArmstrong(int n) {
    int power = countDigits(n);
    int temp = n;
    int sum = 0;
    while (temp != 0) {
        int lastDigit = temp % 10;
        sum += pow(lastDigit, power);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if (isArmstrong(n)) {
        cout << "It's an Armstrong number" << endl;
    } else {
        cout << "It's not an Armstrong number" << endl;
    }

    return 0;
}
