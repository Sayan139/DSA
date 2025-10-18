#include <bits/stdc++.h>
using namespace std;
vector<int> leadersOptimal(int arr[], int n) {
    vector<int> ans;
    int maxSoFar = arr[n-1];
    ans.push_back(maxSoFar);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxSoFar) {
            ans.push_back(arr[i]);
            maxSoFar = arr[i];
        }
    }

    reverse(ans.begin(), ans.end()); // To maintain original order
    return ans;
}

int main() {
    int arr[] = {10, 22, 12, 3, 0, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Uncomment any one to test:
    // vector<int> ans = leadersBruteForce(arr, n);
    vector<int> ans = leadersOptimal(arr, n);

    cout << "Leaders in the array: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
