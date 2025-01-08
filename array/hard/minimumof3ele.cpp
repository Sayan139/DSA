#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
/*
in this approach we are going to just simply traverse through the array and take unique num
and then check whethere it exists in the ans array and then start another loop to count num of time 
that unique element exists and at last checkw whether its count to more than n/3 and in the lasr if the size
of the ans array is 2 then we will break and return the value
(you say why return the 2 because if we divide the array into 3 pieces and get number if numbers need 
to be more than n/3 then if we take n=5 then num need to be at least 2 to get >n/3 if take 3 of them it
results in 6 which is not possible as elements are 5 so thats why there only 2 possibility of answers so thats why 2)
*/
vector <int> bruiteforce(vector <int> arr){
    int n = arr.size();
    vector <int> ans;
    for(int i=0; i<n; i++){
        if(ans.size()==0 || ans[0] != arr[i]){
            int count = 0;
            for(int j=0; j<n; j++){
                if(arr[j]==arr[i]) count++;
            }
            if(count > (n/3)) ans.push_back(arr[i]);
        }
        if(ans.size()==2) break;
    }
    return ans;
}
/*
now we use the map method to do this quetion we will use unordered_map for this
this is the btter approach
Time Complexity: O(N*logN), where N = size of the given array.
Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN).
If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

Space Complexity: O(N) as we are using a map data structure. We are also using a list that stores a maximum of 2 elements. That space used is so small that it can be considered constant.
*/
vector <int> bettersol(vector <int> arr){
    int n = arr.size();
    vector <int> ans;
    unordered_map <int,int> mpp;
    int mini = n/3+1;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mini) ans.push_back(arr[i]);
        if(ans.size()==2) break;
    }
    return ans;
}
/*
now for the optimal part
this approach is also called Extended Boyer Moore's Voting Algorithm here 
this is same method we used in the mazority n/2 element approach but it little bit extendec as 
we are going to do it for the two elements
*/
vector <int> optimal(vector <int> arr){
    int n = arr.size();
    int cnt1 = 0,cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    for(int i=0; i<n; i++){
        if(cnt1 == 0 && ele2 != arr[i]){
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && ele1 != arr[i]){
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1) cnt1++;
        else if(arr[i] == ele2) cnt2++;
        else{
            cnt1--,cnt2--;
        }
    }
    vector <int> ans;
    cnt1 = 0,cnt2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==ele1) cnt1++;
        if(arr[i]==ele2) cnt2++; 
    }
    int  mini = n / 3 + 1;
    if(cnt1 >= mini) ans.push_back(ele1);
    if(cnt2 >= mini) ans.push_back(ele2);
    return ans;
}