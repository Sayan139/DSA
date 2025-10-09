#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution:
We need to check whether the given array is sorted and possibly rotated.

👉 Logic:
- Traverse the entire array and count how many times the sorting order breaks,
  i.e., when arr[i] > arr[i+1].
- But since the array can be **rotated**, the last element may still be greater
  than the first element in a valid rotated sorted array.

🔹 Example:
   arr = [3, 4, 5, 1, 2]
   Here, the only "break" is between 5 and 1 — that's allowed (just one rotation).

🔸 Why (i + 1) % n ?
   - Normally, when i = n-1 (the last element), arr[i+1] would go out of bounds.
   - Using (i + 1) % n wraps it back to index 0 (the first element).
   - This allows us to **compare the last element with the first element**,
     handling the rotation case cleanly.

🕒 TC: O(n) 💾 SC: O(1)
*/
bool check(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++) {
        // Compare current element with the next (circularly)
        if(arr[i] > arr[(i + 1) % n])
            count++;
    }

    // If order breaks more than once, it's not sorted & rotated
    return count <= 1;
}
