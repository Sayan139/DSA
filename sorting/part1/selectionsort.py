def selectionsort(arr):
    for i in range(len(arr)):
        mini  = i
        for j in range(i+1,len(arr)):
            if arr[j] < arr[mini]:
                mini = j
        arr[mini],arr[i]=arr[i],arr[mini]
arr = [64, 25, 12, 22, 11]
selectionsort(arr)
print("Sorted array:", arr)