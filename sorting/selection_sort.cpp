#include <iostream>
using namespace std;
void selectionsort(vector<int> &arr){
    for(int i=0; i<arr.size()-1; i++){
        int mini = i;
        for(int j=0; j<arr.size(); j++){
            if(arr[j] < arr[mini]) mini = j;
        }
        swap(arr[mini],arr[i]);
    }
}