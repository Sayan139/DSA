#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {3, 6, 4, 4, 3, 2, 1, 9, 10, 2};  // Example array
    int n = arr.size();
    vector<int> hash(11, 0);  // Create a hash array of size 11 initialized to 0

    // Counting the frequency of each element in arr
    for (int num : arr) {
        hash[num] += 1;
    }

    // Printing the frequency of each number from 0 to 10
    cout << "number : occurrence" << endl;
    for (int i = 0; i < 11; ++i) {
        cout << i << " : " << hash[i] << endl;
    }

    return 0;
}
