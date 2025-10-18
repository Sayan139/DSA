#include <bits/stdc++.h>
using namespace std;

/*
1️⃣ With Duplicates in Input
*/
vector<int> findUnionWithDuplicates(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    vector<int> temp;

    while(i < n && j < m) {
        if(a[i] <= b[j]) {
            if(temp.empty() || temp.back() != a[i]) temp.push_back(a[i]);
            i++;
        } else {
            if(temp.empty() || temp.back() != b[j]) temp.push_back(b[j]);
            j++;
        }
    }

    while(i < n) {
        if(temp.empty() || temp.back() != a[i]) temp.push_back(a[i]);
        i++;
    }
    while(j < m) {
        if(temp.empty() || temp.back() != b[j]) temp.push_back(b[j]);
        j++;
    }

    return temp;
}

/*
2️⃣ No Duplicates in Input
*/
vector<int> findUnionNoDuplicates(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    vector<int> result;

    while(i < n && j < m) {
        if(a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while(i < n) result.push_back(a[i++]);
    while(j < m) result.push_back(b[j++]);

    return result;
}
