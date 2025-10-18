#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int,int> prefix;
    prefix[0] = -1;  
    int sum = 0, maxlen = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(prefix.find(sum - k) != prefix.end()) {
            maxlen = max(maxlen, i - prefix[sum - k]);
        }
        if(prefix.find(sum) == prefix.end()) {
            prefix[sum] = i;
        }
    }

    return maxlen;
}
int longestSubarrayPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int i = 0, sum = 0, maxlen = 0;

    for(int j = 0; j < n; j++) {
        sum += arr[j];
        while(sum > k) {
            sum -= arr[i];
            i++;
        }
        if(sum == k) {
            maxlen = max(maxlen, j - i + 1);
        }
    }
    return maxlen;
}
