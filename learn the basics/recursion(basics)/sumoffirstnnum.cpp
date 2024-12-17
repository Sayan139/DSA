#include <iostream>
using namespace std;
int sumofn(int n)
{
    if (n == 1)
        return 1;
    return n + sumofn(n - 1);
}
int sumOfSeries(int n) //question of finding the sum of the series 1^3 + 2^3 + 3^3 + 4^3 .... so..on you have to find the sum of them
{
    if (n == 1)
        return 1;
    return (n * n * n) + sumOfSeries(n - 1);
}
int main()
{
    int n;
    cout << "enter the value of the number n: ";
    cin >> n;
    cout << "the sum of first " << n << " number is : " << sumofn(n);
}