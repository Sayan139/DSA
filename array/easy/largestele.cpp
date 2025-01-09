#include <iostream>
using namespace std;
/*
in this approach we are going to iterate through the array and find largest and placeit in the 
perevious largest element and will continue this process till end
*/
int largest(vector <int> arr){
    int largest = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > largest) largest = arr[i]; 
    }
    return largest;
}