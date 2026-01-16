#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << 2 << endl;
        return;
    }
    if (n == 3)
    {
        cout << 3 << endl;
        return;
    }
    int mx = 114514;
    if (n % 2 == 0)
    {
        // int cnt = n / 2;

        mx = min(mx, 0);
    }
    if (n % 2 != 0)
    {
        mx = min(mx, 1);
    }
    cout << mx << endl;
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