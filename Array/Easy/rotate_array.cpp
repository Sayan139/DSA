#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++, end--;
    }
}
// 👉 Right rotation by k steps
void rotateRight(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // Handle k > n

    reverse(nums, 0, n - k - 1);
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - 1);
}
// 👉 Left rotation by k steps
void rotateLeft(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // Handle k > n

    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
    reverse(nums, 0, n - 1);
}
