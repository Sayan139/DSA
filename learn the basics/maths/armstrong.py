import math
def armstrong(n):
    power = int(math.log10(n)+1)
    sum = 0,temp = n
    while temp != 0:
        lt = temp%10
        sum += lt**power
        temp //= 10
    return sum==n