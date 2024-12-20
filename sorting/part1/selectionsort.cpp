#include <iostream>
using namespace std;
void selectionsortset(vector <int> &arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        int mini = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
void printarray(vector <int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    vector <int> arr = {10, 15 ,20,25 ,30 ,35 ,40 ,45, 5 ,50 };
    printarray(arr);
    selectionsortset(arr);
    printarray(arr);
}