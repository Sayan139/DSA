'''this is algorithm for implementing merge sort
 this is a divide and conquer type of algo her we have to get a mid prtion of the array
 then recursively call it for the start fromt mid and mid+1 till end and we will continue this unil low is greater than high
 then we will use the merge funtion which will merge the array parts by storing it in temp array and then
 we will store it back to the actual array from the transfered index low'''
def merge(arr,low,mid,high):
    temp = []
    left = low
    right = mid+1
    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            temp.append(arr[left])
            left+=1
        else:
            temp.append(arr[right])
            right+=1
    while left <= mid:
        temp.append(arr[left])
        left+=1
    while right <= high:
        temp.append(arr[right])
        right+=1
    for i in range(len(temp)):
        arr[low+i] = temp[i]
def mergesort(arr,low,high):
    if low>=high:
        return
    mid = (high+low)//2
    mergesort(arr,low,mid)
    mergesort(arr,mid+1,high)
    merge(arr,low,mid,high)
arr = [64, 34, 25, 12, 22, 11, 90]
mergesort(arr, 0, len(arr) - 1)
print("Sorted array:", arr)