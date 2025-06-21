#include <iostream>
using namespace std;
int maxfreq(vector<int> arr,int k){
    sort(arr.begin(),arr.end());
    int left = 0,right = 0,res = 0;
    long long total = 0;
    while(right < arr.size()){
        total += arr[right];
        while(arr[right] * (right - left + 1) > total + k){
            total -= arr[left];
            left++;
        }
        res = max(res,right - left + 1);
        right++;
    }
    return res;
}
int main(){
    vector <int> arr = {1, 2, 4};
    int k = 5;
    cout << maxfreq(arr,k);
}