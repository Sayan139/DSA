def canjump(arr):
    n = len(arr)
    maxlen = 0
    for i in range(n):
        if i > maxlen:
            return False
        maxlen = max(maxlen, i + arr[i])
    return True

def minjumpsgame(arr):
    n = len(arr)
    if n < 1:
        return 0
    if arr[0] == 0:
        return -1
    jumps = 0
    currentend = 0
    farthest = 0
    for i in range(n - 1):
        farthest = max(farthest, i + arr[i])
        if i == currentend:
            jumps += 1
            currentend = farthest
            if currentend >= n - 1:
                return jumps
    return -1

arr = [2, 3, 1, 1, 4]  # Example input array
result = minjumpsgame(arr)

if result == -1:
    print("Cannot reach the end of the array")
else:
    print("Minimum number of jumps to reach the end:", result)
