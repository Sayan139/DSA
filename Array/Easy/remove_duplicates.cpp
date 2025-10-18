#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& arr) {
    int index = 1;
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[i - 1]) {
            arr[index] = arr[i]; 
            index++;
        }
    }

    return index; 
}
