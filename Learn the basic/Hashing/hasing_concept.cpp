#include <bits/stdc++.h>
using namespace std;
void numberHashing(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> hash(maxVal + 1, 0);
    for (int num : arr) hash[num]++; // store frequency
    cout << "Frequency of 5: " << hash[5] << endl; // fetch in O(1)
}

/*
2️⃣ Character Hashing:
Here, we count how many times each character occurs.
Characters are mapped to indices using ASCII subtraction.
For lowercase letters, 'a' → 0, 'b' → 1, ..., 'z' → 25.
Example: For s = "banana", hash['a'-'a'] = 3, hash['b'-'a'] = 1, hash['n'-'a'] = 2.
🕒 TC: O(n) 💾 SC: O(26)
*/
void charHashing(string s) {
    vector<int> hash(26, 0);
    for (char c : s) hash[c - 'a']++;
    cout << "Frequency of 'a': " << hash['a' - 'a'] << endl;
}

/*
3️⃣ Hashing for Large Numbers:
When the range of numbers is too large for arrays (e.g., 10^9),
we use STL maps or unordered_maps.
map → Ordered (implemented as Red-Black Tree) → O(logN)
unordered_map → Hash Table → O(1) average
Example: arr = [2, 5, 28, 2, 139], then mp[2] = 2, mp[28] = 1.
*/
void mapHashing(vector<int>& arr) {
    unordered_map<int,int> mp;
    for (int num : arr) mp[num]++; // pre-store
    cout << "Frequency of 28: " << mp[28] << endl; // fetch in O(1)
}

/*
4️⃣ Division Method (Hash Function Example):
We can also map elements to smaller hash table indices using modulo (k % m).
This is useful when we have limited memory.
Example: arr = [2, 5, 16, 28, 139], m = 10
We store each element in hash[num % 10].
If two numbers give same remainder, we store them in a list at that index (chaining).
🕒 TC: O(n) 💾 SC: O(m)
*/
void divisionHashing(vector<int>& arr, int m) {
    vector<vector<int>> hash(m);
    for (int num : arr)
        hash[num % m].push_back(num);

    // Example fetch
    int key = 28;
    int idx = key % m;
    cout << "Elements at index " << idx << ": ";
    for (int x : hash[idx]) cout << x << " ";
    cout << endl;
}
int main() {
    vector<int> arr = {2, 5, 16, 28, 139};
    string s = "banana";

    numberHashing(arr);
    charHashing(s);
    mapHashing(arr);
    divisionHashing(arr, 10);

    return 0;
}
