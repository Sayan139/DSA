#include <bits/stdc++.h>
using namespace std;

/*
Problem: Rearrange Array Elements by Sign (Variety 1 & 2)

Problem Statement (Variety 1):
Given an array ‘A’ of size ‘N’ with an equal number of positive and negative elements,
rearrange the array such that positive and negative elements alternate,
starting with a positive element. The relative order of positive and negative elements must be maintained.

Example 1:
Input: arr[] = {1,2,-4,-5}, N = 4
Output: 1 -4 2 -5
Explanation: Positives = 1,2; Negatives = -4,-5. Alternate while keeping relative order.

Problem Statement (Variety 2):
Given an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal),
rearrange the array such that positive and negative elements alternate starting with a positive element.
Place leftover elements at the end in the same order as in the input.

Example 2:
Input: arr[] = {1,2,-4,-5,3,4}, N = 6
Output: 1 -4 2 -5 3 4
Explanation: Alternately place positives and negatives; remaining positives at the end.
*/

/*
1. Brute Force Approach (Variety 1)

Algorithm / Intuition:
Separate positives and negatives into two arrays, then place them alternately.

Approach:
1. Create two vectors: pos and neg.
2. Traverse A, push positive elements to pos, negative to neg.
3. Place elements alternately: pos[i] at 2*i, neg[i] at 2*i+1.

Time Complexity: O(N) for segregating + O(N/2) for merging = O(N)
Space Complexity: O(N) (for pos and neg vectors)
*/
vector<int> rearrangeBySignBruteForce(vector<int>& A) {
    int n = A.size();
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
    }
    for (int i = 0; i < n/2; i++) {
        A[2*i] = pos[i];
        A[2*i+1] = neg[i];
    }
    return A;
}

/*
2. Optimal Approach (Variety 1)

Algorithm / Intuition:
Use two indices: posIndex for even positions, negIndex for odd positions.
Place elements directly in a new array during a single traversal.

Time Complexity: O(N)
Space Complexity: O(N) (for answer array)
*/
vector<int> rearrangeBySignOptimal(vector<int>& A) {
    int n = A.size();
    vector<int> ans(n,0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            ans[posIndex] = A[i];
            posIndex += 2;
        } else {
            ans[negIndex] = A[i];
            negIndex += 2;
        }
    }
    return ans;
}

/*
3. Brute Force Approach (Variety 2 - Unequal Positives/Negatives)

Algorithm / Intuition:
Separate positives and negatives into two arrays. Place alternately,
then append remaining elements at the end.

Time Complexity: O(2*N) = O(N)
Space Complexity: O(N) (for pos and neg vectors)
*/
vector<int> rearrangeBySignVar2(vector<int>& A) {
    int n = A.size();
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
    }

    int i = 0;
    int minSize = min(pos.size(), neg.size());
    for (int j = 0; j < minSize; j++) {
        A[2*j] = pos[j];
        A[2*j+1] = neg[j];
    }

    int index = 2*minSize;
    if (pos.size() > neg.size()) {
        for (int j = minSize; j < pos.size(); j++) A[index++] = pos[j];
    } else {
        for (int j = minSize; j < neg.size(); j++) A[index++] = neg[j];
    }

    return A;
}

int main() {
    // Variety 1
    vector<int> A1 = {1,2,-4,-5};
    vector<int> ans1 = rearrangeBySignOptimal(A1);
    cout << "Variety 1 Output: ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    // Variety 2
    vector<int> A2 = {1,2,-4,-5,3,4};
    vector<int> ans2 = rearrangeBySignVar2(A2);
    cout << "Variety 2 Output: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}
