#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution: Insertion Sort
- Builds the sorted portion of the array one element at a time.
- Takes each element and inserts it into its correct position among previously sorted elements.
- Efficient for small or nearly sorted arrays.
🕒 TC: O(n^2) worst-case, O(n) best-case (already sorted)
💾 SC: O(1)
*/
void insertionSort(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}
