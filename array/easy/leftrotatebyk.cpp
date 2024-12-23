#include <iostream>
using namespace std;
//Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.
//bruite force aldready done in copy:
//optimal also done in the copy

//this is the optimal approach
void reverse(vector <int>& arr,int i,int j){
    while(i<j){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++,j--;
    }
}
void rotatethearrayktimes(vector <int>& arr,int k){
    int n = arr.size();
    k=k%n;
    if(k==0) return;
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-1);
}