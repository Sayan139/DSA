#include <bits/stdc++.h>
using namespace std;
/*
optimal sol : (for recursion problems)
Use recursion — swap elements at start and end,
then recursively move inward.
Elegant and short but uses call stack space.
🕒 TC: O(n) 💾 SC: O(n) (recursion stack)
*/
void helper(vector<int>& arr, int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    helper(arr, start + 1, end - 1);
}
int sol1(vector<int> &arr){
    helper(arr, 0, arr.size() - 1);
}