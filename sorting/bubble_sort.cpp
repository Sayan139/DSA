#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution: Bubble Sort with Early Exit
- Repeatedly compares adjacent elements and swaps them if out of order.
- Tracks if any swap occurs in a pass; stops early if the array is already sorted.
🕒 TC: O(n^2) worst-case, O(n) best-case (already sorted)
💾 SC: O(1)
*/
void bubbleSort(vector<int>& arr) {
    bool is_swap = true;
    for(int i = arr.size() - 1; i > 0; i--) {
        is_swap = false;
        for(int j = 0; j < i; j++) {
            if(arr[j + 1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
                is_swap = true;
            }
        }
        if(!is_swap) break; // array is already sorted
    }
}
