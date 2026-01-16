#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    // cout<<114514<<endl;
    int cnt = 0;
    if (k > n)
    {
        cout << -1 << endl;
        return;
    }
    if (k == n)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= 31; i++)
    {
        int d = 1 << i;
        int l = n / d;
        int h = (n + d - 1) / d;
        if (l == k || h == k)
        {
            cout << i << endl;
            return;
        }
        if (h < k)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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