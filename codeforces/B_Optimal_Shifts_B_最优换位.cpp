#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0;
    int cnt = 0;
    int cnt0 = 0;
    bool fg = true;
    for (int i = 1; i <= n; i++)
    {
        if (fg && s[i] == '0')
        {
            cnt0++;
        }
        if (s[i] == '0')
            cnt++;
        if (s[i] == '1')
        {
            fg = false;
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    if (cnt != 0)
    {
        cnt += cnt0;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
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