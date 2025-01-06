def checkarrayissorted(arr):
    for i in range(len(arr)-1):
        if arr[i] > arr[i+1]:
            return False
    return True
# question to check whether the array is sorted and rotated
def sortedorrotated(arr):
    count = 0
    for i in range(1,len(arr)):
        if arr[i] < arr[i-1]:
            count+=1
    if arr[len(arr)-1] > arr[0]:
        count+=1
    return count<=1