#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solutions:

🔹 Approach 1: Sum Formula
The numbers from 0 to n have a total sum = n*(n+1)/2.
Subtract the sum of array elements from this total to find the missing number.

🕒 TC: O(n) 💾 SC: O(1)

🔹 Approach 2: XOR Method
XOR all numbers from 0 to n and XOR all elements of the array.
Since a ⊕ a = 0, all common elements cancel out, leaving the missing number.

🕒 TC: O(n) 💾 SC: O(1)
*/
int missingNumber_Sum(vector<int>& nums) {
    int n = nums.size();
    int total = n * (n + 1) / 2;
    int actual = 0;
    for(int i = 0; i < n; i++) actual += nums[i];
    return total - actual;
}

int missingNumber_XOR(vector<int>& nums) {
    int n = nums.size();
    int xorAll = 0, xorNums = 0;

    for(int i = 0; i <= n; i++) xorAll ^= i;
    for(int i = 0; i < n; i++) xorNums ^= nums[i];

    return xorAll ^ xorNums;
}
