#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution:
Given a sorted array, we need to remove duplicates **in-place** 
and return the count of unique elements.

👉 Logic:
- Since the array is already sorted, all duplicates are grouped together.
- We maintain a pointer `index` that keeps track of the position 
  where the next unique element should go.
- We start from i = 1 and compare each element with the previous one:
    - If arr[i] != arr[i-1], it means we've found a new unique element.
    - We place this new element at arr[index] and increment `index`.

🕒 TC: O(n) 💾 SC: O(1)
*/
int removeDuplicates(vector<int>& arr) {
    int index = 1; // Points to the next position for a unique element

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[i - 1]) {
            arr[index] = arr[i]; // Move the unique element forward
            index++;
        }
    }

    return index; // Number of unique elements
}
