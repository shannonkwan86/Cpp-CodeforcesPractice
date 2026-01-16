#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        s[i] = i;
    }
    if (l == r)
    {
        s[l] = 1e8 + 1;
    }
    else
    {
        if (l > 1)
            s[r] = s[l - 1] = 1e8 + 1;
        else
            s[r] = 0;
    }
    vector<int> a(n + 1);
    a[1] = s[1];
    for (int i = 2; i <= n; i++)
    {
        a[i] = s[i] ^ s[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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