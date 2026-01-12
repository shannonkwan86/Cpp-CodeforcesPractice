#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int n, k, d;
int a[114];
int mem[114][114][114];
// int ans = -1;
void init()
{
    for (int i = 0; i < 114; i++)
    {
        for (int j = 0; j < 114; j++)
        {
            for (int k = 0; k < 114; k++)
            {
                mem[i][j][k] = -1;
            }
        }
    }
}
int dfs(int i, int j, int s)
{
    if (j == k)
    {
        if (s == 0)
            return 0;
        else
            return -1e18;
    }
    if (i > n)
        return -1e18;
    if (mem[i][j][s] != -1)
        return mem[i][j][s];
    int res1 = a[i] + dfs(i + 1, j + 1, (s + (a[i]) % d) % d);
    int res2 = dfs(i + 1, j, s);
    mem[i][j][s] = max(res1, res2);
    return mem[i][j][s];
}
void solve()
{
    init();
    cin >> n >> k >> d;
    // vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = dfs(1, 0, 0);
    if (ans >= 0)
        cout << ans << endl;
    else
        cout << -1 << endl;
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