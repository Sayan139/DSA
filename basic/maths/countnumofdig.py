def countnumofdig(n):
    countnum = 0
    if(n==0):
        return 0
    while(n != 0):
        countnum += 1
        n = n//10
    return countnum
n = int(input("enter the value: "))
print(f"the num of digits {n} have : {countnumofdig(n)}")