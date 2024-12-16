#include <iostream>
using namespace std;
bool canjump(vector <int> arr){
    int n = arr.size();
    int maxlen = 0;
    for(int i =0; i<n; i++){
        if(i>maxlen) return false;
        maxlen = max(maxlen,i+arr[i]);
    }
    return true;
}
int minjumpsgame(vector <int> arr){
    int n = arr.size();
    if(n<=1) return 0;
    if(arr[0]==0) return -1;
    int jumps = 0,currentend=0,farthest=0;
    for(int i=0; i<n; i++){
        farthest = max(farthest,i+arr[i]);
        if(i==farthest){
            jumps++;
            currentend = farthest;
            if(currentend >= n-1){
                return jumps;
            }
        }
    }
    return -1;
}
int  main(){
    vector<int> arr = {2, 3, 1, 1, 4}; // Example input array
    int result = minjumpsgame(arr);
    
    if (result == -1) {
        cout << "Cannot reach the end of the array" << endl;
    } else {
        cout << "Minimum number of jumps to reach the end: " << result << endl;
    }
    return 0;
}