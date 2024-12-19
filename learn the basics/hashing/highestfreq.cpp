#include <iostream>
using namespace std;
vector <int> hasharray(vector <int> arr){
    vector <int> hash(arr.size()+1,0);
    for(int i=0; i<arr.size(); i++){
        hash[arr[i]-1]++;
    }
    return hash;
}
//The frequency of an element is the number of times it occurs in an array.
//You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
//Return the maximum possible frequency of an element after performing at most k operations.
int maxfrew(vector <int> arr,int k){
    sort(arr.begin(),arr.end());
    long long left =0,right = 0;
    long long result =0;
    long long total = 0;
    while(right < arr.size()){
        total += arr[right];
        while(arr[right]*(right-left+1) > total+k){
            total -= arr[left];
            left++;
        }
        result = max(result,right-left+1);
        right++;
    }
    return result;
}
int main(){
    vector <int> arr = {3,4,5,6,6,7,3,2,1,3,4,6};
    vector<int> result = hasharray(arr);
    cout << "Element frequencies: " << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Element " << i + 1 << ": " << result[i] << endl;
    }
}