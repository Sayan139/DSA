#You are given an array arr[] containing positive integers.
#The elements in the array arr[] range from 1 to n (where n is the size of the array), 
#and some numbers may be repeated or absent. 
#Your task is to count the frequency of all numbers in the range 1 to n and return an 
#array of size n such that result[i] represents the frequency of the number i (1-based indexing).
def frequencycount(arr):
    n = len(arr)
    hash_array = [0] * n
    for num in arr:
        if 1 <= num <= n:
            hash_array[num - 1] += 1  # (-1) for 1-based indexing
    return hash_array

arr = [4, 5, 6, 7, 2]
result = frequencycount(arr)

print(f"Frequency of numbers in range 1 to {len(arr)}:")
for i in range(len(result)):
    print(f"Number {i + 1}: {result[i]}")
