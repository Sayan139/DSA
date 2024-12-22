from collections import Counter

def hasharray(arr):
    hash_array = [0] * (len(arr) + 1)
    for num in arr:
        hash_array[num - 1] += 1
    return hash_array
#The frequency of an element is the number of times it occurs in an array.
#You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
#Return the maximum possible frequency of an element after performing at most k operations.
def maxfrew(arr, k):
    arr.sort()
    left, right = 0, 0
    result = 0
    total = 0
    while right < len(arr):
        total += arr[right]
        while arr[right] * (right - left + 1) > total + k:
            total -= arr[left]
            left += 1
        result = max(result, right - left + 1)
        right += 1
    return result

arr = [3, 4, 5, 6, 6, 7, 3, 2, 1, 3, 4, 6]
result = hasharray(arr)
print("Element frequencies:")
for i in range(len(result)):
    print(f"Element {i + 1}: {result[i]}")

# Example of using maxfrew
k = 3
print("Maximum frequency after at most", k, "operations:", maxfrew(arr, k))
