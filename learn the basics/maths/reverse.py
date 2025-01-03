def reverse(n):
    return int(str(n)[::-1]) # bad space complexity
def rerverse2(n):
    reverse_value = 0
    while n!=0:
        lt = n%10
        reverse_value = (reverse_value*10)+lt
        n//=10
    return reverse_value #constant space complecity
n = int(input("enter the value: "))
print(f"the reverse is: {reverse(n)}")