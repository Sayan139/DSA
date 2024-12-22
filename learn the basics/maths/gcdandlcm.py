def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a
def lcm(a,b):
    return (a*b)//gcd(a,b)
a = 12
b = 32
print(f"gcd od the two num is : {gcd(a,b)}\n lcm of the two num is: {lcm(a,b)}")