#include <iostream>
using namespace std;
//# Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.
/*
here the bruite force appproach can be using the concept of left rotate the array by 1 place by using it
the k number of times which is not going to be efficient
*/
/*
 now discussing on optimal apprach
ok so in order to do this question we need a concept that
when for exaples size of array is 5 and then the num of rotation is given 7 so as we know if we do 5 
rotaion of 7 rotation the array will return to its orginal form then why should we do what can we skip that
part so thats why inorder to reduce it we need to do k = k%n which in this example will result as 1 to this means we
need to move for only two step 0,1 so thats why in this case we will use this situation in this case so reduce the iterations
and then we will make a external reverse function the main function of the function is to reverse the selected 
index till some index as in c++ we have aldready built in so noo need here now we have to do the reverse part from 
0 to n-k-1 and then n-k till n-1 and then 0 to n-1 and thats how we are going to move the whole array
*/
void leftrotatek(vector <int> arr,int k){
    int n = arr.size();
    k = k%n;
    reverse(arr.begin(),arr.begin()+k); // here the reverse tyravel k time from 0 so it will travel till k-1 (pretty smart)
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
}