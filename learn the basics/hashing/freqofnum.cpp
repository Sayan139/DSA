#include <iostream>
using namespace std;
int main(){
	int arr[] = {3,6,4,4,3,2,1,9,10,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int hash[11]={0};
	for(int i=0; i<n; i++){
		hash[arr[i]]+=1;
	}
	cout << "number : ocuurance" << endl;
	for(int i=0; i<11; i++){
		cout << i << " : " << hash[i] << endl;
	}
	return 0;
}