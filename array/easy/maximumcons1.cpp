#include <iostream>
using namespace std;
// Approach:  We maintain a variable count that keeps a track of the number of consecutive 1’s while traversing the array. The other variable max_count maintains the maximum number of 1’s, in other words, it maintains the answer.

// We start traversing from the beginning of the array. Since we can encounter either a 1 or 0 there can be two situations:-

// If  the value at the current index is equal to 1 we increase the value of count by one. After updating  the count variable if it becomes more than the max_count  update the max_count.
// If the value at the current index is equal to zero we make the variable count as 0 since there are no more consecutive ones.
int max_conscutive_ones(vector <int> arr){
    int n = arr.size();
    int count = 0;
    int maxi = 0;
    for(int i=0; i<n; i++){
        if(arr[i]!=0) count++;
        else count = 0;
        maxi = max(maxi,count);
    }
    return maxi;
}