def largestele(arr):
    largest = -2**31
    for i in range(len(arr)):
        if arr[i] > largest:
            largest = arr[i]
    return largest
arr = [56,3,43,23,24,64,67,55]
print(f"the largest num: {largestele(arr)}")