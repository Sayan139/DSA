#include <bits/stdc++.h>
using namespace std;

/*
Optimal Solution: Quick Sort (Divide and Conquer)
- Choose a pivot (here, last element of the current subarray).
- Partition array so that:
  • Elements ≤ pivot go left
  • Elements > pivot go right
- Recursively apply quickSort on left and right subarrays.
- Efficient on average, but worst-case O(n^2) if pivot is poorly chosen.
🕒 TC: O(n log n) average, O(n^2) worst-case
💾 SC: O(log n) recursion stack
*/
class Solution {
public:
    // Partition function: rearranges elements around pivot
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];       // choose last element as pivot
        int i = low - 1;             // index for smaller element

        for(int j = low; j < high; j++) {
            if(arr[j] <= pivot) {    // element smaller than pivot
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]); // place pivot in correct position
        return i + 1;                // return pivot index
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high) {
            int pi = partition(arr, low, high); // partitioning index
            quickSort(arr, low, pi - 1);       // sort left subarray
            quickSort(arr, pi + 1, high);      // sort right subarray
        }
    }
};

/*
Dry Run Example:

Array: [10, 7, 8, 9, 1, 5]
k = 0 (not used here, just normal quicksort)

Step 1: pivot = 5 (last element)
Partition: [1, 5, 8, 9, 7, 10] -> pivot index = 1

Left Subarray: [1] -> size 1, already sorted
Right Subarray: [8, 9, 7, 10]

Step 2: pivot = 10
Partition: [8, 9, 7, 10] -> pivot index = 4
Left Subarray: [8, 9, 7]

Step 3: pivot = 7
Partition: [7, 9, 8] -> pivot index = 2
Left: empty, Right: [9, 8]

Step 4: pivot = 8
Partition: [8, 9] -> pivot index = 3

Final sorted array: [1, 5, 7, 8, 9, 10]

*/
