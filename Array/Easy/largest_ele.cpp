#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution:
Iterate once through the array to find the maximum element.
🕒 TC: O(n) 💾 SC: O(1)
*/
int largest(vector<int> &arr) {
    int maxi = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
