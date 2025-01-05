def sol(arr,n):
    if n==1:
        return
    didswap = False
    for i in range(n):
        if arr[i] > arr[i+1]:
            arr[i],arr[i+1]=arr[i+1],arr[i]
            didswap = True
    if not didswap:
        return 
    sol(arr,n-1)