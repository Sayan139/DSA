def bubblesort(arr,n):
    if(n==1):
        return
    didswap = 0
    for j in range(n-1):
        if arr[j] > arr[j+1]:
            arr[j],arr[j+1]=arr[j+1],arr[j]
            didswap = 1
    if didswap==0:
        return
    bubblesort(arr,n-1)
arr = [5, 2, 9, 1, 5, 6]
print("Original array:", arr)
bubblesort(arr,len(arr))
print("Sorted array:", arr)