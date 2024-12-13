def countnum(n):
    if(n==0):
        return 0 #this is  used to handle the edge case when the value of n is 0
    count = 0
    while(n!=0):
        count+=1
        n//=10 #here double // means divide or we can say overall this will not return any float value
    return count
n = int(input("enter the number : "))
print(f"the num of digits in the number {n} is : {countnum(n)}")