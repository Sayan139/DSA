#include <bits/stdc++.h>
using namespace std;
/*
the bruite force and optimal approach both are same like lower bound:
*/
int bruite(vector <int> arr,int target){
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]>target) return i;
    }return n;
}
int optimal(vector <int> arr,int k){
    int n = arr.size();
    int ans = n;
    int low = 0,high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]>k){
            ans = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
/*
Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].
Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.
*/
vector <int> optimalquestion(vector <int> arr,int x){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 0,high = n-1;
    int floor = -1;
    int ceil = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid]==x) return {arr[mid],arr[mid]};
        else if(arr[mid] < x){
            floor = arr[mid];
            low = mid + 1;
        }else{
            ceil = arr[mid];
            high = mid -1;
        }
    }
    return {floor,ceil};
}