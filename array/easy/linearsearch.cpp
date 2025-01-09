#include <iostream>
using namespace std;
/*
here we are taking the array and the specific element as input and then we will iterate through the array
and if any thing matches to the input k we taken we will return true or in the end return false
tc:O(n) sc:O(1)
*/
bool linearsearch(vector <int> arr,int k){
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==k) return true;
    }return false;
}