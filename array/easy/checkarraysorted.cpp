#include <iostream>
using namespace std;
/*
this is question to check whether the array is sorted or not
so the first approach would be to go all through the array and keep checking whether the 
next num is bigger than the current num and if in any case we get bigger num than the
current num we will return false
*/
bool arraysorted(vector <int> arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]) return false;
    }return true;
}