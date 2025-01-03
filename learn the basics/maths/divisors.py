import math
def divisor(n):
    divisor_list = []
    for i in range(1,math.sqrt(n)):
        if n%i==0:
            divisor_list.append(i)
            if i != n//i:
                divisor_list.append(n//i)
    return divisor_list
# Function to calculate ΣF(i) for i from 1 to n
def prob(n):
    total_sum = 0
    for i in range(1,n):
        total_sum += i * (n//i)
    return total_sum