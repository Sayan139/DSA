#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {4, 5, 6, 7, 2, 4, 5, 6, 2, 2};
    unordered_map<int, int> frequencyMap;

    for (int num : arr) {
        frequencyMap[num]++;
    }

    cout << "Number : Frequency" << endl;
    for (auto it : frequencyMap) { // Iterate through the unordered_map
        cout << it.first << " : " << it.second << endl; 
    }

    return 0;
}
