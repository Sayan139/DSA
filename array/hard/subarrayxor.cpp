#include <bits/stdc++.h>
using namespace std;
/*
the bruite force approach is simple:
The steps are as follows:

Generate Subarrays: 
First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
Calculate XOR of the subarray: After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the XOR of all the elements(of that particular subarray).
Check the XOR and modify the count: If the XOR is equal to k, we will increase the count by 1.
Time Complexity: O(N3) approx., where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.
*/
int bruite(vector <int> arr,int k){
    int n = arr.size();
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int xorr = 0;
            for(int k=i; k<=j; k++){
                xorr = xorr^arr[k];
            }
            if(xorr==k)cnt++;
        }
    }
    return cnt;
}
/*
Approach:

The steps are as follows:

Generate Subarrays: 
First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
Calculate XOR of the subarray: Inside loop j, we will XOR the current element to the XOR of the previous subarray i.e. xorr = XOR(a[i….j-1]) ^ arr[j]. 
Check the XOR and modify the count: After calculating the XOR, we will check if the sum is equal to the given k. If it is, we will increase the value of the count.
Intuition: If we carefully observe, we can notice that to get the XOR of the current subarray we just need to XOR the current element(i.e. arr[j]) to the XOR of the previous subarray i.e. arr[i….j-1].

Assume previous subarray = arr[i……j-1]
current subarray = arr[i…..j]
XOR of arr[i….j] = (XOR of arr[i….j-1]) ^ arr[j]
This is how we can remove the third loop and while moving j pointer, we can calculate the XOR.

Time Complexity: O(N2), where N = size of the array.
Reason: We are using two nested loops here. As each of them is running for N times, the time complexity will be approximately O(N2).

Space Complexity: O(1) as we are not using any extra space.

*/
int better(vector <int> arr,int k){
    int n =arr.size();
    int cnt = 0;
    for(int i=0; i<n; i++){
        int xorr = 0;
        for(int j=i; j<n; j++){
            xorr = xorr ^ arr[j];
            if(xorr==k) cnt++;
        }
    }
    return cnt;
}
/*
now the optimal approach
in this optimal approach we are using to solve it by formula
Approach:

The steps are as follows:

First, we will declare a map to store the prefix XORs and their counts.
Then, we will set the value of 0 as 1 on the map.
Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
For each index i, we will do the following:
We will XOR the current element i.e. arr[i] to the existing prefix XOR.
Then we will calculate the prefix XOR i.e. xr^k, for which we need the occurrence.
We will add the occurrence of the prefix XOR xr^k i.e. mpp[xr^k] to our answer.
Then we will store the current prefix XOR, xr in the map increasing its occurrence by 1.
Question: Why do we need to set the value of 0 beforehand?
Let’s understand this using an example. Assume the given array is [3, 3, 1, 1, 1] and k is 3. Now, for index 0, we get the total prefix XOR as 3, and k is also 3. So, the prefix XOR xr^k will be = 3^3 = 0. Now, if the value is not previously set for the key 0 in the map, we will get the default value 0 and we will add 0 to our answer. This will mean that we have not found any subarray with XOR 3 till now. But this should not be the case as index 0 itself is a subarray with XOR k i.e. 3.
So, in order to avoid this situation we need to set the value of 0 as 1 on the map beforehand.
*/
int optimal(vector <int> arr,int k){
    int n = arr.size();
    int xr = 0;
    map<int,int>mpp;
    mpp[xr]++;
    int count = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ arr[i];
        int x = xr ^ k;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}