def oneton(n):
    if n==1:
        return
    oneton(n-1)
    print(n)
def ntoone(n):
    if n==1:
        return
    print(n)
    ntoone(n-1)