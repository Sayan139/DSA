import math
def primecheck(n):
    if(n==1):
        return False
    if(n==2 or n==3):
        return True
    if(n%2==0 or n%3==0):
        return False
    for i in range(5,int(math.sqrt(n))+1,6):
        if n%i==0 or n%(i+2)==0:
            return False
    return True
n = int(input("Enter a number: "))

if primecheck(n):
    print(f"{n} is a prime number.")
else:
    print(f"{n} is not a prime number.")