#include <bits/stdc++.h>
using namespace std;

/*
Problem: Leaders in an Array

Problem Statement:
Given an array, print all the elements which are leaders.
A Leader is an element that is greater than all elements on its right side in the array.

Example:
Input: arr = {10, 22, 12, 3, 0, 6}
Output: 22 12 6
Explanation: 
22 is greater than all elements to its right, 12 is greater than elements to its right after 22, and 6 is the last element.
*/

/*
1. Brute Force Approach

Algorithm / Intuition:
Check for each element if there is any element on its right greater than it.
If not, it is a leader.

Approach:
1. Run an outer loop from i = 0 to n-1 for each element.
2. Run an inner loop from j = i+1 to n-1 to check if any element > arr[i].
3. If no element is greater, push arr[i] to the leaders array.

Time Complexity: O(N^2) {Nested loops}
Space Complexity: O(N) {To store leaders}
*/
vector<int> leadersBruteForce(int arr[], int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) ans.push_back(arr[i]);
    }
    return ans;
}

/*
2. Optimal Approach

Algorithm / Intuition:
Traverse from the end of the array while keeping track of the maximum element seen so far.
If the current element is greater than the maximum so far, it is a leader.

Approach:
1. Initialize maxSoFar = arr[n-1] and push arr[n-1] to leaders.
2. Traverse i = n-2 to 0:
   - If arr[i] > maxSoFar, push arr[i] to leaders and update maxSoFar.
3. Leaders are stored in reverse order; reverse them before printing.

Time Complexity: O(N) {Single traversal}
Space Complexity: O(N) {To store leaders}
*/
vector<int> leadersOptimal(int arr[], int n) {
    vector<int> ans;
    int maxSoFar = arr[n-1];
    ans.push_back(maxSoFar);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxSoFar) {
            ans.push_back(arr[i]);
            maxSoFar = arr[i];
        }
    }

    reverse(ans.begin(), ans.end()); // To maintain original order
    return ans;
}

int main() {
    int arr[] = {10, 22, 12, 3, 0, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Uncomment any one to test:
    // vector<int> ans = leadersBruteForce(arr, n);
    vector<int> ans = leadersOptimal(arr, n);

    cout << "Leaders in the array: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
