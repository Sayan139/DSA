#include <bits/stdc++.h>
using namespace std;
/*
now coming for the bruite forece approach:
Naive Approach (Brute-force): 

This approach is not the exact solution according to the question as in this approach we are going to use an extra space i.e. an array. But it is definitely one of the solutions if the question does not contain the constraint of not using any extra space. And also this approach will help to understand the optimal approaches.

Approach:

Assume the size of the given arrays are n and m.

The steps are as follows:

We will first declare a third array, arr3[] of size n+m, and two pointers i.e. left and right, one pointing to the first index of arr1[] and the other pointing to the first index of arr2[].
The two pointers will move like the following:
If arr1[left] < arr2[right]: We will insert the element arr1[left] into the array and increase the left pointer by 1.
If arr2[right] < arr1[left]: We will insert the element arr2[right] into the array and increase the right pointer by 1.
If arr1[left] == arr2[right]: Insert any of the elements and increase that particular pointer by 1.
If one of the pointers reaches the end, then we will only move the other pointer and insert the rest of the elements of that particular array into the third array i.e. arr3[].
If we move the pointer like the above, we will get the third array in the sorted order.
Now, from sorted array arr3[], we will copy first n(size of arr1[]) elements to arr1[], and the next m(size of arr2[]) elements to arr2[].
Intuition:

Intuition is pretty straightforward. As the given arrays are sorted, we are using 2 pointer approach to get a third array, that contains all the elements from the given two arrays in the sorted order. Now, from the sorted third array, we are again filling back the given two arrays.
Time Complexity: O(n+m) + O(n+m), where n and m are the sizes of the given arrays.
Reason: O(n+m) is for copying the elements from arr1[] and arr2[] to arr3[]. And another O(n+m) is for filling back the two given arrays from arr3[].

Space Complexity: O(n+m) as we use an extra array of size n+m.
*/
void merge(long long arr1[],long long arr2[],int n,int m){
    long long arr3[n+m];
    int left = 0;
    int right = 0;
    int index = 0;
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[index]=arr1[left];
            left++,index++;
        }else{
            arr3[index]=arr2[right];
            right++,index++;
        }
    }
    while(left < n){
        arr3[index] = arr1[left];
        index++,left++;
    }
    while(right < m){
        arr3[index++]=arr2[right++];
    }
    for(int i=0; i<n+m; i++){
        if(i < n) arr1[i] = arr3[i];
        else arr2[i-n] = arr3[i];
    }
}
/*
now coming to the optimal soultion 1:
this is a simple two pointer approach with a twist
Approach:

The sizes of the given arrays are n(size of arr1[]) and m(size of arr2[]).

The steps are as follows:

We will declare two pointers i.e. left and right. The left pointer will point to the last index of the arr1[](i.e. Basically the maximum element of the array). The right pointer will point to the first index of the arr2[](i.e. Basically the minimum element of the array).
Now, the left pointer will move toward index 0 and the right pointer will move towards the index m-1. While moving the two pointers we will face 2 different cases like the following:
If arr1[left] > arr2[right]: In this case, we will swap the elements and move the pointers to the next positions.
If arr1[left] <= arr2[right]: In this case, we will stop moving the pointers as arr1[] and arr2[] are containing correct elements.
Thus, after step 2, arr1[] will contain all smaller elements and arr2[] will contain all bigger elements. Finally, we will sort the two arrays.
Intuition:

If we merge the given array, one thing we can assure is that arr1[] will contain all the smaller elements and arr2[] will contain all the bigger elements. This is the logic we will use. Using the 2 pointers, we will swap the bigger elements of arr1[] with the smaller elements of arr2[] until the minimum of arr2[] becomes greater or equal to the maximum of arr1[].
Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.

Space Complexity: O(1) as we are not using any extra space.
*/
void optimal1(int arr1[],int arr2[],int n,int m){
    int left = n-1;
    int right = 0;
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]) {
            swap(arr1[left],arr2[right]);
            left--,right++;
        }
        else break;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}
/*
now coming to the optimal solution part 2:
Intuition:

Similar to optimal approach 1, in this approach, we will use two pointers i.e. left and right, and swap the elements if the element at the left pointer is greater than the element at the right pointer. 

But the placing of the pointers will be based on the gap value calculated. The formula to calculate the initial gap is the following:

Initial gap = ceil((size of arr1[] + size of arr2[]) / 2)

Assume the two arrays as a single continuous array and initially, we will place the left pointer at the first index and the right pointer at the (left+gap) index of that continuous array.

Now, we will compare the elements at the left and right pointers and move them by 1 place each time after comparison. While comparing we will swap the elements if the element at the left pointer > the element at the right pointer. After some steps, the right pointer will reach the end and the iteration will be stopped.

After each iteration, we will decrease the gap and will follow the same procedure until the iteration for gap = 1 gets completed. Now, after each iteration, the gap will be the following:

gap = ceil( previous gap / 2)

The whole process will be applied to the imaginary continuous array constructed using arr1[] and arr2[].

Approach:

The steps are as follows:

First, assume the two arrays as a single array and calculate the gap value i.e. ceil((size of arr1[] + size of arr2[]) / 2).
We will perform the following operations for each gap until the value of the gap becomes 0:
Place two pointers in their correct position like the left pointer at index 0 and the right pointer at index (left+gap).
Again we will run a loop until the right pointer reaches the end i.e. (n+m). Inside the loop, there will be 3 different cases:
If the left pointer is inside arr1[] and the right pointer is in arr2[]: We will compare arr1[left] and arr2[right-n] and swap them if arr1[left] > arr2[right-n].
If both the pointers are in arr2[]: We will compare arr1[left-n] and arr2[right-n] and swap them if arr1[left-n] > arr2[right-n].
If both the pointers are in arr1[]: We will compare arr1[left] and arr2[right] and swap them if arr1[left] > arr2[right].
After the right pointer reaches the end, we will decrease the value of the gap and it will become ceil(current gap / 2). 
Finally, after performing all the operations, we will get the merged sorted array.

for contect here we are using and concept called shell short :
Shell sort is mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved. The idea of ShellSort is to allow the exchange of far items. In Shell sort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element are sorted.

Algorithm:

Step 1 − Start
Step 2 − Initialize the value of gap size, say h.
Step 3 − Divide the list into smaller sub-part. Each must have equal intervals to h.
Step 4 − Sort these sub-lists using insertion sort.
Step 5 – Repeat this step 2 until the list is sorted.
Step 6 – Print a sorted list.
Step 7 – Stop.
*/
void swapifgrater(int arr1[],int arr2[],int left,int right){
    if(arr1[left] > arr2[right]){
        swap(arr1[left],arr2[right]);
    }
}
void merge(int arr1[],int arr2[],int n,int m){
    int len = n+m;
    int gap = (len/2)+(len%2);
    while(gap > 0){
        int left = 0;
        int right = left+gap;
        while(right < len){
            // here this means thats the left is in arr1 and right is in arr2
            if(left < n && right >= n){
                swapifgrater(arr1,arr2,left,right - n); // here we are taking the right pointer value left + gap and subtracting it with the left arr size and we are getting the actual value it in simple means thats the we are subtracting the size of the first array from the gap
            }
            else if(left >= n){
                swapifgrater(arr1,arr2,left - n,right -n);
            }
            else{
                swapifgrater(arr1,arr2,left,right);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap+1)/2;
    }
}
/*
here if the question is given that you have the arr1 and arr2 but you have to return the anser in arr1 itslef and 
arr1 have the part for it filles with 0 on those cases 
we have to take the approach a bit different 
here we have to take three indexes and which are the last of arr1 and last arr2
*/
void optimaltype2(vector <int> arr1,int m,vector <int> arr2,int n){
    int left = m-1; // this the index given for till the arr1 valid index after that all are 0
    int right = n-1;
    int index = m+n-1;
    while(left >= 0 && right >= 0){
        if(arr1[left] >= arr2[right]){
            arr1[index]=arr1[left];
            left--;
        }else{
            arr1[index]=arr2[right];
            right--;
        }
        index--;
    }
    while(right >= 0){
        arr1[index] = arr2[right];
        right--,index--;
    }
}