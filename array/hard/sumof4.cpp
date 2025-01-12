#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
// for the bruite force soluyion
/*
its the same approach as the sum of 3 and its tc:O(n^4) which is very inefficient 
Time Complexity: O(N4), where N = size of the array.
Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting as we are just sorting 4 elements every time.

Space Complexity: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.
*/
vector <vector <int>> bruiteforce(vector <int> arr,int target){
    int n = arr.size();
    set <vector <int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; k<n; k++){
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target){
                        vector <int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector <vector <int>> ans(st.begin(),st.end());
    return ans;
}
// now coming to better approach
/* its also same as the previous one sum of 3 approach it reduces the tc:O(n^3) 
Time Complexity: O(N3*log(M)), where N = size of the array, M = no. of elements in the set.
Reason: Here, we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.

Space Complexity: O(2 * no. of the quadruplets)+O(N)
Reason: we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N). */
vector <vector <int>> better(vector <int> arr,int target){
    int n = arr.size();
    set <vector <int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set <long long> hashset;
            for(int k=j+1; k<n; k++){
                long long sum_num = arr[i] + arr[j];
                sum_num += arr[k];
                long long fourth = target - sum_num;
                if(hashset.find(fourth) != hashset.end()){
                    vector <int> temp = {arr[i],arr[j],arr[k],arr[fourth]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector <vector <int>> ans(st.begin(),st.end());
    return ans;
}
// now coming to the optimal apprach
/*
in this approach we cant reduce th tc: less than O(n^3) but we can reduce the space complexity
Time Complexity: O(N3), where N = size of the array.
Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 

Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/
vector <vector <int>> optimal(vector <int> arr,int target){
    int n = arr.size();
    vector <vector <int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0; i<n; i++){
        if(i > 0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>0 && arr[j]==arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while( k< l){
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum == target){
                    vector <int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++,l--;
                    while(k <l && arr[k]==arr[k-1]) k++;
                    while(k <l && arr[l]==arr[l+1]) l--;
                }
                else if(sum  < target) k++;
                else l--;
            }
        }
    }
    return ans;
}
// question on sum4 2
/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
here the approach is simple her we have to find the constrains which is going to give the result of 0 
so we are going to use the concept of iterator as we dont want to store more elements in the function for
storing the we just using iterator now for the solving concept we are using the 
first we will run a nested loop for arr1 and arr2 which will iterate and find the all the possible a+b elments
in the two arrays ans store it in an hash array and other part is we now next iterate from array3 and array4
arr4 where we are going to find the target we need to find in the hash set we will do it by adding the iterator elements
of arr3 and arr4 to and in then find the remaining num to be add to the squence to meet 0 we will find that in the hashmap and 
thenr eturn the count
*/
int foursumcount(vector <int> arr1,vector <int> arr2,vector <int> arr3,vector <int> arr4){
    unordered_map<int,int> mpp;
    int count = 0;
    for(int a : arr1){
        for(int b : arr2){
            mpp[a+b]++;
        }
    }
    for(int c : arr3){
        for(int d : arr4){
            int target = -(c+d);
            if(mpp.find(target)!=mpp.end()) count += mpp[target];
        }
    }
    return count;
}