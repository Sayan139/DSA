''' this is quick sort algo
here this is also divide and conquer rule but more optimised tha merge sort

'''
def partition(arr,low,high):
    pivot = arr[low]
    i = low  
    j = high
    while i < j:
        while arr[i] <= pivot and i <= high:
            i+=1
        while arr[j] > pivot and j >= low +1:
            j-=1
        if i < j:
            arr[i],arr[j]=arr[j],arr[i]
    arr[low],arr[j] = arr[j],arr[low]
    return j
def quicksort(arr,low,high):
    if low < high:
        pindex = partition(arr,low,high)
        quicksort(arr,low,pindex-1)
        quicksort(arr,pindex+1,high)
arr = [4, 6, 2, 5, 7, 9, 1, 3]
print("Before using QuickSort:")
print(arr)

quicksort(arr,0,len(arr)-1)  # Sort the array in-place

print("After using QuickSort:")
print(arr)