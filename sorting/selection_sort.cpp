#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution: Selection Sort
- Repeatedly select the minimum element from the unsorted portion and place it at the current position.
- Uses nested loops: outer loop fixes position, inner loop finds minimum.
🕒 TC: O(n^2) 💾 SC: O(1)
*/
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int mini = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[mini]) mini = j;
        }
        swap(arr[i], arr[mini]);
    }
}
