#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int mx = 2e5 + 5;
vector<int> tr[mx];
int sz[mx];
int fa[mx];

void dfs(int u, int p)
{
    fa[u] = p;
    sz[u] = 1;
    for (int v : tr[u])
    {
        if (v == p)
        {
            continue;
        }
        else
        {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        tr[i].clear();
        sz[i] = 0;
        fa[i] = 0;
    }

    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    dfs(1, 0);

    for (int u = 1; u <= n; u++)
    {
        bool ok = true;
        for (int v : tr[u])
        {
            if (v == fa[u])
            {
                if ((n - sz[u]) % 2 == 0)
                    ok = false;
            }
            else
            {
                if (sz[v] % 2 == 0)
                    ok = false;
            }
        }
        if (ok)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
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