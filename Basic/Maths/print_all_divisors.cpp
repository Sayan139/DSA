#include <bits/stdc++.h>
using namespace std;
/*
Brute Force:
Check every number from 1 to n.
If it divides n, store it as a factor.
🕒 TC: O(n) 💾 SC: O(1)
*/
void sol1(int n){
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            cout << i << " ";
    }
}
/*
optimal sol:
Only check till sqrt(n) — because divisors come in pairs.
If i divides n, then both i and n/i are factors.
Store both, and sort at the end to get ascending order.
🕒 TC: O(√n) 💾 SC: O(√n)
*/
int sol2(int n)
{
    vector<int> ans;
    int range = sqrt(n);
    for (int i = 1; i <= range; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i)
                ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}