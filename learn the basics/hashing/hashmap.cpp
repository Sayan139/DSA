#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Creating a hash map (unordered_map in C++)
    unordered_map<string, int> hash_map;

    // Adding key-value pairs
    hash_map["apple"] = 5;
    hash_map["banana"] = 10;

    // Accessing values by key
    cout << hash_map["apple"] << endl;  // Output: 5

    // Checking if a key exists
    if (hash_map.find("banana") != hash_map.end()) {
        cout << "Banana is in the hash map." << endl;
    }

    // Removing a key-value pair
    hash_map.erase("apple");

    // Iterating over key-value pairs
    for (const auto& pair : hash_map) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
