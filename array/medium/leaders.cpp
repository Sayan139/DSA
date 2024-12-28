#include <iostream>
using namespace std;
// Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.
// bruite force: 
// Intuition:

// There is no special intuition needed here. Just a common fact that we need to compare elements in order to find the greatest is more than enough.

// Approach

// In this brute force approach, we start checking all the elements from the start of the array to the end to see if an element is greater than all the elements on its right (i.e, the leader).
// For this, we will use nested loops where the outer loop will check for each element in the array whether it is a leader or not.
// The inner loop checks if there is any element to the right that is greater than the element currently traversed by the outer loop.
// We start by initializing the outer loop pointer to the start element and setting it as the current leader.
// If any element traversed is found greater than the element currently set as a leader, it will not go to the ans array and we increment the outer loop pointer by 1 and set the next element as the current leader.
// If we don’t find any other element to the right greater than the current element, then we push the current element to the ans array stating that is it the leader element.
vector <int> bruite(vector <int> arr){
    int n = arr.size();
    vector <int> res;
    for(int i=0; i<n; i++){
        int leader = true;
        for(int j=i+1; j<n; j++){
            if(arr[i] < arr[j]){
                leader = false;
                break;
            }
        }
        if(leader){
            res.push_back(arr[i]);
        }
    }
    return res;
}

// optimal approach:
// In the above approach, we do a fresh traversal for each candidate. If we think carefully, we only want to compare the elements on the right side. So, what if we start from the last element?
// That is, we'll try to remember the greatest element encountered so far and we'll use that to decide whether a candidate is a leader or not.
// First, we'll start the traversal from the right. Then, we move toward the left. Whenever we encounter a new element, we check with the greatest element obtained so far.
// If the current element is greater than the greatest so far, then the current element is one of the leaders and we update the greatest element.
// Else, we proceed with the further elements on the left. This method prints the leaders in the reverse direction of their occurrences. If we are concerned about the order, we can use an extra array or a string to order.
vector <int> optimal(vector <int> arr){
    vector <int> res;
    int n = arr.size();
    if(n==0) return res;
    int max_ele = arr[n-1];
    res.push_back(max_ele);
    for(int i = n-2; i>=0; i--){
        if(arr[i] > max_ele){
            res.push_back(arr[i]);
            max_ele = arr[i];
        }
    }
    return res;
}