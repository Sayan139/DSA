#include <bits/stdc++.h>
using namespace std;
/*
this is a bruite force approach:
Intuition: For each number between 1 to N, we will try to count the occurrence in the given array using linear search. And the element with occurrence as 2 will be the repeating number and the number with 0 occurrences will be the missing number.

Approach:

The steps are as follows:

We will run a loop(say i) from 1 to N.
For each integer, i, we will count its occurrence in the given array using linear search.
We will store those two elements that have the occurrence of 2 and 0.
Finally, we will return the elements.

Time Complexity: O(N2), where N = size of the given array.
Reason: Here, we are using nested loops to count occurrences of every element between 1 to N.

Space Complexity: O(1) as we are not using any extra space.
*/
vector <int> bruite(vector <int> arr){
    int n = arr.size();
    int repeating = -1,missing = -1;
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(arr[j]==i) cnt++;
        }
        if(cnt == 2) repeating = i;
        if(cnt == 0) missing = i;
        if(repeating == -1 && missing == -1){
            break;
        }
    }
    return {repeating,missing};
}
/*
now coming to the better approach 
Instead of counting the occurrences every time, using the hashing technique, we will store the frequency of each element between 1 to N. Now, the element with frequency 2 will be the repeating number and the element with frequency 0 will be the missing number.

Note: Here, we can solve this problem using a hash array.

Approach:

The steps are as follows:

The range of the number is 1 to N. So, we need a hash array of size N+1 (as we want to store the frequency of N as well).
We will iterate all the elements of the given array and update the hash array accordingly i.e. hash[a[i]] = hash[a[i]]+1.
Now, we will iterate on the hash array and return the two elements with frequencies 2 and 0.
Time Complexity: O(2N), where N = the size of the given array.
Reason: We are using two loops each running for N times. So, the time complexity will be O(2N).

Space Complexity: O(N) as we are using a hash array to solve this problem.
*/
vector <int> better(vector <int> arr){
    int n = arr.size();
    vector <int> hash_array(n+1,0);
    for(int i=0; i<n; i++){
        hash_array[arr[i]]++;
    }
    int repeating = -1,missing = -1;
    for(int i=1; i<=n; i++){
        if(hash_array[i]==2) repeating = i;
        else if(hash_array[i]==0) missing = i;
        if(repeating != -1 && missing != -1) break;
    } return {repeating,missing};
}
/*
now coming to the optimal sol 1:
Intuition:

The idea is to convert the given problem into mathematical equations. Since we have two variables i.e. missing and repeating, we will try to form two linear equations. And then we will find the values of two variables using those equations.

Assume the repeating number to be X and the missing number to be Y.

In the array, the numbers are between 1 to N, and in that range, one number is missing and one number is occurring twice.

Step 1: Form equation 1:

Now, we know the summation of the first N numbers is:

Sn = (N*(N+1))/2
Let’s say, S = the summation of all the elements in the given array.

Therefore, S - Sn = X - Y…………………equation 1
Step 2: Form equation 2:

Now, we know the summation of squares of the first N numbers is:

S2n = (N*(N+1)*(2N+1))/6
Let’s say, S2 = the summation of squares of all the elements in the given array.

Therefore, S2-S2n = X2-Y2...................equation 2
From equation 2 we can conclude,

X+Y = (S2 - S2n) / (X-Y) [From equation 1, we get the value X-Y] ………… equation 3
From equation 1 and equation 3, we can easily find the value of X and Y. And this is what we want.

Note: Here, we are summing all the numbers and squares of all the numbers, so we should use a bigger data type(Like in C++, long long instead of int).

Approach:

Assume the repeating number to be X and the missing number to be Y.

The steps are as follows:

First, find out the values of S and Sn and then calculate S - Sn (Using the above formulas).
Then, find out the values of S2 and S2n and then calculate S2 - S2n.
After performing steps 1 and 2, we will be having the values of X + Y and X - Y. Now, by substitution of values, we can easily find the values of X and Y.
Time Complexity: O(N), where N = the size of the given array.
Reason: We are using only one loop running for N times. So, the time complexity will be O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
vector <int> optimal1(vector <int> arr){
    int n = arr.size();
    long long sn = (n*(n+1))/2; // sum all the elements from 1 to n
    long long sn2 = ((n*(n+1)/2)*(2*n+1))/6; // sum of all the elements from 1^2 to n^2
    long long s = 0, s2 = 0; 
    for(int i=0; i<n; i++){ // sum all the i and i^2 elements
        s+=arr[i];
        s2 += (long long)arr[i]*(long long)arr[i];
    }
    long long val1 = s - sn; // here we are subtracting the n num of elements with the sum of arr elements to get a number but the number is formed by two num x and y which are 
    // no repeating and another is missing we have to find it and the equation we take is something like x-y=val1 (you understood?) the value we finding the equation so now to complete
    // the equation we are making another square equation
    long long val2 = s2 - sn2; // same goes here but for squares
    // and in these square equation x^2-y^2 the formula is (x+Y)(x-y) and we got the answer of x-y in val1 so we will use it like (x+y)(x-y)=vol2 and now x+y = vol2/(x-y) and then x+y=vol2/vol1
    val2 = val2/val1; // now we got (x+y)
    long long x = (val1+val2)/2; // now to find x we used  use the elimination method which result 2x=val1+val2 and then x=(val1+val2)/2
    long long y = x - val1; // and y is easy as we need to do x - (x-y) or x - x + y = vol1 so y =  x - vol1
    return {(int)x,(int)y};
}
/*
Optimal Approach 2 (Using XOR): 

Using XOR, we are going to solve this problem using the following 3 steps.

Assume the repeating number to be X and the missing number to be Y.

Step 1: Find the XOR of the repeating number(X) and the missing number(Y)
i.e. (X^Y) = (a[0]^a[1]^.....^a[n-1]) ^ (1^2^........^N)

In order to find the XOR of the repeating number and the missing number, we will first XOR all the array elements and with that value, we will again XOR all the numbers from 1 to N.
(X^Y) = (a[0]^a[1]^.....^a[n-1]) ^ (1^2^3^........^N)
Step 2: Find the first different bit from right between the repeating and the missing number i.e. the first set bit from right in (X^Y)

By convention, the repeating and the missing number must be different and since they are different they must contain different bits. Now, our task is to find the first different bit from the right i.e. the end. We know, the XOR of two different bits always results in 1. The position of the first different bit from the end will be the first set bit(from the right) in (X^Y) that we have found in step 1.
Step 3: Based on the position of the different bits we will group all the elements ( i.e. all array elements + all elements between 1 to N) into 2 different groups

Assume an imaginary array containing all the array elements and all the elements between 1 to N. Now, we will check that particular position for each element of that imaginary array and then if the bit is 0, we will insert the element into the 1st group otherwise, we will insert it into the 2nd group. 
After performing this step, we will get two groups. Now, if we XOR all the elements of those 2 groups, we will get 2 numbers. One of them will be the repeating number and the other will be the missing number. But until now, we do not know which one is repeating and which one is missing.
Last step: Figure out which one of the numbers is repeating and which one is missing

We will traverse the entire given array and check which one of them appears twice. And the number that appears twice is the repeating number and the other one is the missing number.
Approach:

The steps are as follows:

For the first step, we will run a loop and calculate the XOR of all the array elements and the numbers between 1 to N. Let’s call this value xr.
In order to find the position of the first set bit from the right, we can either use a loop or we can perform AND of the xr and negation of (xr-1) i.e. (xr & ~(xr-1)).
Now, we will take two variables i.e. zero and one. Now, we will check the bit of that position for every element (array elements as well as numbers between 1 to N).
If the bit is 1: We will XOR that element with variable one.
If the bit is 0: We will XOR that element with variable zero.
Finally, we have two variables i.e. two numbers zero and one. Among them, one is repeating and the other is missing. It’s time to identify them. 
We will traverse the entire array and check how many times variable zero appears. 
If it appears twice, it will be the repeating number, otherwise, it will be the missing. Now, based on variable zero’s identity, we can easily identify in which category, variable one belongs.

Time Complexity: O(N), where N = the size of the given array.
Reason: We are just using some loops running for N times. So, the time complexity will be approximately O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
vector <int> optimal2(vector <int> arr){
    int n = arr.size();
    int xr = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }
    int number = (xr & ~(xr-1));
    int zero = 0;
    int one = 0;
    for(int i=0; i<n; i++){
        if((arr[i]&number)!=0) one = one ^ arr[i];
        else zero = zero ^ arr[i];
    }
    for(int i=1; i<=n; i++){
        if((i&number)!=0) one = one ^ i;
        else zero = zero ^ i;
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==zero) cnt++;
    }
    if(cnt==2) return {zero,one};
    return {one,zero};
}