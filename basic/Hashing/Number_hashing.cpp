#include <iostream>
using namespace std;
int main(){
    vector <int> arr= {4,5,9,3,5,7,4,2,2};
    vector<int> freq(10,0);
    for(int i=0; i<arr.size(); i++){
        freq[arr[i]]++;
    }
    for(int i=0; i<freq.size(); i++){
        cout << i << " : " << freq[i] << endl; 
    }cout << endl;
}