#include <iostream>
using namespace std;
// bruite force approach:
//aldready done in the copy
vector <int> bruite(vector <int>& arr){
    int n = arr.size();
    vector <int> temp;
    for(int i=0; i<n; i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    int nz = temp.size();
    for(int i=0; i<nz; i++){
        arr[i] = temp[i];
    }
    for(int i=nz; i<n; i++){
        arr[i] = 0;
    }
}

// optimal Algorithm:

// First, using a loop, we will place the pointer j. If we don’t find any 0, we will not perform the following steps.
// After that, we will point i to index j+1 and start moving the pointer using a loop.
// While moving the pointer i, we will do the following:
// If a[i] != 0 i.e. a[i] is a non-zero element: We will swap a[i] and a[j]. Now, the current j is pointing to the non-zero element a[i]. So, we will shift the pointer j by 1 so that it can again point to the first zero.
// Finally, our array will be set in the right manner.

vector <int> optimal(vector <int> &arr){
    int n = arr.size();
    int j = -1;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return;
    for(int i=j+1; i<n; i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}