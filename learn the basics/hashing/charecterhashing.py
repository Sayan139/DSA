string = "hello world"
hash_map = {}

for char in string:
    if char in hash_map:
        hash_map[char] += 1
    else:
        hash_map[char] = 1

print("Character : Frequency")
for char, freq in hash_map.items():
    print(f"{char} : {freq}")
