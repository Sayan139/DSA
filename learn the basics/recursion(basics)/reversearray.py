def reversearray(arr,start,end):
    if start >= end:
        return
    arr[start],arr[end]=arr[end],arr[start]
    reversearray(arr,start+1,end-1)