#include <iostream>
using namespace std;
int main(){
    int arr[] = {3,4,6,3,2,35,2,5,6,3,6,8,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 35;
    for(int i=0; i<size; i++){
        if(arr[i]==n) cout<<"true";
    }
    
}