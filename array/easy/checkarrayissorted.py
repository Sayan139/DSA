def check_array_sorted(arr):
    for i in range(1,len(arr)):
        if arr[i] < arr[i-1]:
            return False
    return True
def check_if_sorted_or_rotated(arr):
    count = 0
    for i in range(1,len(arr)):
        if arr[i] < arr[i-1]:
            count+=1
    if arr[len(arr)-1]>arr[0]:
        count+=1
    return count<=1
arr = [1, 2, 3, 4, 5]
if check_array_sorted(arr):
    print("Array is sorted.")
else:
    print("Array is not sorted.")