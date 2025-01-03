def palindrome(n):
    rev_num  = 0
    temp = n
    while n!=0:
        lt = n%10
        rev_num = (rev_num*10)+lt
        n//=10
    return rev_num==temp