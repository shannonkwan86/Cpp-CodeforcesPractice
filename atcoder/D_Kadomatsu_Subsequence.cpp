#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mpl;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mpr;
    int ans = 0;
    mpl[a[1]]++;
    mpl[a[2]]++;
    for (int i = 3; i <= n; i++)
    {
        mpl[a[i]]++;
        if (a[i] % 5 == 0)
        {
            ans += mpl[a[i] / 5 * 3] * mpl[a[i] / 5 * 7];
        }
    }
    mpr[a[n]]++;
    mpr[a[n - 1]]++;
    for (int i = n - 2; i >= 1; i--)
    {
        mpr[a[i]]++;
        if (a[i] % 5 == 0)
        {
            ans += mpr[a[i] / 5 * 3] * mpr[a[i] / 5 * 7];
        }
    }
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