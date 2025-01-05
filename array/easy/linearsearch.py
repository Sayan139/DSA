def linearsearch(arr,k):
    for i in range(len(arr)):
        if arr[i] == k:
            return True
    return False
arr = [3,4,6,3,2,35,2,5,6,3,6,8,3]
k = 3
if linearsearch(arr,k):
    print("its present")
else:
    print("its not present")