#include <bits/stdc++.h>
using namespace std;
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