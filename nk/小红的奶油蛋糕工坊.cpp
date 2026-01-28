#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    int midn = (n + 1) / 2;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l, r;
    l = midn - (midn / 2);
    if (midn % 2 == 1)
        r = midn + (midn / 2);
    else
        r = midn + midn / 2 - 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= l && a[i] <= r)
        {
            a[i] = midn;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
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