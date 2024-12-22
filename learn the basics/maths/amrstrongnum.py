import math
def armstrong(n):
    power = len(str(n))
    sumnum = 0
    temp = n
    while temp!=0:
        lt = temp%10
        sumnum += lt**power
        temp//=10
    return sumnum==n
n = 153
print(armstrong(n))

n = 123
print(armstrong(n))