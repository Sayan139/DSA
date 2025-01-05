def insertionsort(arr):
    for i in range(len(arr)):
        j = i
        while j>0 and arr[j-1] > arr[j]:
            arr[j-1],arr[j]=arr[j],arr[j-1]
            j-=1
arr = [64, 25, 12, 22, 11]
insertionsort(arr)
print(arr)