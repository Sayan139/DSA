#include <iostream>
using namespace std;
//You are given an array arr[] containing positive integers.
//The elements in the array arr[] range from 1 to n (where n is the size of the array), 
//and some numbers may be repeated or absent. 
//Your task is to count the frequency of all numbers in the range 1 to n and return an 
//array of size n such that result[i] represents the frequency of the number i (1-based indexing).
vector <int> frequencycount(vector <int> arr){
	int n = arr.size();
	vector <int> hash(arr.size(),0);
	for(int i=0; i<n; i++){
		if(arr[i]>=1 && arr[i]<=n){
			hash[arr[i]-1]++; // (-1) for 1 based indexing
		}
	}
	return hash;
}
int main() {
    vector<int> arr = {4, 5, 6, 7, 2};
    vector<int> result = frequencycount(arr);
    cout << "Frequency of numbers in range 1 to " << arr.size() << ":" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Number " << i + 1 << ": " << result[i] << endl;
    }
    return 0;
}