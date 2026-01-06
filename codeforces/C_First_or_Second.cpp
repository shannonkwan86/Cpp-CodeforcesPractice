#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    vector<int> suf(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    pre[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        pre[i] = pre[i - 1] + abs(a[i]);
    }
    suf[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + a[i];
    }
    int ans = pre[n - 1];
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, pre[i - 1] - suf[i + 1]);
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