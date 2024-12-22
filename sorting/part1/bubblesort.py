def bubblesort(arr):
    n = len(arr)
    for i in range(n-1,-1,-1):
        didswap = 0
        for j in range(0,i):
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
                didswap=1
        if didswap==0:
            break
arr = [5, 2, 9, 1, 5, 6]
print(f"unsorted array: {arr}")
bubblesort(arr)
print(f"after aplying bubble sort: {arr}")