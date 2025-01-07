# this is type 1 problem 
# here In this case, we are given the row number r and the column number c, and we need to find out the element at position (r,c).
# to solve the problem we need to use a formula of combination
# her we have to use the formula nCr = n! / (r! * (n-r)!)
# for this question its n-1Cr-1 = 
# ok list while solving it it might take more time so to eliminate it we can use
# a tactics thats take n! and below it r! and there is (n-r)! so if we subtract r from n then 
# we will have some common elements in n! is getting subtraacted why should we again and again do it
# so thats why we will not iterate till thats why we will iterate till num of r and r-i values  simple!
# Time Complexity: O(c), where c = given column number.
# Reason: We are running a loop for r times, where r is c-1.

# Space Complexity: O(1) as we are not using any extra space.
def ncr(n,r):
    result = 1
    for i in range(r):
        result = result * (n-i)
        result = result / (i+1)
    return result
def pascalstraingle(n,r):
    element = ncr(n-1,r-1)
    return element
# now coming to the type 2 problem here 
'''We will replicate this in our algorithm. First, we will mark the indices of the column starting from 0. Then we will simply multiply the numerator by (n-index) and the denominator by the index itself.

From column no. 1 the formula will be the following:

Current element = prevElement * (rowNumber - colIndex) / colIndex
Approach:

The steps are as follows:

First, we will print the 1st element i.e. 1 manually.
After that, we will use a loop(say i) that runs from 1 to n-1. It will print the rest of the elements.
Inside the loop, we will use the above-said formula to print the element. We will multiply the previous answer by (n-i) and then divide it by i itself.
Thus, the entire row will be printed.
Time Complexity: O(N) where N = given row number. Here we are using only a single loop.

Space Complexity: O(1) as we not using any extra space.'''
def pascalstraingle(n):
    ans = 1
    print(f"{ans} ",end="")
    for i in range(1,n):
        ans = ans * (n-i)
        ans  = ans//i
        print(f"{ans} ",end="")
    print()
'''
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
'''
def generaterow(row):
    ans = 1
    ans_row = []
    ans_row.append(ans)
    for col in range(1,row):
        ans = ans * (row - col)
        ans = ans // col
        ans_row.append(ans)
    return ans_row
def pascalstrainglewhole(n):
    ans = []
    for row in range(1,n+1):
        ans.append(generaterow(row))
    return ans