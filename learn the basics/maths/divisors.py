import math
def divisors(n):
    divisors_list = []
    sqrtn = int(math.sqrt(n))
    for i in range(1,sqrtn+1):
        if n%i==0:
            divisors_list.append(i)
            if i != n//i:
                divisors_list.append(n//i)
    return divisors_list
#Given a positive integer n, 
#The task is to find the value of Σi from 1 to n F(i) where function 
#F(i) for the number i is defined as the sum of all divisors of i.
def divisorstilln(n):
    sum = 0
    for i in range(1,n+1):
        sum += i * (n//i)
    return sum
