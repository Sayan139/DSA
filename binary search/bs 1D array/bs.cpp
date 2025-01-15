#include <bits/stdc++.h>
using namespace std;
/*
Binary Search: Explained

278

1
This is the very first article of the Binary Search series. Until now, we have learned the linear search algorithm. Now, in this article, we will discuss another search algorithm i.e. the Binary Search algorithm. The flow of this article will be the following:

A real-life example of Binary Search
Coding problem example
Iterative code implementation of Binary Search
Recursive code implementation of Binary Search
Time complexity
Overflow case
A real-life example of Binary Search:

Problem statement: Assume there is a dictionary and we have to find the word “raj”.

Method 1: One of the many ways is to check every possible page of the entire dictionary and see if we can find the word “raj”. This technique is known as linear search.
Basically, we can traverse from the first till the end to find the target value in the search space i.e. the entire dictionary in our example.

Method 2: In this case, we will optimize our search by using the property of a dictionary i.e. a dictionary is always in the sorted order.

We will first try to open the dictionary in such a way that it is roughly divided into two parts. Then, we will check the left page. Now, assume the words on the left page starts with ‘s’. We can certainly say that our target word i.e. “raj” definitely comes before the words start with ‘s’. So, now, we need not search in the entire dictionary rather we will only search in the left half.
Now, we will do the same thing with the left half. First, we will divide it into 2 halves and then try to locate which half contains the word “raj”. Eventually, after certain steps, we will end up finding the word “raj”.
This is a typical real-life example of binary search. 

Note:

Binary search is only applicable in a sorted search space. The sorted search space does not necessarily have to be a sorted array. It can be anything but the search space must be sorted.
In binary search, we generally divide the search space into two equal halves and then try to locate which half contains the target. According to that, we shrink the search space size.
Time Complexity:

In the algorithm, in every step, we are basically dividing the search space into 2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After a certain number of divisions, the size will reduce to such an extent that we will not be able to divide that anymore and the process will stop. The number of total divisions will be equal to the time complexity.

Let’s derive the number of divisions mathematically,

If a number n can be divided by 2 for x times:
	2^x = n
Therefore, x = logn (base is 2)
So the overall time complexity is O(logN), where N = size of the given array.
*/
//iterative method
/*
Algorithm:

Now, we will apply the binary search algorithm in the given array:

Step 1: Divide the search space into 2 halves:
In order to divide the search space, we need to find the middle point of it. So, we will take a ‘mid’ pointer and do the following:
mid = (low+high) // 2 ( ‘//’ refers to integer division)
Step 2: Compare the middle element with the target:
In this step, we can observe 3 different cases:
If arr[mid] == target: We have found the target. From this step, we can return the index of the target possibly.
If target > arr[mid]: This case signifies our target is located on the right half of the array. So, the next search space will be the right half.
If target < arr[mid]: This case signifies our target is located on the left half of the array. So, the next search space will be the left half.
Step 3: Trim down the search space:
Based on the probable location of the target we will trim down the search space.
If the target occurs on the left, we should set the high pointer to mid-1. Thus the left half will be the next search space.
Similarly, if the target occurs on the right, we should set the low pointer to mid+1. Thus the right half will be the next search space.

*/
int iterative(vector <int>& arr,int target){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 0,high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]==target) return mid;
        else if(target > arr[mid]) low = mid+1;
        else high = mid -1;
    }return -1;
}
//recursive method
/*
In the algorithm, in every step, we are basically dividing the search space into 2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After a certain number of divisions, the size will reduce to such an extent that we will not be able to divide that anymore and the process will stop. The number of total divisions will be equal to the time complexity.

Let’s derive the number of divisions mathematically,

If a number n can be divided by 2 for x times:
	2^x = n
Therefore, x = logn (base is 2)
So the overall time complexity is O(logN), where N = size of the given array.
*/
int recursive(vector <int>& arr,int low,int high,int target){
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==target) return mid;
    else if(target > arr[mid]){
        return recursive(arr,mid+1,high,target);
    }
    return recursive(arr,low,mid-1,target);
}