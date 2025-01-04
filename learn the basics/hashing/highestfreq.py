def hasharray(arr):
    n = len(arr)
    hash_array = [0] * n
    for i in range(n):
        hash_array[arr[i]]+=1
    return hash_array
# frequency of the most frequent element
''' this is a sliding window problem here we have to sort the array before doing the question
question:Return the maximum possible frequency of an element after performing at most k operations.
in simple words you are given a value k you need to convert as many number to a num present in the array
equal and count them thats it
now the approach is take the left and right element and a total and result her we will move the
right part only one by one and add the values to the total so that we can count the total value
and now we will check if the right pointer index (where the distinct num is present ) if that number 
is multiplier to the number of index we travered (it means if we make all the past number same as the right
pointer number) is it going to be greater than the total+k(why k you say because the toal would be expected total of the total and k )
and of this is greater than that then we have to reduce the range by reducig the left part index element from total
and increasing the left(reducing the range) now this is to check and fix but in normal cases we would 
calculate the how much we are increasing and store the max of it and move forward the right index pointer
and at the end return the simple result.'''
def freq(arr,k):
    n = len(arr)
    arr.sort()
    left = 0,right =0,result = 0,total = 0
    while right < n:
        total += arr[right]
        while arr[right] * (right-left+1) > total + k:
            total -= arr[left]
            left+=1
        result = max(result,right-left+1)
        right+=1
    return result
