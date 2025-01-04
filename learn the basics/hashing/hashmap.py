array = [10, 20, 10, 30, 20, 30, 40, 10, 50, 30, 20, 10, 40, 50, 50, 20, 30]
hash_map = {}
for i in array:
    hash_map[i] = hash_map.get(i,0)+1 #here get first insitialize the value of the key as 0 then increment it with +1
print(hash_map)