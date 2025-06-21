#include <iostream>
using namespace std;
void bubblesort(vector<int> &arr){
    for(int i=arr.size(); i>=0; i--){
        for(int j=0; j < i; j++){
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}