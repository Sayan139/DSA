def selectionsort(arr):
    n = len(arr)
    for i in range(0,n):
        mini = i
        for j in range(i+1,n):
            if arr[j] < arr[mini]:
                mini = j
        arr[mini],arr[i]=arr[i],arr[mini]
arr = [5, 2, 9, 1, 5, 6]
print(f"unsorted array: {arr}")
selectionsort(arr)
print(f"sorted array: {arr}")