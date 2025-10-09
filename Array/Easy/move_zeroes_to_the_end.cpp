#include <bits/stdc++.h>
using namespace std;
/*
Optimal Solution:
Move all zeros to the end while maintaining the order of non-zero elements.
Use a pointer `index` to track the position for the next non-zero element.

🕒 TC: O(n) 💾 SC: O(1)
*/
void moveZeroes(vector<int>& nums) {
    int index = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[index]);
            index++;
        }
    }
}
