#include <bits/stdc++.h>
using namespace std;
bool sol1(vector<int>& arr,int target){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == target) return true;
    }return false;
}