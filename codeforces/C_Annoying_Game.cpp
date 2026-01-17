#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<int> l(n + 1);
    l[1]=a[1];
    for (int i = 2; i <= n; i++)
    {
        l[i] = max(l[i - 1] + a[i], a[i]);
    }
    vector<int> r(n + 1);
    r[n]=a[n];
    for (int i = n-1; i >= 1; i--)
    {
        r[i] = max(r[i + 1] + a[i], a[i]);
    }
    if (k % 2 == 0)
    {
        int ans = -1e18+7;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, l[i] + r[i] - a[i]);
        }
        cout << ans << endl;
    }
    else
    {
        int ans = -1e18+7;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, l[i] + r[i] - a[i] + b[i]);
        }
        cout << ans << endl;
    }
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