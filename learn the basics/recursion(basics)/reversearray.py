def reverseArray1(arr):
    i = 0
    e = len(arr) - 1
    while i < e:
        arr[i], arr[e] = arr[e], arr[i]
        i += 1
        e -= 1

def helperfunction(arr, start, end):
    if start > end:
        return
    arr[start], arr[end] = arr[end], arr[start]
    helperfunction(arr, start + 1, end - 1)

def reverseArray2(arr):
    helperfunction(arr, 0, len(arr) - 1)

arr = [1, 2, 3, 4, 5]
reverseArray1(arr)
print("Reversed using reverseArray1:", arr)

arr2 = [1, 2, 3, 4, 5]
reverseArray2(arr2)
print("Reversed using reverseArray2:", arr2)
