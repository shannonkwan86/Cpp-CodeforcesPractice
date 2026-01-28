#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(m + 1);
    vector<int> c(m + 1);
    vector<int> vis(n + 1, 0);
    // set<int> st;
    vector<int> stk;
    vector<int> he(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i] >> c[i];
        if (a[b[i]] + he[b[i]] + c[i] > h)
        {
            for (int j = 0; j < stk.size(); j++)
            {
                he[stk[j]] = 0;
                vis[stk[j]] = 0;
            }
            stk.clear();
        }
        else
        {
            he[b[i]] += c[i];
            if (!vis[b[i]])
            {
                stk.push_back(b[i]);
                vis[b[i]] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] + he[i] << " ";
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