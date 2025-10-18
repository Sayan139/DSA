#include <bits/stdc++.h>
using namespace std;
int majorityElementOptimal(vector<int> v) {
    int n = v.size();
    int count = 0;
    int element = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            element = v[i];
            count = 1;
        }
        else if (v[i] == element) count++;
        else count--;
    }
    int freq = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == element) freq++;
    }
    if (freq > n / 2) return element;
    return -1;
}
int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElementOptimal(arr);

    cout << "The majority element is: " << ans << endl;
    return 0;
}
