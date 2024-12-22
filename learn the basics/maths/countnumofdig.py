import math
#bruite force approach
def countnum(n):
    if n==0:
        return 0
    count = 0
    while n!=0:
        count+=1
        n//=10
    return count
#optimal approach
def countnumopt(n):
    return math.floor(math.log10(n))+1 if n>0 else 1
# Function to count the number of digits in n that divide n evenly
def numofdigeven(n):
    if n==0:
        return 0
    count =0
    temp = n
    while temp!=0 :
        lt = temp%10
        if lt!=0 and n%lt==0:
            count+=1
        temp//=10
    return count
n = 443562
print(f"the num of dig is: {countnum(n)}")