def secondlargest(arr):
    largest = -(2**31)
    second_largest = -(2**31)
    for i in range(len(arr)):
        if arr[i] > largest:
            second_largest = largest
            largest = arr[i]
        elif arr[i] > second_largest and arr[i]!=largest:
            second_largest = arr[i]
    if second_largest==-(2**31):
        return -1
    return second_largest
def secondsmallest(arr):
    smallest = (2**31)-1
    second_smallest = (2**31)-1
    for i in range(len(arr)):
        if arr[i] < smallest:
            second_smallest = smallest
            smallest = arr[i]
        elif arr[i] < second_smallest and arr[i]!=smallest:
            second_smallest = arr[i]
    if second_smallest==(2**31)-1:
        return -1
    return second_smallest
arr = [12, 35, 1, 10, 34, 1]
print("Second largest:", secondlargest(arr))
print("Second smallest:", secondsmallest(arr))