#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeBySignOptimal(vector<int>& A) {
    int n = A.size();
    vector<int> ans(n,0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            ans[posIndex] = A[i];
            posIndex += 2;
        } else {
            ans[negIndex] = A[i];
            negIndex += 2;
        }
    }
    return ans;
}
vector<int> rearrangeBySignVar2(vector<int>& A) {
    int n = A.size();
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
    }

    int i = 0;
    int minSize = min(pos.size(), neg.size());
    for (int j = 0; j < minSize; j++) {
        A[2*j] = pos[j];
        A[2*j+1] = neg[j];
    }

    int index = 2*minSize;
    if (pos.size() > neg.size()) {
        for (int j = minSize; j < pos.size(); j++) A[index++] = pos[j];
    } else {
        for (int j = minSize; j < neg.size(); j++) A[index++] = neg[j];
    }

    return A;
}
int main() {
    // Variety 1
    vector<int> A1 = {1,2,-4,-5};
    vector<int> ans1 = rearrangeBySignOptimal(A1);
    cout << "Variety 1 Output: ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    // Variety 2
    vector<int> A2 = {1,2,-4,-5,3,4};
    vector<int> ans2 = rearrangeBySignVar2(A2);
    cout << "Variety 2 Output: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}
