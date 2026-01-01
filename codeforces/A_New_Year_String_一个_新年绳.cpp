#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    // int cnt = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    // int mn = 4;
    // bool fg = false;
    // cout << s << endl;
    // cout << endl;
    for (int i = 0; i <= n - 4; i++)
    {
        if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '6')
        {
            // fg = true;
            cout << 0 << endl;
            return;
        }
    }
    // int cnt = 0;
    for (int i = 0; i <= n - 4; i++)
    {
        if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '5')
        // cnt++;
        {
            cout << 1 << endl;
            return;
        }
    }

    // int ans = min(mn, cnt);
    cout << 0 << endl;
    // cout << mn << endl;
    // cout<<cnt<<endl;
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