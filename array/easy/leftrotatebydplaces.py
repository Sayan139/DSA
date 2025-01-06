# Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.
# bruite force aldready done in copy:
# optimal also done in the copy

# this is the optimal approach
def reverse(arr, i, j):
    while i < j:
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1

def rotate_the_array_k_times(arr, k):
    n = len(arr)
    k = k % n
    if k == 0: return
    reverse(arr, 0, n - k - 1)
    reverse(arr, n - k, n - 1)
    reverse(arr, 0, n - 1)
