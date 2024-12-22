def reverse(n):
    rev = 0
    sign = 1 if n>0 else -1
    n=abs(n)
    while n!=0:
        lt = n%10
        rev = (rev*10)+lt
        n//=10
    return rev*sign if -(2**31) <= rev*sign <= (2**31)-1 else 0
n = -123
print(f"reverse is : {reverse(n)}")
