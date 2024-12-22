def factorialofnum(n):
    if n == 1:
        return 1
    return n * factorialofnum(n - 1)

def factoriallist(n, arr, currnum, idx):
    if currnum * idx > n:
        return arr
    currnum *= idx
    arr.append(currnum)
    return factoriallist(n, arr, currnum, idx + 1)

n = 100
arr = [1]
result = factoriallist(n, arr, 1, 2)

for i in result:
    print(i, end=" ")
