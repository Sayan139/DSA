str = "sayan biswas"
hash_map = {}
for i in str:
    hash_map[i] = hash_map.get(i,0)+1
print(hash_map)