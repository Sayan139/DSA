def largestele(arr):
    largest = -2**31
    for i in range(len(arr)):
        if arr[i] > largest:
            largest = arr[i]
    return largest