#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//question : https://www.geeksforgeeks.org/problems/jump-game/1
bool canJump(vector<int>& arr) {
    int n = arr.size();
    int maxlen = 0;
    for (int i = 0; i < n; ++i) {
        if (i > maxlen) {
            return false;
        }
        maxlen = max(maxlen, i + arr[i]);
    }
    return true;
}
//question : https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
int minJumpsGame(vector<int>& arr) {
    int n = arr.size();
    if (n < 1) {
        return 0;
    }
    if (arr[0] == 0) {
        return -1;
    }
    int jumps = 0, currentEnd = 0, farthest = 0;
    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + arr[i]);
        if (i == currentEnd) {
            ++jumps;
            currentEnd = farthest;
            if (currentEnd >= n - 1) {
                return jumps;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 1, 1, 4}; // Example input array
    int result = minJumpsGame(arr);

    if (result == -1) {
        cout << "Cannot reach the end of the array" << endl;
    } else {
        cout << "Minimum number of jumps to reach the end: " << result << endl;
    }

    return 0;
}
