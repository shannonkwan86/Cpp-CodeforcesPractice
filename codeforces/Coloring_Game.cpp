#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
//双指针
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int MAX = a[n];
    for (int m = 3; m <= n; m++)
    {
        int l = 1;
        for (int r = m - 1; r >= 2; r--)
        {
            while (l < r && (a[l] + a[r] <= a[m] || a[l] + a[r] <= MAX - a[m]))
            {
                l++;
            }
            if (l >= r)
                break;
            ans += (r - l);
        }
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