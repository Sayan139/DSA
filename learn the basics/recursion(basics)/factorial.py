def factorial(n):
    if n==1:
        return 1
    return n * factorial(n-1)
'''factorial less than or equal to n:
A number n is called a factorial number if it is the factorial of a positive integer. For example, the first few factorial numbers are 1, 2, 6, 24, 120,
Given a number n, the task is to return the list/vector of the factorial numbers smaller than or equal to n.
this is simple solution here'''
def factorialist(n,arr,current_num,idx):
    if current_num * idx > n:
        return arr
    current_num *= idx
    arr.append(current_num)
    return factorialist(n,arr,current_num,idx+1)