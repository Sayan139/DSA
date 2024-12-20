#include <iostream>
using namespace std;
void bubblesort(vector <int> &arr){
    int n = arr.size();
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    bubblesort(arr);
    printarray(arr);
}