def largetsele(arr):
    largest = -(2**31)
    for i in range(0,len(arr)):
        if arr[i] > largest:
            largest = arr[i]
    return largest
array = [1, 2, 3, 4, 5]
print(f"the largest is : {largetsele(array)}")