#include <iostream>
#include <map>
using namespace std;
// bruite force approach:Approach:

// The steps are as follows:

// First, we will run a loop(say i) to select the elements of the array one by one.
// For every element arr[i], we will perform a linear search using another loop and count its occurrence.
// If for any element the occurrence is 1, we will return it.
// Time Complexity: O(N2), where N = size of the given array.
// Reason: For every element, we are performing a linear search to count its occurrence. The linear search takes O(N) time complexity. And there are N elements in the array. So, the total time complexity will be O(N2).

// Space Complexity: O(1) as we are not using any extra space.
int bruite(vector <int> arr){
    int n = arr.size();
    for(int i =0; i<n; i++){
        int num = arr[0];
        int count =0;
        for(int j=0; j<n; j++){
            if(arr[j]==num) count++;
        }
        if(count==1) return num;
    }
    return -1;
}

// better solution 1:
// The steps are as follows:

// First, we will find the maximum element(say maxElement) to know the size of the hash array.
// Then we will declare a hash array of size maxElement+1.
// Now, using another loop we will store the elements of the array along with their frequency in the hash array. (i.e. hash[arr[i]]++)
// After that, using another loop we will iterate over the hash array, and try to find the element for which the frequency is 1, and finally, we will return that particular element.
// Time Complexity: O(N)+O(N)+O(N), where N = size of the array
// Reason: One O(N) is for finding the maximum, the second one is to hash the elements and the third one is to search the single element in the array.

// Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
int better1(vector <int> arr){
    int n = arr.size();
    int high = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>high) high=arr[i];
    }
    vector <int> counts(high+1,0);
    for(int i=0; i<n; i++){
        counts[arr[i]]++;
    }
    for(int i=1; i<n; i++){
        if(counts[i]==1) return arr[i];
    }
    return -1;
}

// better solution 2:
// using map
// The steps are as follows:

// First, we will declare a map.
// Now, using a loop we will store the elements of the array along with their frequency in the map data structure.
// Using another loop we will iterate over the map, and try to find the element for which the frequency is 1, and finally, we will return that particular element.
// Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
// Reason: We are inserting N elements in the map data structure and insertion takes logM time(where M = size of the map). So this results in the first term O(N*logM). The second term is to iterate the map and search the single element. In Java, HashMap generally takes O(1) time complexity for insertion and search. In that case, the time complexity will be O(N) + O(M).

// Note: The time complexity will be changed depending on which map data structure we are using. If we use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM). But in the worst case(which rarely happens), it will be nearly O(N2).

// Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
int better2(vector <int> arr){
    int n = arr.size();
    map <int,int> hashmap;
    for(int i=0; i<n; i++){
        hashmap[arr[i]]++;
    }
    for(auto it:hashmap){
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}

//optimal approach:
//We will just perform the XOR of all elements of the array using a loop and the final XOR will be the answer.
// Time Complexity: O(N), where N = size of the array.
// Reason: We are iterating the array only once.

// Space Complexity: O(1) as we are not using any extra space.
int optimal(vector <int> arr){
    int n = arr.size();
    int sol =0;
    for(int i=0; i<n; i++){
        sol ^= arr[i];
    }
    return sol;
}