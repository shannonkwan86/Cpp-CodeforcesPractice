#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int dp[114][114];
int a[114];
int n, k, d;
void solve()
{
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 114; i++)
    {
        for (int j = 0; j < 114; j++)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 1; j--)
        {
            for (int r = 0; r < d; r++)
            {
                if (dp[j - 1][r] != -1)
                {
                    int nr = (r + a[i]) % d;
                    dp[j][nr] = max(dp[j][nr], dp[j - 1][r] + a[i]);
                }
            }
        }
    }
    cout << dp[k][0] << endl;
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