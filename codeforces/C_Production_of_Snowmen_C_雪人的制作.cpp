#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> c(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    // map<int, int> mp;
    int tp = 0;
    for (int ad = 0; ad < n; ad++)
    {
        bool fg = true;
        for (int j = 0; j < n; j++)
            if (b[j] >= c[((j + ad) % n)])
            {
                // mp[ad]++;
                fg = false;
                break;
            }
        if (fg)
        {
            // mp[ad]++;
            tp++;
        }
    }
    int ans = 0;
    for (int ad2 = 0; ad2 < n; ad2++)
    {
        bool fg = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= b[((i + ad2) % n)])
            {
                fg = false;
                break;
            }
        }
        if (fg)
        {
            ans++;
        }
    }
    cout << ans * tp * n << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}