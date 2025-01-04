''' this is the Frequencies in a Limited Array problem 
and the problem statement is : You are given an array arr[] containing positive integers. The elements in the array arr[] range from 1 to n (where n is the size of the array), and some numbers may be repeated or absent. Your task is to count the frequency of all numbers in the range 1 to n and return an array of size n such that result[i] represents the frequency of the number i (1-based indexing).
so the conecept is simple just hash the values and mind that store them in the i-1 index as its one based indexing'''
def limitedfreq(arr):
    n = len(arr)
    ans = [0] * n
    for i in range(n):
        if arr[i] <= 0 or arr[i] > n:
            raise ValueError(f"Element {arr[i]} out of valid range 1 to {n}")
        ans[arr[i]-1]+=1
    return ans