def insertionsort(arr,i,n):
    if i==n:
        return
    j=i
    while j>0 and arr[j-1]>arr[j]:
        arr[j-1],arr[j]=arr[j],arr[j-1]
        j-=1
    insertionsort(arr,i+1,n)
arr = [5, 2, 9, 1, 5, 6]
print("Original array:", arr)
insertionsort(arr,0,len(arr))
print("Sorted array:", arr)