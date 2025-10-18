#include <bits/stdc++.h>
using namespace std;
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
