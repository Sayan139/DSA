#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find the majority element in an array.
A majority element is one that appears more than floor(N/2) times.
*/

/*
1. Brute Force Approach

Algorithm / Intuition:
Naive Approach:
For each element, count how many times it appears in the array.
If any element appears more than floor(N/2) times, return that element.

Approach:
1. Run a loop to pick each element one by one.
2. For each element, run another loop to count its frequency.
3. If the count exceeds floor(N/2), return that element.
4. If no element satisfies the condition, return -1.

Time Complexity:  O(N^2)
Space Complexity: O(1)
*/
int majorityElementBruteForce(vector<int> v) {
    int n = v.size();

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] == v[i]) cnt++;
        }
        if (cnt > n / 2) return v[i];
    }

    return -1;
}


/*
2. Better Approach

Algorithm / Intuition:
We can optimize by avoiding repeated counting of the same elements.
Use a hash map (or unordered_map) to store the frequency of each element.

Approach:
1. Traverse the array and store the count of each element in a map.
2. While storing, check if the count of any element exceeds floor(N/2).
3. Return that element if found, otherwise return -1.

Time Complexity:  O(N)
Space Complexity: O(N)
*/
int majorityElementBetter(vector<int> v) {
    int n = v.size();
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[v[i]]++;
        if (freq[v[i]] > n / 2)
            return v[i];
    }

    return -1;
}


/*
3. Optimal Approach (Moore’s Voting Algorithm)

Algorithm / Intuition:
If an element occurs more than floor(N/2) times, it will always be the majority element after cancellation.
We can track a potential candidate and its count dynamically.

Approach:
1. Initialize two variables: count = 0 and element = 0.
2. Traverse the array:
   - If count is 0, assign element = current number.
   - If current number == element, increment count.
   - Else decrement count.
3. After traversal, element holds the potential majority element.
4. (Optional) Verify it by counting its occurrences if the array doesn’t guarantee a majority.

Time Complexity:  O(N)
Space Complexity: O(1)
*/
int majorityElementOptimal(vector<int> v) {
    int n = v.size();
    int count = 0;
    int element = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            element = v[i];
            count = 1;
        }
        else if (v[i] == element) count++;
        else count--;
    }

    // Optional verification step:
    int freq = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == element) freq++;
    }

    if (freq > n / 2) return element;
    return -1;
}


int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    // Uncomment any one to test:
    // int ans = majorityElementBruteForce(arr);
    // int ans = majorityElementBetter(arr);
    int ans = majorityElementOptimal(arr);

    cout << "The majority element is: " << ans << endl;
    return 0;
}
