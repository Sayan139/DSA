#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str = "hello world";  // Input string
    unordered_map<char, int> hash_map;  // Create an unordered_map to store character frequencies

    // Counting the frequency of each character in the string
    for (char ch : str) {
        hash_map[ch]++;  // Increment the frequency of the character
    }

    // Printing the character frequencies
    cout << "Character : Frequency" << endl;
    for (const auto& pair : hash_map) {
        cout << pair.first << " : " << pair.second << endl;  // pair.first is the character, pair.second is the frequency
    }

    return 0;
}
