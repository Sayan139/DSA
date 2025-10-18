#include <bits/stdc++.h>
using namespace std;
void sortColorsBruteForce(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}
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
