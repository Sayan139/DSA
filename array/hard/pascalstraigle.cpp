#include <iostream>
using namespace std;
/*
this is type 1 problem 
here In this case, we are given the row number r and the column number c, and we need to find out the element at position (r,c).
to solve the problem we need to use a formula of combination
her we have to use the formula nCr = n! / (r! * (n-r)!)
for this question its n-1Cr-1 = 
ok list while solving it it might take more time so to eliminate it we can use
a tactics thats take n! and below it r! and there is (n-r)! so if we subtract r from n then 
we will have some common elements in n! is getting subtraacted why should we again and again do it
so thats why we will not iterate till thats why we will iterate till num of r and r-i values  simple!
Time Complexity: O(c), where c = given column number.
Reason: We are running a loop for r times, where r is c-1.

Space Complexity: O(1) as we are not using any extra space.
*/
int ncr(int n ,int r){
    int res = 1;
    for(int i=1; i<r; i++){
        res = res * (n-1);
        res = res / (i+1);
    }return res;
}
int pascalstraingle(int n,int r){
    int element = ncr(n,r);
    return element;
}
/*
this is type 2 where we need to print the specifice array of the pascals traingle
We will replicate this in our algorithm. First, we will mark the indices of the column starting from 0. Then we will simply multiply the numerator by (n-index) and the denominator by the index itself.

From column no. 1 the formula will be the following:

Current element = prevElement * (rowNumber - colIndex) / colIndex
Approach:

The steps are as follows:

First, we will print the 1st element i.e. 1 manually.
After that, we will use a loop(say i) that runs from 1 to n-1. It will print the rest of the elements.
Inside the loop, we will use the above-said formula to print the element. We will multiply the previous answer by (n-i) and then divide it by i itself.
Thus, the entire row will be printed.
Time Complexity: O(N) where N = given row number. Here we are using only a single loop.

Space Complexity: O(1) as we not using any extra space.
*/
void pascalstraingle(int n){
    int ans = 1;
    cout << ans << " ";
    for(int i=1; i<n; i++){
        ans *= (n-i);
        ans /= i;
        cout << ans << " ";
    }
    cout << endl;
}
/*
Now, in the optimal approach of variation 2, we have learned how to generate a row in O(n) time complexity. So, in order to optimize the overall time complexity, we will be using that approach for every row. Thus the total time complexity will reduce.

Approach:

The steps are as follows:

First, we will run a loop(say row) from 1 to n.
Inside the loop, we will call a generateRow() function and add the returned list to our final answer. Inside the function we will do the following:
First, we will store the 1st element i.e. 1 manually.
After that, we will use a loop(say col) that runs from 1 to n-1. It will store the rest of the elements.
Inside the loop, we will use the specified formula to print the element. We will multiply the previous answer by (row-col) and then divide it by col itself.
Thus, the entire row will be stored and returned.
Finally, we will return the answer list.
*/
vector <int> generaterow(int row){
    int ans = 1;
    vector <int> ans_array;
    ans_array.push_back(ans);
    for(int col = 1; col < row; col++){
        ans *= (row - col);
        ans /= col;
        ans_array.push_back(ans);
    }
    return ans_array;
}
vector <vector <int>> wholepascalstraingle(int n){
    vector <vector <int>> ans;
    for(int row = 1; row <= n; row++){
        ans.push_back(generaterow(row));
    }
    return ans;
}