#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mx=-1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx=max(mx,a[i]);
    }
    cout<<mx*n<<endl;
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