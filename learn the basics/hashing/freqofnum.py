arr = [3, 6, 4, 4, 3, 2, 1, 9, 10, 2]
n = len(arr)
hash = [0] * 11

for num in arr:
    hash[num] += 1

print("number : occurrence")
for i in range(11):
    print(f"{i} : {hash[i]}")
