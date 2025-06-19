#include <iostream>
using namespace std;
void reverse(vector <int>& arr,int start,int end){
    if(start >= end) return;
    swap(arr[start],arr[end]);
    reverse(arr,start+=1,end-=1);
}
int main(){
    vector <int> arr = {3,4,6,7,8,9,34};
    reverse(arr,0,arr.size()-1);
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }cout << endl;
}