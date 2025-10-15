#include <bits/stdc++.h>
using namespace std;
void helper(vector<int>& arr, int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    helper(arr, start + 1, end - 1);
}
int sol1(vector<int> &arr){
    helper(arr, 0, arr.size() - 1);
}