#include <iostream>
using namespace std;
void insertionsort(vector <int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
}
int main(){

}