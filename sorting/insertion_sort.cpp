#include <iostream>
using namespace std;
void insertionsort(vector<int> &arr){
    for(int i=0; i<=arr.size()-1; i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}