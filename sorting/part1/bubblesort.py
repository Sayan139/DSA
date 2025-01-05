def bubblesort(arr):
    for i in range(len(arr)-1,0,-1): #here it will not reach till 0 but not needed as when it will come there the array is aldready sorted thats why no need but we can use -1 in order to reach till 0
        is_swaped = False
        for j in range(0,i):
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
                is_swaped = True
        if not is_swaped:
            return
arr = [64, 25, 12, 22, 11]
bubblesort(arr)
print(arr)