# sum of n numbers
def sumofn(n):
    if n==1:
        return 1
    return n + sumofn(n-1) # simple soultion would be n*(n+1)/2 to get the answer
# sum of the cube of first n numbers
def sumofseries(n):
    if n==1:
        return 1
    return (n**3) + sumofseries(n-1) # (n*(n+1)/2)^3 for finding the sum of this series