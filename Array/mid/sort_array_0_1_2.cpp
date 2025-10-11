#include <bits/stdc++.h>
using namespace std;

/*
Problem: Sort an array consisting of 0s, 1s, and 2s (Dutch National Flag Problem)
*/

/*
1. Brute Force Approach

Approach:
1. Sort the array using any standard sorting algorithm.
2. Since the array contains only 0s, 1s, and 2s, sorting will automatically arrange them.

Time Complexity:  O(n log n)
Space Complexity: O(1) or O(n) depending on the sorting algorithm used.
*/
void sortColorsBruteForce(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}


/*
2. Better Approach

Approach:
1. Count the number of 0s, 1s, and 2s using three counters.
2. Overwrite the array:
   - Fill all 0s first,
   - Then all 1s,
   - Then all 2s.

Time Complexity:  O(n)
Space Complexity: O(1)
*/
void sortColorsBetter(vector<int>& arr) {
    int zero = 0, one = 0, two = 0;

    for (int num : arr) {
        if (num == 0) zero++;
        else if (num == 1) one++;
        else two++;
    }

    int i = 0;
    while (zero--) arr[i++] = 0;
    while (one--)  arr[i++] = 1;
    while (two--)  arr[i++] = 2;
}


/*
3. Optimal Approach (Dutch National Flag Algorithm)

Approach:
1. Use three pointers: low, mid, and high.
   - low = 0 → position for next 0
   - mid = 0 → current index
   - high = n - 1 → position for next 2
2. Traverse the array:
   - If arr[mid] == 0 → swap(arr[low], arr[mid]), increment both low and mid.
   - If arr[mid] == 1 → increment mid.
   - If arr[mid] == 2 → swap(arr[mid], arr[high]), decrement high.
3. Repeat until mid > high.

Time Complexity:  O(n)
Space Complexity: O(1)
*/
void sortColorsOptimal(vector<int>& arr) {
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++, mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    // Uncomment any one method to test
    // sortColorsBruteForce(arr);
    // sortColorsBetter(arr);
    sortColorsOptimal(arr);

    cout << "Sorted array:   ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
