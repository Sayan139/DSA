def insertionsort(arr):
    n = len(arr)
    for i in range(0,n):
        j=i
        while j>0 and arr[j-1] > arr[j]:
            arr[j-1],arr[j]=arr[j],arr[j-1]
            j-=1
arr = [5, 2, 9, 1, 5, 6]
print(f"unsorted array: {arr}")
insertionsort(arr)
print(f"sorted array: {arr}")