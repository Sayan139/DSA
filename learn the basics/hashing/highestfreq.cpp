#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count the frequency of elements in the array
vector<int> hasharray(const vector<int>& arr) {
    int n = arr.size();
    vector<int> hash_array(n + 1, 0); // Create a hash array of size n + 1
    for (int num : arr) {
        hash_array[num - 1]++;  // Increment frequency (adjust for 1-based indexing)
    }
    return hash_array;
}

// Function to find the maximum frequency of an element after performing at most k operations
int maxfrew(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());  // Sort the array
    int left = 0, right = 0;
    int result = 0;
    int total = 0;

    while (right < arr.size()) {
        total += arr[right];  // Add the current element to total
        while (arr[right] * (right - left + 1) > total + k) {
            total -= arr[left];  // Remove the left element from total
            left++;  // Move the left pointer to the right
        }
        result = max(result, right - left + 1);  // Update the result
        right++;  // Move the right pointer to the right
    }
    return result;
}

int main() {
    vector<int> arr = {3, 4, 5, 6, 6, 7, 3, 2, 1, 3, 4, 6};
    
    // Using hasharray function to get frequency of elements
    vector<int> result = hasharray(arr);
    cout << "Element frequencies:" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Element " << i + 1 << ": " << result[i] << endl;
    }

    // Example of using maxfrew function
    int k = 3;
    cout << "Maximum frequency after at most " << k << " operations: " << maxfrew(arr, k) << endl;

    return 0;
}
