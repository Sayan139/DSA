#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution: Merge Sort (Divide and Conquer)
- Recursively divides the array into halves until single elements remain.
- Then merges sorted halves into one sorted array.
- Stable sorting algorithm (preserves relative order of equal elements).
🕒 TC: O(n log n) 💾 SC: O(n) (temporary array during merge)
*/
class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }

        // Copy remaining elements
        while(left <= mid) temp.push_back(arr[left++]);
        while(right <= high) temp.push_back(arr[right++]);

        // Copy back to original array
        for(int i = 0; i < temp.size(); i++)
            arr[low + i] = temp[i];
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if(low >= high) return;
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
};
