#include <iostream>
using namespace std;
// Bruite force Approach: 

// The algorithm steps are as follows:

// We will run a loop(say i) from 1 to N.
// For each integer, i, we will try to find it in the given array using linear search.
// For that, we will run another loop to iterate over the array and consider a flag variable to indicate if the element exists in the array. Flag = 1 means the element is present and flag = 0 means the element is missing.
// Initially, the flag value will be set to 0. While iterating the array, if we find the element, we will set the flag to 1 and break out from the loop.
// Now, for any number i, if we cannot find it, the flag will remain 0 even after iterating the whole array and we will return the number.

int bruite(vector <int> arr,int n){
    for(int i=1; i<=n; i++){
        int flag =0;
        for(int j=0; j<n-1; j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
    }
    return -1;
}


// using hashing 
// better Approach:

// The algorithm steps are as follows:

// The range of the number is 1 to N. So, we need a hash array of size N+1 (as we want to store the frequency of N as well).
// Now, for each element in the given array, we will store the frequency in the hash array.
// After that, for each number between 1 to N, we will check the frequencies. And for any number, if the frequency is 0, we will return it.
int better(vector<int> arr, int n){
    vector <int> count(n+1,0);
    for (int i = 0; i < n - 1; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) return i;
    }

    return -1;
}


//optimal approach 1:
// using sum
// We will first calculate the summation of first N natural numbers(i.e. 1 to N) using the specified formula.
// Then we will add all the array elements using a loop.
// Finally, we will consider the difference between the summation of the first N natural numbers and the sum of the array elements.

int optimal1(vector <int> arr,int n){
    int summation = (n*(n+1))/2;
    int s2 = 0;
    for(int i=0; i<n-1; i++){
        s2 += arr[i];
    }
    int result = summation - s2;
    return result;
}

//optimal approach 2:
//  using xor 
// The steps are as follows:

// We will first run a loop(say i) from 0 to N-2(as the length of the array = N-1).
// Inside the loop, xor2 variable will calculate the XOR of array elements
// i.e. xor2 = xor2 ^ a[i].
// And the xor1 variable will calculate the XOR of 1 to N-1 i.e. xor1 = xor1 ^ (i+1).
// After the loop ends we will XOR xor1 and N to get the total XOR of 1 to N.
// Finally, the answer will be the XOR of xor1 and xor2.

int optimal2(vector <int> arr,int n){
    int xor1=0,xor2=0;
    for(int i=0; i<n-1; i++){
        xor2 = xor2^arr[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^n;
    return (xor1^xor2);
}