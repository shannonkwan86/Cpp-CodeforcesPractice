#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int a[25][25];
map<ll, ll> s[25][25];
int n, m, k;
int ans = 0;
void dfs1(int x, int y, int sum)
{
    if (x > n || y > m)
        return;
    if ((x + y) >= ((n + m) / 2 + 1))
    {
        s[x][y][sum]++;
        return;
    }
    dfs1(x + 1, y, a[x + 1][y] ^ sum);
    dfs1(x, y + 1, sum ^ a[x][y + 1]);
}
void dfs2(int x, int y, int sum)
{
    if (x < 1 || y < 1)
        return;
    if ((x + y) <= ((n + m) / 2 + 1))
    {
        ans += s[x][y][sum ^ k ^ a[x][y]];
        return;
    }
    dfs2(x - 1, y, a[x - 1][y] ^ sum);
    dfs2(x, y - 1, sum ^ a[x][y - 1]);
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs1(1, 1, a[1][1]);
    dfs2(n, m, a[n][m]);
    cout << ans << endl;
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