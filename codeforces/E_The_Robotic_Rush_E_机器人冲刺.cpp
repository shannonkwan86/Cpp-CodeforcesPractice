#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        auto it = lower_bound(b.begin() + 1, b.end(), a[i]);
        r[i] = distance(b.begin(), it);
        l[i] = r[i] - 1;
    }
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> pre(k + 1, 0);
    map<int, int> ft;
    for (int i = 1; i <= k; i++)
    {
        if (s[i] == 'L')
            pre[i] = pre[i - 1] - 1;
        else
            pre[i] = pre[i - 1] + 1;
        if (ft.find(pre[i]) == ft.end())
        {
            ft[pre[i]] = i;
        }
    }

    vector<int> dc(k + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        int ti = k + 1;

        if (r[i] <= m)
        {
            int dr = b[r[i]] - a[i];
            if (ft.count(dr))
            {
                ti = min(ti, ft[dr]);
            }
        }

        if (l[i] >= 1)
        {
            int dl = a[i] - b[l[i]];
            if (ft.count(-dl))
            {
                ti = min(ti, ft[-dl]);
            }
        }

        if (ti <= k)
        {
            dc[ti]++;
        }
    }

    int huo = n;
    for (int i = 1; i <= k; i++)
    {
        huo -= dc[i];
        cout << huo << " ";
    }
    cout << endl;
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