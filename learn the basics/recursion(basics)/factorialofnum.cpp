#include <iostream>
using namespace std;
int factorialofnum(int n){
    if(n==1) return 1;
    return n*factorialofnum(n-1);
}
vector <int> factoriallist(int n,vector <int> arr,int currnum,int idx){
    if(currnum * idx > n){
        return arr;
    }
    currnum *= idx;
    arr.push_back(currnum);
    return factoriallist(n,arr,currnum,idx+1);
}
int main() {
    int n = 100;
    vector<int> arr = {1};
    vector<int> result = factoriallist(n, arr, 1, 2);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}