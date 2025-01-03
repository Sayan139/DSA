# question : https://www.geeksforgeeks.org/problems/jump-game/1
def jumpgame1(arr):
    n = len(arr)
    maxlen = 0
    for i in range(n):
        if i > maxlen:
            return False
        maxlen = max(maxlen,i+arr[i])
    return True
# question : https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
def jumpgame2(arr):
    n = len(arr)
    if n<0:
        return 0
    if arr[0] == 0:
        return -1
    jumps = 0
    current_index= 0
    farthest = 0
    for i in range(n):
        farthest = max(farthest,i+arr[i])
        if i == current_index:
            jumps+=1
            current_index = farthest
            if current_index >= n-1:
                return jumps
    return -1