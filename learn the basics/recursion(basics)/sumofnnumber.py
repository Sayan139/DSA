def sumofn(n):
    if n == 1:
        return 1
    return n + sumofn(n - 1)

def sumOfSeries(n):
    if n == 1:
        return 1
    return (n * n * n) + sumOfSeries(n - 1)

def main():
    n = int(input("Enter the value of the number n: "))
    
    print(f"The sum of the first {n} numbers is: {sumofn(n)}")
    print(f"The sum of the series 1^3 + 2^3 + ... + n^3 is: {sumOfSeries(n)}")

if __name__ == "__main__":
    main()
