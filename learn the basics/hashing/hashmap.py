# Creating a hash map (dictionary)
hash_map = {}

# Adding key-value pairs
hash_map["apple"] = 5
hash_map["banana"] = 10

# Accessing values by key
print(hash_map["apple"])  # Output: 5

# Checking if a key exists
if "banana" in hash_map:
    print("Banana is in the hash map.")

# Removing a key-value pair
del hash_map["apple"]

# Iterating over key-value pairs
for key, value in hash_map.items():
    print(f"{key}: {value}")
