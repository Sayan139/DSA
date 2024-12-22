def printrecursion(n, s):
    if n == 0:
        return
    print(s, end=" ")
    printrecursion(n - 1, s)

n = int(input("Enter the number of times you want to print: "))
s = input("Enter what you want to print: ")
printrecursion(n, s)
