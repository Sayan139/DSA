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
/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
so above this is the question so in order to solve we know that the array is aldready sorted 
so thats why we need to fnd the number  of violation this made so in order to find it we need to find 
it by iterating through the whole array and find if the i is greater than i-1 if it is then increment violattion
thats and in the end we would check if n-1 element is greater then the first element at 0
*/
bool checksrraysortedorrotaed(vector <int> arr){
    int n = arr.size();
    int count = 0;
    for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]) count++;
    }
    if(arr[n-1] > arr[0]) count++;
    return count<=1;
}