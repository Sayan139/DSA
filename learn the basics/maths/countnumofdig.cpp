#include <iostream>
#include <cmath>
using namespace std;

// Brute force approach to count the number of digits in a number
int countnum(int n) {
    if (n == 0) {
        return 0;
    }
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Optimal approach to count the number of digits in a number
int countnumopt(int n) {
    return (n > 0) ? floor(log10(n)) + 1 : 1;
}

// Function to count the number of digits in n that divide n evenly
int numofdigeven(int n) {
    if (n == 0) {
        return 0;
    }
    int count = 0;
    int temp = n;
    while (temp != 0) {
        int lt = temp % 10;
        if (lt != 0 && n % lt == 0) {
            count++;
        }
        temp /= 10;
    }
    return count;
}

int main() {
    int n = 443562;
    cout << "The number of digits is: " << countnum(n) << endl;
    return 0;
}
