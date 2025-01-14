#include <bits/stdc++.h>
using namespace std;
/*
Naive Approach (Brute-force): 

Approach:

The steps are as follows:

First, we will run a loop(say i) from 0 to N-1 to select the a[i].
As index j should be greater than index i, inside loop i, we will run another loop i.e. j from i+1 to N-1, and select the element a[j].
Inside this second loop, we will check if a[i] > 2*a[j] i.e. if a[i] and a[j] can be a pair. If they satisfy the condition, we will increase the count by 1.
Finally, we will return the count i.e. the number of such pairs.
Intuition:

The naive approach is pretty straightforward. We will use nested loops to generate all possible pairs. We know index i must be smaller than index j. So, we will fix i at one index at a time through a loop, and with another loop, we will check(the condition a[i] > 2*a[j]) the elements from index i+1 to N-1  if they can form a pair with a[i].

Time Complexity: O(N2), where N = size of the given array.
Reason: We are using nested loops here and those two loops roughly run for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
int countpairsbruite(vector <int> arr){
    int n = arr.size();
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>2*arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}
/*
Approach:

The steps are basically the same as they are in the case of the merge sort algorithm. The change will be just in the mergeSort() function:

In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the mergeSort().
We will add the numbers returned by the previous mergeSort() calls.
Before the merge step, we will count the number of pairs using a function, named countPairs().
We need to remember that the left half starts from low and ends at mid, and the right half starts from mid+1 and ends at high.
The steps of the countPairs() function will be as follows:

We will declare a variable, cnt, initialized with 0.
We will run a loop from low to mid, to select an element at a time from the left half.
Inside that loop, we will use another loop to check how many elements from the right half can make a pair.
Lastly, we will add the total number of elements i.e. (right-(mid+1)) (where right = current index), to the cnt and return it.
Time Complexity: O(2N*logN), where N = size of the given array.
Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).

Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
*/
void merge(vector <int>& arr,int low,int mid,int high){
    vector <int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=0; i< temp.size(); i++){
        arr[low+i] = temp[i];
    }
}
int countpairs(vector <int>& arr,int low,int mid,int high){
    int right = mid+1;
    int cnt = 0;
    for(int i=low; i<=mid; i++){
        while(right <= high && (long long)arr[i]>2*(long long)arr[right]) right++;
        cnt += (right - (mid+1));
    }
    return cnt;
}
int mergesort(vector <int>& arr,int low,int high){
    int cnt = 0;
    if(low >= high)  return cnt;
    int mid = (low+high)/2;
    cnt += mergesort(arr,low,mid);
    cnt += mergesort(arr,mid+1,high);
    cnt += countpairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}
int team(vector <int> arr){
    int n = arr.size();
    return mergesort(arr,0,n-1);
}