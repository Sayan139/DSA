#include <iostream>
#include <vector>
using namespace std;

// Function to count the frequency of numbers in the array
vector<int> frequencycount(const vector<int>& arr) {
    int n = arr.size();
    vector<int> hash_array(n, 0); // Initialize a vector of size n with 0s

    for (int num : arr) {
        if (num >= 1 && num <= n) {
            hash_array[num - 1]++;  // (-1) for 1-based indexing
        }
    }

    return hash_array;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 2};  // Example input array
    vector<int> result = frequencycount(arr);

    cout << "Frequency of numbers in range 1 to " << arr.size() << ":\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "Number " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}
