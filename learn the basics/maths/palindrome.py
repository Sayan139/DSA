def palindromebruite(n):
    if n<0:
        return False
    rev = 0
    temp = n
    while temp!=0:
        lt = temp%10
        rev = (rev*10)+lt
        temp//=10
    return rev==n
def plaindromecheckoptimal(n):
    ss = str(n)
    return True if ss == ss[::-1] else False
n = -121
print(f"palindrome status: {plaindromecheckoptimal(n)}")