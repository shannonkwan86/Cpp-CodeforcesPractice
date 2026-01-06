#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a;

    int x = sqrt(n);
    // int cnt = 0;
    // map<int, int> mp;
    vector<int> mp(n + 1, 0);
    for (int i = 1; i < x; i++)
    {
        for (int j = i + 1; j <= x; j++)
        {

            if (i * i + j * j <= n)
            {
                mp[i * i + j * j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 1)
            a.push_back(i);
    }
    cout << a.size() << endl;
    // sort(a.begin(), a.end());
    for (int i : a)
        cout << i << " ";
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}