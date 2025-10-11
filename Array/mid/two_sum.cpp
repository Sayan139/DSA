#include <bits/stdc++.h>
using namespace std;

/*
we need to insert a unordered map first then we need to iterate the array and inside it as we need to find a pair
we can get the rem num from the target num by making a variable rem which will store the value of target - current_val
and after that search it in the map if its found then we found and pair else its not at the end if not found return empty 
array or {}
tc : O(n) sc : O(n)
*/
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mpp; 
    for(int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i];
        if(mpp.find(rem) != mpp.end()) {
            return {i, mpp[rem]};
        }
        mpp[nums[i]] = i;
    }
    return {}; 
}
