#include <iostream>
using namespace std;
/*
here we need to eliminate the num one by one so eliminate 1 , and also elimate the multiples of 3 and 2
and itertae from 5 to sqrt(n) and skin 6 steps each iteration and eliminate i and i+2
Time Complexity: O(√n)
Space Complexity: O(1)
*/
bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}