#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
        sort(a.begin() + 1, a.end());

    if (2 * m > n)
    {
        cout << -1 << endl;
        return;
    }
    if (m == 0)
    {
        
        int x = -1;
        vector<pair<int, int>> res;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i].first < a[n].first)
            {
                a[n].first -= a[i].first;
                res.push_back({a[i].second, a[n].second});
            }
            else
            {
                x = i;
                break;
            }
        }
        if (x == -1)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            cout << res.size() + x << endl;
            for (auto u : res)
            {
                cout << u.first << " " << u.second << endl;
            }
            for (int i = 1; i < x; i++)
            {
                cout << a[i].second << " " << a[i + 1].second << endl;
            }
            cout << a[x].second << " " << a[n].second << endl;
        }
    }
    if (m > 0)
    {
        cout << n - m << endl;
        for (int i = 1; i <= n - m; i++)
        {
            cout << a[i + m].second << " " << a[i].second << endl;
        }
    }
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