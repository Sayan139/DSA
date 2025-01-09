#include <set>
#include <iostream>
using namespace std;
//Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.
/*
for the bruite force approach we are going to be simple and straight forward
here we are going to make 3 floops which will run till on every one of them as like this that 
the outer loop will run till n take them as i and now inside loop j will start running from i+1 till n
and then inside it there going to be a function which is going to run for j+1 like that and now we will make
a short vector containing all these 3 findings which result in summation as 0 and then we will sotre it in 
a set which we will declare outside the those for loop and it should be 2 or 3 d set to make 2d set
 we need to do set<vector <int>> like this it a bit complex but ok
*/
vector <vector <int>> bruite(vector <int> arr){
    int n = arr.size();
    set <vector <int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+ arr[j] + arr[k] == 0){
                    vector <int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector <vector <int>> ans(st.begin(),st.end());
    return ans;
}
/*
for the better solution we are using hashing and found the third num in the hash map because 
the hash map there almost constant tc so this could be helpful
Time Complexity: O(N2 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.
*/
vector <vector <int>> better(vector <int> arr){
    int n = arr.size();
    set <vector <int>> st;
    for(int i=0; i<n; i++){
        set <int> hashset;
        for(int j=i+1; j<n; j++){
            int third = - (arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end()){
                vector <int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector <vector <int>> ans(st.begin(),st.end());
    return ans;
}
// now coming to the optimal approach 
/*
here just simply we are using the two pointer approach in which there are going to be three pointers
from beginning we have loop for i and inside it we going to make a j and k which is going to for j = i+1 
and k is n-1 and then we will add each number and see what sum result and if grater than 0 we will reduce the
k and if less than 0 then move j and so one if its exactly 0 then we are going to add the value to answer and 
then reduce the k and increase the j and use the while loop to avoid the duplicate values 
*/
vector <vector <int>> optimal(vector <int> arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector <vector <int>> ans;
    for(int i=0; i<n; i++){
        if(i != 0  && arr[i]==arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                vector <int> temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++,k--;
                while (j < k && arr[j] == arr[j-1]) j++;
                while (j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}