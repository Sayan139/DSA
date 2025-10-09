#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution:
Iterate once through the array to find both the largest and second largest elements.
We update `largest` and `second_largest` as we traverse the array.
🕒 TC: O(n) 💾 SC: O(1)
*/
int getSecondLargest(vector<int> &arr) {
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } 
        else if(arr[i] > second_largest && arr[i] < largest) {
            second_largest = arr[i];
        }
    }

    if(second_largest == INT_MIN) return -1; // No second largest found
    return second_largest;
}
