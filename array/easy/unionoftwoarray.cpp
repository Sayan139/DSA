#include <iostream>
#include <map>
#include <set>
using namespace std;
//use of hash map:
//Our aim is to find the common elements in arr1 and arr2, and the distinct elements of arr1,arr2. Use a Single map to find the frequencies of elements in arr1 and arr2.

// As we are using only a single map the common element in arr1 and arr2 are treated as a single element for finding frequency, so there would be no duplicates.
vector <int> sol(vector <int>& arr1,vector <int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    map <int,int> freq;
    vector <int> unionofnum;
    for(int i=0; i<n; i++){
        freq[arr1[i]]++;
    }
    for(int i=0; i<m; i++){
        freq[arr2[i]]++;
    }
    for(auto & x:freq){
        unionofnum.push_back(x.first);
    }
    return unionofnum;
}
//using set
vector <int> sol1(vector <int> arr1,vector <int> arr2){
    int n = arr1.size();
    int m = arr2.size();
    set <int> allnum;
    vector <int> unionofnum;
    for(int i=0; i<n; i++){
        allnum.insert(arr1[i]);
    }
    for(int i=0; i<n; i++){
        allnum.insert(arr2[i]);
    }
    for(auto & x:allnum){
        unionofnum.push_back(x);
    }
    return unionofnum;
}
// now using the two pointer approach 
// Approach:

// Take two pointers let’s say i,j pointing to the 0th index of arr1 and arr2.
// Create an empty vector for storing the union of arr1 and arr2.
// From solution 2 we know that the union is nothing but the distinct elements in arr1 + arr2 
// Let’s traverse the arr1 and arr2 using pointers i and j and insert the distinct elements found into the union vector.
// While traversing we may encounter three cases.

// arr1[ i ] == arr2[ j ] 
// Here we found a common element, so insert only one element in the union. Let’s insert arr[i] in union and increment i.

// NOTE: There may be cases like the element to be inserted is already present in the union, in that case, we are inserting duplicates which is not desired. So while inserting always check whether the last element in the union vector is equal or not to the element to be inserted. If equal we are trying to insert duplicates, so don’t insert the element, else insert the element in the union. This makes sure that we are not inserting any duplicates in the union because we are inserting elements in sorted order.
// arr1[ i ]  < arr2[ j ]
// arr1[ i ] < arr2[ j ] so we need to insert arr1[ i ] in union.IF last element in  union vector is not equal to arr1[ i ],then insert in union else don’t insert. After checking Increment i.
// arr1[ i ] > arr2[ j ]
// arr1[ i ] > arr2[ j ] so we need to insert arr2[ j ] in union. IF the last element in the union vector is not equal to arr2[ j ], then insert in the union, else don’t insert. After checking Increment j. After traversing if any elements are left in arr1 or arr2 check for condition and insert in the union.


vector<int> unionOfArrays(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0;
    vector<int> result;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (result.empty() || result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
            j++;
        } else {
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while (i < arr1.size()) {
        if (result.empty() || result.back() != arr1[i]) {
            result.push_back(arr1[i]);
        }
        i++;
    }

    while (j < arr2.size()) {
        if (result.empty() || result.back() != arr2[j]) {
            result.push_back(arr2[j]);
        }
        j++;
    }

    return result;
}

