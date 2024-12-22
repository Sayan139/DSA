def print1ton(n):
    if n == 0:
        return
    print1ton(n - 1)
    print(n, end=" ")

def printnto1(n):
    if n == 0:
        return
    print(n, end=" ")
    printnto1(n - 1)

n = int(input("How much you want to print: "))
print("n to 1:")
printnto1(n)
print()
print("1 to n:")
print1ton(n)
print()
