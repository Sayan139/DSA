#include <bits/stdc++.h>
using namespace std;

/*
Problem: Next Lexicographical Permutation

Problem Statement:
Given an array Arr[] of integers, rearrange the numbers into the lexicographically next greater permutation.
If such an arrangement is not possible, rearrange it to the lowest possible order (i.e., sorted in ascending order).

Example:
Input: A = {1,3,2}
Output: {2,1,3}
Explanation: Next permutation after 1,3,2 is 2,1,3.
*/

/*
1. Brute Force Approach

Algorithm / Intuition:
Generate all permutations of the array, sort them, find the input permutation,
and return the permutation immediately after it in the sorted list.

Time Complexity: O(N! * N) {Generating all permutations takes N!, copying arrays takes O(N)}
Space Complexity: O(N!) {All permutations stored in memory}
*/
vector<int> nextPermutationBruteForce(vector<int> &A) {
    vector<vector<int>> perms;
    sort(A.begin(), A.end());
    
    do {
        perms.push_back(A);
    } while (next_permutation(A.begin(), A.end()));
    
    for (int i = 0; i < perms.size() - 1; i++) {
        if (perms[i] == A) {
            return perms[i + 1];
        }
    }
    
    return perms[0]; // wrap around if last permutation
}

/*
2. Optimal Approach

Algorithm / Intuition:
1. Traverse the array from the back to find the first index 'ind' such that A[ind] < A[ind+1] (breakpoint).
2. If no such index exists, the array is the last permutation. Reverse it to get the first permutation.
3. If breakpoint exists:
   - Traverse from the end to find the smallest number greater than A[ind].
   - Swap it with A[ind].
   - Reverse the subarray from ind+1 to end to get the next permutation.

Time Complexity: O(N) {Single traversal + possible reverse}
Space Complexity: O(1) {In-place swapping and reversing}
*/
vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size();
    int ind = -1;

    // Step 1: Find breakpoint
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }

    // Step 2: If no breakpoint, reverse entire array
    if (ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 3: Find element to swap with breakpoint
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 4: Reverse right half
    reverse(A.begin() + ind + 1, A.end());
    return A;
}

int main() {
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};

    // Uncomment any one to test:
    // vector<int> ans = nextPermutationBruteForce(A);
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "]" << endl;

    return 0;
}
