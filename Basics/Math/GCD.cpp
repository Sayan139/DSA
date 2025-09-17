#include <bits/stdc++.h>
using namespace std;
// bruite force and better :
/*
bruite:
here you need to iterate till the smaller element out of them 2 num and find the
greatest num that divides both and its going to be ans if not found any mathc return n * m
better : 
here you just need to iterate from the min(n,m) to 1 instead of 1 to min(n,m) its gives the ans
faster
tc : O(min(n,m)) sc : O(1)
*/
// optimal sol : using Euclidean Algorithm is a method 
/*
To find the GCD of n1 and n2 where n1 > n2:
Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
Once one of them becomes 0, the other number is the GCD of the original numbers.
This subtracting method works but still slow to make it more optimal we are using % to reduce 
the bigger num much more faster than the subtraction 
tc : O(min(n,m)) sc : O(1)
*/
int sol(int n,int m){
    while(n > 0 && m > 0){
        if(n > m){
            n = n%m;
        }else{
            m = m%n;
        }
    }
    if(n == 0){
        return m;
    }
    return n;
}