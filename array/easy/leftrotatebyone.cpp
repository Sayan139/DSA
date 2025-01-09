#include <iostream>
using namespace std;
/*
here in this approach as we need to rotate one step so it can be right or left so we are going to have
two varient of this question
*/
/*
variant 1 : here we have to right rotate the array by one so
in order to do it we will store the last element in x and right shift other element till n-1
and then assign the value stored in x to the first element
Time Complexity: O(n), as we iterate through the array only once.

Space Complexity: O(1) as no extra space is used
*/
void rightrotate(vector <int>& arr){
    int temp = arr[arr.size()-1];
    for(int i=1; i<arr.size(); i++){
        arr[i] = arr[i-1];
    }arr[0] = temp;
}
/*
here in the second variant we need to left rotate so
we need to save the first element in a temp variable and left shift all the element from 1 to n-1
and then assign the value of temp to n-1 index
same tc and sc
*/
void leftrotate(vector <int>& arr){
    int n = arr.size();
    int temp = arr[0];
    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }arr[n-1] = temp;
}