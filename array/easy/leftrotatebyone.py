def leftrotatebyone(arr):
    x = arr[0]
    for i in range(len(arr)-2):
        arr[i] = arr[i+1]
    arr[len(arr)-1] = x